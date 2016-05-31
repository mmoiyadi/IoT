package com.talentica.blescanner.home;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothManager;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Build;

import com.talentica.blescanner.base.Debug;

/**
 * Created by NavalB on 23-05-2016.
 */
 class CheckFeasibility {
	private final String TAG = CheckFeasibility.class.getSimpleName();

	private final Context context;

	public CheckFeasibility(Context context) {this.context = context;}

	public FeasibilityError check() {
		FeasibilityError feasibilityError;
		feasibilityError = checkIsLollipop();
		if (isOkay(feasibilityError)) feasibilityError = checkHasBluetooth();
		if (isOkay(feasibilityError)) feasibilityError = checkHasBLE();
		if (isOkay(feasibilityError)) feasibilityError = checkLocationPermissions();
		Debug.i(TAG, feasibilityError.name());
		return feasibilityError;
	}

	private FeasibilityError checkIsLollipop() {
		Debug.d(TAG, "checking for lollipop and above...");
		if (Build.VERSION.SDK_INT < Build.VERSION_CODES.LOLLIPOP) {
			return FeasibilityError.IS_DEVICE_BELOW_LOLLIPOP;
		} else {
			return FeasibilityError.OKAY;
		}
	}

	private boolean isOkay(FeasibilityError feasibilityError) {
		return feasibilityError == FeasibilityError.OKAY;
	}

	private FeasibilityError checkHasBluetooth() {
		Debug.d(TAG, "checking for bluetooth...");
		BluetoothManager bluetoothManager = (BluetoothManager) context.getSystemService(Context.BLUETOOTH_SERVICE);
		BluetoothAdapter bluetoothAdapter = bluetoothManager.getAdapter();
		if (bluetoothAdapter == null) {
			return FeasibilityError.DOES_NOT_HAVE_BLUETOOTH;
		} else {
			return FeasibilityError.OKAY;
		}
	}

	private FeasibilityError checkHasBLE() {
		Debug.d(TAG, "checking for BLE...");
		PackageManager packageManager = context.getPackageManager();
		if (!packageManager.hasSystemFeature(PackageManager.FEATURE_BLUETOOTH_LE)) {
			return FeasibilityError.DOES_NOT_HAVE_BLE;
		} else {
			return FeasibilityError.OKAY;
		}
	}

	private FeasibilityError checkLocationPermissions() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
			Debug.d(TAG, "checking location permissions...");
			String[] permissions = new String[2];
			if (PackageManager.PERMISSION_DENIED == context.checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION))
				permissions[0] = (Manifest.permission.ACCESS_COARSE_LOCATION);
			if (PackageManager.PERMISSION_DENIED == context.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION))
				permissions[1] = (Manifest.permission.ACCESS_FINE_LOCATION);
			if (permissions[0] != null || permissions[1] != null) {
				Debug.e(TAG, "permissions are NOT granted.");
				Debug.d(TAG, "requesting location permissions...");
				return FeasibilityError.DOES_NOT_HAVE_LOCATION_PERMISSIONS;
			} else {
				return FeasibilityError.OKAY;
			}
		}
		return FeasibilityError.OKAY;
	}
}
