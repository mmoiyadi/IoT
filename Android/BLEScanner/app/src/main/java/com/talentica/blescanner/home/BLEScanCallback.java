package com.talentica.blescanner.home;

import android.bluetooth.le.ScanCallback;
import android.bluetooth.le.ScanResult;

import com.talentica.blescanner.base.Debug;

import java.util.List;

/**
 * Created by NavalB on 23-05-2016.
 */
 class BLEScanCallback extends ScanCallback {
	private static final String TAG = BLEScanCallback.class.getSimpleName();

	private BluetoothScanner.Callback callback;

	@Override
	public void onScanResult(int callbackType, ScanResult result) {
		super.onScanResult(callbackType, result);
		Debug.i(TAG, "onScanResult");
		if (callback != null) {
			Debug.d(TAG, "delegating result..." + callback.toString());
			if (result != null) {
				callback.scanResult(new BLEScanResult(result));
			} else {
				Debug.e(TAG, "scan result received is NULL");
			}
		} else {
			Debug.e(TAG, "callback is NULL");
		}
	}

	@Override
	public void onBatchScanResults(List<ScanResult> results) {
		super.onBatchScanResults(results);
		Debug.i(TAG, "onBatchScanResults");
	}

	@Override
	public void onScanFailed(int errorCode) {
		super.onScanFailed(errorCode);
		Debug.i(TAG, "onScanFailed");
	}

	public void setCallback(BluetoothScanner.Callback callback) {
		this.callback = callback;
	}
}
