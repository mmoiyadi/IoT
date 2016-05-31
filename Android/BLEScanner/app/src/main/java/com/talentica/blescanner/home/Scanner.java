package com.talentica.blescanner.home;

/**
 * Created by NavalB on 24-05-2016.
 */
public interface Scanner {
	boolean isScanning();
	void start();
	void stop();
	void performOnActivityResult(int requestCode, int resultCode);
}
