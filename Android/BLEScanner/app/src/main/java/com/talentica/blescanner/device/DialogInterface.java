package com.talentica.blescanner.device;

/**
 * Created by NavalB on 27-05-2016.
 */
public interface DialogInterface {
	void onDialogPositiveButtonClicked(byte[] value);
	void onDialogPositiveButtonClicked(String value);
	void onDialogPositiveButtonClicked(int value,int formatType);
	void onDialogPositiveButtonClicked(float value,int formatType);
}
