package com.talentica.blescanner.home;

import android.bluetooth.le.BluetoothLeScanner;

import java.util.List;

/**
 * Created by NavalB on 23-05-2016.
 */
 public interface BluetoothScanner {
	void scan();

	void stopScan();

	void setBLEScanner(BluetoothLeScanner bluetoothLeScanner);

	interface Callback {
		void scanResults(List<BLEScanResult> results);

		void scanResult(BLEScanResult result);
	}
}
