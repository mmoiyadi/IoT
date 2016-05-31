package com.talentica.blescanner.home;

import android.content.Context;
import android.content.Intent;

import com.talentica.blescanner.home.BluetoothScanner;

/**
 * Created by NavalB on 24-05-2016.
 */
public interface ScanningView {
	void startActivityForResult(Intent intent,int requestCode);
	Context getContext();
	BluetoothScanner.Callback getScannerCallback();
	void startScan();
	void stopScan();

}
