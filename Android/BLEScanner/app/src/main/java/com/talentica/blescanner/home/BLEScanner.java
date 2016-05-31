package com.talentica.blescanner.home;

import android.bluetooth.le.BluetoothLeScanner;

import com.talentica.blescanner.base.Debug;

/**
 * Created by NavalB on 23-05-2016.
 */
public class BLEScanner implements BluetoothScanner {
	private final static String TAG = BLEScanner.class.getSimpleName();
	private BluetoothLeScanner bluetoothLeScanner;
	private final BLEScanCallback scanCallback;
	private final Callback callback;

	public BLEScanner(Callback callback) {
		this.scanCallback = new BLEScanCallback();
		this.callback = callback;
	}

	@Override
	public void scan() {
		Debug.d(TAG, "trying to scan for BLE devices...");
		if (bluetoothLeScanner != null) {
			scanCallback.setCallback(callback);
			bluetoothLeScanner.startScan(scanCallback);
		} else {
			Debug.e(TAG, "bluetoothLeScanner is NULL.");
		}
	}

	@Override
	public void stopScan() {
		Debug.d(TAG, "trying to stop scan for BLE devices...");
		if (bluetoothLeScanner != null) {
			bluetoothLeScanner.stopScan(scanCallback);
		} else {
			Debug.d(TAG, "scanning was not started...");
		}
	}

	@Override
	public void setBLEScanner(BluetoothLeScanner bluetoothLeScanner) {
		this.bluetoothLeScanner = bluetoothLeScanner;
	}
}
