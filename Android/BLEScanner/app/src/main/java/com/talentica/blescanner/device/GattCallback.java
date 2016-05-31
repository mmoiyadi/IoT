package com.talentica.blescanner.device;

import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothProfile;

import com.talentica.blescanner.base.Debug;
import com.talentica.blescanner.base.Utils;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by NavalB on 24-05-2016.
 */
public class GattCallback extends BluetoothGattCallback {
	private static final String TAG = GattCallback.class.getSimpleName();

	private final PostOnUIThread postOnUIThread;

	public GattCallback(GattResult gattResult) {
		postOnUIThread = new PostOnUIThread(gattResult);
	}

	@Override
	public void onCharacteristicChanged(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic) {
		super.onCharacteristicChanged(gatt, characteristic);
		Debug.i(TAG, "onCharacteristicChanged ");
	}

	@Override
	public void onCharacteristicRead(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status) {
		super.onCharacteristicRead(gatt, characteristic, status);
		Debug.i(TAG, "onCharacteristicRead " + "status " + status);
		printStatus(status);

//		Debug.i(TAG, new String(characteristic.getValue(), StandardCharsets.UTF_8));
//		Debug.i(TAG,Arrays.toString(characteristic.getCharacteristicValue()));
//		Debug.i(TAG,Utils.bytesToHex(characteristic.getCharacteristicValue()));
		Debug.i(TAG,characteristic.getStringValue(0));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_UINT8,0)));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_UINT16,0)));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_UINT32,0)));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_SINT8,0)));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_SINT16,0)));
		Debug.i(TAG,String.valueOf(characteristic.getIntValue(BluetoothGattCharacteristic.FORMAT_SINT32,0)));
		Debug.i(TAG,String.valueOf(characteristic.getFloatValue(BluetoothGattCharacteristic.FORMAT_SFLOAT,0)));
		Debug.i(TAG,String.valueOf(characteristic.getFloatValue(BluetoothGattCharacteristic.FORMAT_FLOAT,0)));
		if(status == BluetoothGatt.GATT_SUCCESS){
			postOnUIThread.onSuccessfulCharacteristicRead();
		}
	}

	@Override
	public void onCharacteristicWrite(BluetoothGatt gatt, BluetoothGattCharacteristic characteristic, int status) {
		super.onCharacteristicWrite(gatt, characteristic, status);
		Debug.i(TAG, "onCharacteristicWrite " + "status " + status);
		printStatus(status);
		if(status == BluetoothGatt.GATT_SUCCESS){
			postOnUIThread.onSuccessfulCharacteristicWrite();
		}else {
			postOnUIThread.onFailureCharacteristicWrite();
		}
	}

	@Override
	public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {
		super.onConnectionStateChange(gatt, status, newState);
		Debug.i(TAG, "onConnectionStateChange " + "status " + status + " newState " + newState);
		printStatus(status);
		delegateConnectionState(newState);
	}

	private void printStatus(int status) {
		switch (status) {
			case BluetoothGatt.GATT_SUCCESS:
				Debug.i(TAG, "GATT operation completed successfully");
				break;
			case BluetoothGatt.GATT_CONNECTION_CONGESTED:
				Debug.e(TAG, "A remote device connection is congested.");
				break;
			case BluetoothGatt.GATT_FAILURE:
				Debug.e(TAG, "A GATT operation failed, generic error statement.");
				break;
			case BluetoothGatt.GATT_INSUFFICIENT_AUTHENTICATION:
				Debug.e(TAG, "Insufficient authentication for a given operation");
				break;
			case BluetoothGatt.GATT_INSUFFICIENT_ENCRYPTION:
				Debug.e(TAG, "Insufficient encryption for a given operation");
				break;
			case BluetoothGatt.GATT_INVALID_ATTRIBUTE_LENGTH:
				Debug.e(TAG, "A write operation exceeds the maximum length of the attribute ");
				break;
			case BluetoothGatt.GATT_INVALID_OFFSET:
				Debug.e(TAG, "A read or write operation was requested with an invalid offset");
				break;
			case BluetoothGatt.GATT_READ_NOT_PERMITTED:
				Debug.e(TAG, "GATT read operation is not permitted");
				break;
			case BluetoothGatt.GATT_REQUEST_NOT_SUPPORTED:
				Debug.e(TAG, "The given request is not supported");
				break;
			case BluetoothGatt.GATT_WRITE_NOT_PERMITTED:
				Debug.e(TAG, "GATT write operation is not permitted");
				break;
			default:
				Debug.e(TAG, "not specified.");
		}
	}

	private void delegateConnectionState(int newState) {
		switch (newState) {
			case BluetoothProfile.STATE_CONNECTED:
				postOnUIThread.onConnected();
				break;
			case BluetoothProfile.STATE_DISCONNECTED:
				postOnUIThread.onDisconnected();
				break;
		}
	}

	@Override
	public void onDescriptorRead(BluetoothGatt gatt, BluetoothGattDescriptor descriptor, int status) {
		super.onDescriptorRead(gatt, descriptor, status);
		Debug.i(TAG, "onDescriptorRead " + "status " + status);
		printStatus(status);
	}

	@Override
	public void onDescriptorWrite(BluetoothGatt gatt, BluetoothGattDescriptor descriptor, int status) {
		super.onDescriptorWrite(gatt, descriptor, status);
		Debug.i(TAG, "onDescriptorWrite " + "status " + status);
		printStatus(status);
	}

	@Override
	public void onMtuChanged(BluetoothGatt gatt, int mtu, int status) {
		super.onMtuChanged(gatt, mtu, status);
		Debug.i(TAG, "onMtuChanged " + "status " + status);
		printStatus(status);
	}

	@Override
	public void onReadRemoteRssi(BluetoothGatt gatt, int rssi, int status) {
		super.onReadRemoteRssi(gatt, rssi, status);
		Debug.i(TAG, "onReadRemoteRssi " + "status " + status);
		printStatus(status);
	}

	@Override
	public void onReliableWriteCompleted(BluetoothGatt gatt, int status) {
		super.onReliableWriteCompleted(gatt, status);
		Debug.i(TAG, "onReliableWriteCompleted " + "status " + status);
		printStatus(status);
	}

	@Override
	public void onServicesDiscovered(BluetoothGatt gatt, int status) {
		super.onServicesDiscovered(gatt, status);
		Debug.i(TAG, "onServicesDiscovered " + "status " + status);
		printStatus(status);
		List<BluetoothGattService> serviceList = gatt.getServices();
		List<BLEGattService> bleGattServiceList = new ArrayList<>();
		Debug.i(TAG, "---------------");
		for (BluetoothGattService bluetoothGattService : serviceList) {
			BLEGattService bleGattService = new BLEGattService(bluetoothGattService);
			bleGattServiceList.add(bleGattService);
			Debug.i(TAG, bleGattService.toString());
			Debug.i(TAG, "---------------");
		}
		postOnUIThread.loadServices(bleGattServiceList);
	}
}
