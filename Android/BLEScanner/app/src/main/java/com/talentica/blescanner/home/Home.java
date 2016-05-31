package com.talentica.blescanner.home;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;

public class Home extends AppCompatActivity {
	private static final String TAG = Home.class.getSimpleName();
	private static final int REQUEST_LOCATION_PERMISSION = 904;

	private CheckFeasibility checkFeasibility;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_home);
		checkFeasibility = new CheckFeasibility(getApplicationContext());
		performAppropriateFunction(checkFeasibility.check());
	}

	private void performAppropriateFunction(FeasibilityError check) {
		switch (check) {
			case DOES_NOT_HAVE_LOCATION_PERMISSIONS:
				askLocationPermissions();
				break;
			default:
				attachRespectiveFragment(check);
		}
	}

	private void askLocationPermissions() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
			Debug.d(TAG, "asking location permissions...");
			String[] permissions = new String[2];
			if (PackageManager.PERMISSION_DENIED == checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION))
				permissions[0] = (Manifest.permission.ACCESS_COARSE_LOCATION);
			if (PackageManager.PERMISSION_DENIED == checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION))
				permissions[1] = (Manifest.permission.ACCESS_FINE_LOCATION);
			if (permissions[0] != null || permissions[1] != null) {
				Debug.e(TAG, "permissions are NOT granted.");
				Debug.d(TAG, "launching intent for location permissions...");
				requestPermissions(permissions, REQUEST_LOCATION_PERMISSION);
			} else {
				Debug.i(TAG, "permissions are granted.");
			}
		}
	}

	private void attachRespectiveFragment(FeasibilityError feasibility) {
		Debug.d(TAG, "attaching respective fragment...");
		Fragment fragment = getFeasibleFragment(feasibility);
		replaceFragment(fragment);
	}

	private Fragment getFeasibleFragment(FeasibilityError feasibility) {
		Debug.d(TAG, "getting feasible fragment...");
		Fragment fragment;
		switch (feasibility) {
			case OKAY:
				fragment = BLEDeviceListings.newInstance();
				break;
			default:
				fragment = Support.newInstance(feasibility);
		}
		return fragment;
	}

	private void replaceFragment(Fragment fragment) {
		Debug.d(TAG, "replacing fragment...");
		getSupportFragmentManager().beginTransaction().replace(R.id.container, fragment, getString(R.string.tag_home)).commitAllowingStateLoss();
	}

	@Override
	public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
		Debug.i(TAG, "onRequestPermissionsResult");
		super.onRequestPermissionsResult(requestCode, permissions, grantResults);
		switch (requestCode) {
			case REQUEST_LOCATION_PERMISSION:
				for (int result : grantResults) {
					if (result != PackageManager.PERMISSION_GRANTED) {
						Debug.i(TAG, "PERMISSION_NOT_GRANTED");
						attachRespectiveFragment(FeasibilityError.DENIED_LOCATION_PERMISSIONS);
						break;
					}
				}
				performAppropriateFunction(checkFeasibility.check());
				break;
			default:
		}
	}
}
