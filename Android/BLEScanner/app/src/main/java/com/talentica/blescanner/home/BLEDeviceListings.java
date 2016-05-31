package com.talentica.blescanner.home;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;
import com.talentica.blescanner.device.PostOnUIThread;

import java.util.List;

/**
 * A simple {@link Fragment} subclass.
 */
public class BLEDeviceListings extends Fragment implements BluetoothScanner.Callback, ScanningView {
	private static final String TAG = BLEDeviceListings.class.getSimpleName();

	private boolean isScanning = false;
	private BLEDeviceListAdapter bleDeviceListAdapter;
	private Scanner scanner;

	private ProgressBar progressBar;
	private TextView messageView;
	private Handler uiHandler;

	public static Fragment newInstance() {
		return new BLEDeviceListings();
	}

	public BLEDeviceListings() {
		// Required empty public constructor
	}

	@Override
	public void scanResults(List<BLEScanResult> results) {
//		TODO haven;t check out
	}

	@Override
	public void scanResult(BLEScanResult result) {
		Debug.i(TAG, "scan result received.");
		Debug.i(TAG, result.toString());
		bleDeviceListAdapter.addDevice(result);
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		Debug.i(TAG, "onActivityResult requestCode " + requestCode + " resultCode " + resultCode);
		scanner.performOnActivityResult(requestCode, resultCode);
	}

	@Override
	public void onCreate(@Nullable Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setActionBar();
		setHasOptionsMenu(true);
		bleDeviceListAdapter = new BLEDeviceListAdapter(this.getContext());
		scanner = new Scan(this);
		uiHandler = new Handler(Looper.getMainLooper());
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		return inflater.inflate(R.layout.fragment_bledevices, container, false);
	}

	@Override
	public void onActivityCreated(@Nullable Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);
		initializeViews();
	}

	private void initializeViews() {
		Debug.d(TAG, "initializing views...");
		if (getView() != null) {
			progressBar = (ProgressBar) getView().findViewById(R.id.progress_bar_ble_scan);
			messageView = (TextView) getView().findViewById(R.id.tv_message);
			ListView deviceList = (ListView) getView().findViewById(R.id.list_ble_devices);
			deviceList.setAdapter(bleDeviceListAdapter);
		} else {
			Debug.e(TAG, "No view object. Could not assign views");
		}
	}

	@Override
	public void onResume() {
		super.onResume();
		scanner.start();
	}

	@Override
	public void onPause() {
		super.onPause();
		scanner.stop();
	}

	@Override
	public void onCreateOptionsMenu(Menu menu, MenuInflater inflater) {
		super.onCreateOptionsMenu(menu, inflater);
		inflater.inflate(R.menu.menu_ble_devices, menu);
	}

	@Override
	public void onPrepareOptionsMenu(Menu menu) {
		super.onPrepareOptionsMenu(menu);
		menu.findItem(R.id.menu_stop_scan).setVisible(isScanning);
		menu.findItem(R.id.menu_scan).setVisible(!isScanning);
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.menu_scan:
				Debug.d(TAG, "scan menu clicked...");
				scanner.start();
				return true;
			case R.id.menu_stop_scan:
				Debug.d(TAG, "stopScan menu clicked...");
				scanner.stop();
				return true;
			default:
				Debug.e(TAG, " menu clicked...");
		}
		return super.onOptionsItemSelected(item);
	}

	private void setActionBar() {
		ActionBar actionBar = ((AppCompatActivity) getActivity()).getSupportActionBar();
		if (actionBar != null) {
			actionBar.setTitle(R.string.title_ble_devices);
		}
	}

	@Override
	public BluetoothScanner.Callback getScannerCallback() {
		return this;
	}

	@Override
	public void startScan() {
		Debug.d(TAG,"UI changes while initializing scan...");
		refreshMenu();
		bleDeviceListAdapter.clear();
		setScanning(true);
		updateUI();
		uiHandler.postDelayed(autoSopScanning,5000);
	}

	private Runnable autoSopScanning =new Runnable() {
		@Override
		public void run() {
			if(scanner!=null && scanner.isScanning()) {
				scanner.stop();
			}
		}
	};

	@Override
	public void stopScan() {
			Debug.d(TAG, "UI changes while stopping scan...");
			refreshMenu();
			setScanning(false);
			updateUI();
	}

	private void refreshMenu() {
		getActivity().invalidateOptionsMenu();
	}

	private void setScanning(boolean scanning) {
		isScanning = scanning;
	}

	private void updateUI() {
		Debug.d(TAG, "updating UI...");
		updateProgressBar();
		updateMessageView();
	}

	private void updateProgressBar() {
		Debug.d(TAG, "updating progress bar...");
		progressBar.setVisibility(isScanning ? View.VISIBLE : View.INVISIBLE);
	}

	private void updateMessageView() {
		Debug.d(TAG, "updating message view...");
		messageView.setText(isScanning ? getString(R.string.ble_devices_scanning) : getString(R.string.ble_devices_scanning_stopped));
	}
}
