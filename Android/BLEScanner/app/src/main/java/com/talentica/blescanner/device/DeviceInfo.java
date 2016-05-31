package com.talentica.blescanner.device;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattService;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ExpandableListView;
import android.widget.ProgressBar;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;
import com.talentica.blescanner.base.Utils;
import com.talentica.blescanner.home.BLEScanResult;

import java.util.List;

public class DeviceInfo extends AppCompatActivity implements GattResult, DeviceInfoExpandableAdapter.Contract, DialogInterface {
	private static final String EXTRA_SCAN_RESULT = "scan_result";
	private static final String TAG = DeviceInfo.class.getSimpleName();

	private BLEScanResult bleScanResult;
	private GattConnection gattConnection = GattConnection.DISCONNECTED;
	private BluetoothGatt bluetoothGatt;
	private GattCallback gattCallback;
	private ExpandableListView deviceInfoServiceList;
	private ProgressBar progressBar;
	//	PopupWindow popupWindow;
	private BLEGattCharacteristic currentBleGattCharacteristic;

	private DeviceInfoExpandableAdapter deviceInfoServiceListAdapter;

	public static void launch(Context context, BLEScanResult bleScanResult) {
		Intent intent = new Intent(context, DeviceInfo.class);
		intent.putExtra(EXTRA_SCAN_RESULT, bleScanResult);
		context.startActivity(intent);
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_device);
		getScanResult();
		checkScanResult();
		proceed();
	}

	private void getScanResult() {
		Intent intent = getIntent();
		if (intent != null) {
			bleScanResult = intent.getParcelableExtra(EXTRA_SCAN_RESULT);
		} else {
			Debug.e(TAG, "intent received is NULL.");
		}
	}

	private void checkScanResult() {
		if (bleScanResult == null) {
			Debug.e(TAG, "scan result received is NULL. Cannot perform further.");
			finish();
		}
	}

	private void proceed() {
		setActionBar();
		deviceInfoServiceList = (ExpandableListView) findViewById(R.id.device_info_service_list);
		gattCallback = new GattCallback(this);
		deviceInfoServiceListAdapter = new DeviceInfoExpandableAdapter(this);
		if (deviceInfoServiceList != null) {
			deviceInfoServiceList.setAdapter(deviceInfoServiceListAdapter);
		}
		progressBar = (ProgressBar) findViewById(R.id.device_info_progress_bar);
	}

	private void setActionBar() {
		ActionBar actionBar = getSupportActionBar();
		if (actionBar != null) {
			actionBar.setTitle(bleScanResult.getDeviceName());
			actionBar.setDisplayHomeAsUpEnabled(true);
		} else {
			Debug.e(TAG, "action bar is NULL");
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.menu_device_info, menu);
		return super.onCreateOptionsMenu(menu);
	}

	/**
	 * You must return true for the menu to be displayed;
	 * if you return false it will not be shown.
	 */
	@Override
	public boolean onPrepareOptionsMenu(Menu menu) {
		switch (gattConnection) {
			case CONNECTED:
				menu.findItem(R.id.menu_disconnect_gatt).setVisible(true);
				menu.findItem(R.id.menu_connect_gatt).setVisible(false);
				menu.findItem(R.id.menu_disconnecting_gatt).setVisible(false);
				menu.findItem(R.id.menu_connecting_gatt).setVisible(false);
				break;
			case DISCONNECTED:
				menu.findItem(R.id.menu_disconnect_gatt).setVisible(false);
				menu.findItem(R.id.menu_connect_gatt).setVisible(true);
				menu.findItem(R.id.menu_disconnecting_gatt).setVisible(false);
				menu.findItem(R.id.menu_connecting_gatt).setVisible(false);
				break;
			case CONNECTING:
				menu.findItem(R.id.menu_disconnect_gatt).setVisible(false);
				menu.findItem(R.id.menu_connect_gatt).setVisible(false);
				menu.findItem(R.id.menu_disconnecting_gatt).setVisible(false);
				menu.findItem(R.id.menu_connecting_gatt).setVisible(true);
				break;
			case DISCONNECTING:
				menu.findItem(R.id.menu_disconnect_gatt).setVisible(false);
				menu.findItem(R.id.menu_connect_gatt).setVisible(false);
				menu.findItem(R.id.menu_disconnecting_gatt).setVisible(true);
				menu.findItem(R.id.menu_connecting_gatt).setVisible(false);
				break;
			default:
				Debug.e(TAG, "menu item not handled");
		}
		return true;
	}

	/**
	 * Return false to allow normal menu processing to
	 * proceed, true to consume it here.
	 */
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.menu_connect_gatt:
				connectGatt();
				break;
			case R.id.menu_disconnect_gatt:
				disConnectGatt();
				break;
			case android.R.id.home:
				finish();
				break;
		}
		return super.onOptionsItemSelected(item);
	}

	private void setGattConnection(GattConnection gattConnection) {
		this.gattConnection = gattConnection;
	}

	private void connectGatt() {
		Debug.d(TAG, "trying to connect Gatt service...");
		connecting();
		if (bluetoothGatt == null) {
			bluetoothGatt = makeGattConnect();
		} else {
			bluetoothGatt.connect();
		}
	}

	private BluetoothGatt makeGattConnect() {
		BluetoothGatt bluetoothGatt;
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
			bluetoothGatt = bleScanResult.getBluetoothDevice().connectGatt(getApplicationContext(), false, gattCallback, BluetoothDevice.TRANSPORT_LE);
		} else {
			bluetoothGatt = bleScanResult.getBluetoothDevice().connectGatt(getApplicationContext(), false, gattCallback);
		}
		return bluetoothGatt;
	}

	private void fetchGattServices() {
		if (bluetoothGatt != null) {
			listGattServices();
		} else {
			Debug.e(TAG, "bluetoothGatt is NULL.");
		}
	}

	private void listGattServices() {
		List<BluetoothGattService> serviceList = bluetoothGatt.getServices();
		if (serviceList.isEmpty()) {
			Debug.e(TAG, "There are no Gatt services.");
			boolean flag = bluetoothGatt.discoverServices();
			Debug.i(TAG, "discovering services started " + flag);
		} else {
			for (BluetoothGattService bluetoothGattService : serviceList) {
				Debug.i(TAG, String.valueOf(bluetoothGattService.getUuid()));
			}
		}
	}

	private void disConnectGatt() {
		if (bluetoothGatt != null) {
			Debug.d(TAG, "disconnecting Gatt service...");
			disconnecting();
			bluetoothGatt.disconnect();
		} else {
			Debug.e(TAG, "bluetoothGatt is NULL. Need to connect first.");
		}
	}

	private void refreshMenu() {
		invalidateOptionsMenu();
	}

	@Override
	public void loadServices(List<BLEGattService> gattServiceList) {
		deviceInfoServiceListAdapter.setGattServices(gattServiceList);
	}

	@Override
	public void onConnected() {
		Debug.i(TAG, "Gatt onConnected");
		setGattConnection(GattConnection.CONNECTED);
		hideProgressBar();
		refreshMenu();
		fetchGattServices();
	}

	@Override
	public void onDisconnected() {
		Debug.i(TAG, "Gatt onDisconnected");
		setGattConnection(GattConnection.DISCONNECTED);
		bluetoothGatt = null;
		hideProgressBar();
		refreshMenu();
	}

	@Override
	public void onSuccessfulCharacteristicRead() {
		deviceInfoServiceListAdapter.notifyDataSetChanged();
	}

	@Override
	public void onSuccessfulCharacteristicWrite() {
		currentBleGattCharacteristic = null;
	}

	@Override
	public void onFailureCharacteristicWrite() {
		currentBleGattCharacteristic = null;
	}

	private void showProgressBar() {
		progressBar.setVisibility(View.VISIBLE);
	}

	private void hideProgressBar() {
		progressBar.setVisibility(View.INVISIBLE);
	}

	private void connecting() {
		Debug.i(TAG, "Gatt connecting");
		setGattConnection(GattConnection.CONNECTING);
		showProgressBar();
		refreshMenu();
	}

	private void disconnecting() {
		Debug.i(TAG, "Gatt disconnecting");
		setGattConnection(GattConnection.DISCONNECTING);
		showProgressBar();
		refreshMenu();
	}

	@Override
	public Context getContext() {
		return getApplicationContext();
	}

	@Override
	public void expand(int groupId) {
		if (deviceInfoServiceList != null) {
			deviceInfoServiceList.expandGroup(groupId);
		}
	}

	@Override
	public void collapse(int groupId) {
		if (deviceInfoServiceList != null) {
			deviceInfoServiceList.collapseGroup(groupId);
		}
	}

	@Override
	public void readCharacteristic(BLEGattCharacteristic bleGattCharacteristic) {
		if (bluetoothGatt != null) {
			bluetoothGatt.readCharacteristic(bleGattCharacteristic.getBluetoothGattCharacteristic());
		} else {
			Debug.e(TAG, "GATT is not connected. Connect again.");
		}
	}

	@Override
	public void writeCharacteristic(BLEGattCharacteristic bleGattCharacteristic) {
		if (bluetoothGatt != null) {
			currentBleGattCharacteristic = bleGattCharacteristic;
			DialogFragment dialogFragment = CharacteristicWriteDialog.create(currentBleGattCharacteristic);
			if (dialogFragment != null) {
				dialogFragment.show(getSupportFragmentManager(), "writeDialog");
			} else {
				Debug.e(TAG, "dialog is NOT required.");
			}
		} else {
			Debug.e(TAG, "bluetoothGatt is NULL. Reconnect.");
		}
	}

	@Override
	protected void onResume() {
		super.onResume();
		connectGatt();
	}

	@Override
	protected void onPause() {
		super.onPause();
		disConnectGatt();
	}

	@Override
	public void onDialogPositiveButtonClicked(byte[] value) {
	}

	@Override
	public void onDialogPositiveButtonClicked(String value) {
		if (bluetoothGatt != null) {
			if(currentBleGattCharacteristic!=null) {
				BluetoothGattCharacteristic bluetoothGattCharacteristic =currentBleGattCharacteristic.getBluetoothGattCharacteristic();
				bluetoothGattCharacteristic.setValue(value);
				bluetoothGatt.writeCharacteristic(bluetoothGattCharacteristic);
			}else{
				Debug.e(TAG,"There is no current characteristic");
			}
		} else {
			Debug.e(TAG, "GATT is not connected. Connect again.");
		}
	}

	@Override
	public void onDialogPositiveButtonClicked(int value,int formatType) {
		if (bluetoothGatt != null) {
			if(currentBleGattCharacteristic!=null) {
				BluetoothGattCharacteristic bluetoothGattCharacteristic =currentBleGattCharacteristic.getBluetoothGattCharacteristic();
				bluetoothGattCharacteristic.setValue(value,formatType,0);
				bluetoothGatt.writeCharacteristic(bluetoothGattCharacteristic);
			}else{
				Debug.e(TAG,"There is no current characteristic");
			}
		} else {
			Debug.e(TAG, "GATT is not connected. Connect again.");
		}
	}

	@Override
	public void onDialogPositiveButtonClicked(float value, int formatType) {
	}

	@Override
	public void onBackPressed() {
		/*if (popupWindow != null && popupWindow.isShowing()) {
			popupWindow.dismiss();
			return;
		}*/
		super.onBackPressed();
	}
}
