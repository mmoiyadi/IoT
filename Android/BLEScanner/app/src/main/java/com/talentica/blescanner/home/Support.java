package com.talentica.blescanner.home;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;

/**
 * A simple {@link Fragment} subclass.
 */
public class Support extends Fragment {
	private static final String TAG = Support.class.getSimpleName();
	private static final String KEY_MESSAGE = "feasibility";
	private int displayMessage;

	public static Fragment newInstance(FeasibilityError feasibilityError) {
		Bundle bundle = new Bundle();
		bundle.putInt(KEY_MESSAGE, feasibilityError.ordinal());
		Fragment fragment = new Support();
		fragment.setArguments(bundle);
		return fragment;
	}

	public Support() {
		// Required empty public constructor
	}

	@Override
	public void onCreate(@Nullable Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		FeasibilityError feasibilityError = FeasibilityError.values()[getArguments().getInt(KEY_MESSAGE)];
		displayMessage = getDisplayMessage(feasibilityError);
		setActionBar();
	}

	private int getDisplayMessage(FeasibilityError feasibilityError) {
		switch (feasibilityError) {
			case IS_DEVICE_BELOW_LOLLIPOP:
				return R.string.error_below_lollipop;
			case DOES_NOT_HAVE_BLUETOOTH:
				return R.string.error_no_bluetooth;
			case DOES_NOT_HAVE_BLE:
				return R.string.error_no_ble;
			case DENIED_LOCATION_PERMISSIONS:
				return R.string.error_denied_location_permission;
			default:
				return R.string.error_unknown;
		}
	}

	private void setActionBar() {
		ActionBar actionBar = ((AppCompatActivity) getActivity()).getSupportActionBar();
		if (actionBar != null) {
			actionBar.setTitle(R.string.title_support);
		}
	}

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
		// Inflate the layout for this fragment
		return inflater.inflate(R.layout.fragment_support, container, false);
	}

	@Override
	public void onActivityCreated(@Nullable Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);
		setMessageView();
	}

	private void setMessageView() {
		if (getView() != null) {
			TextView messageView = (TextView) getView().findViewById(R.id.tv_message);
			messageView.setText(displayMessage);
			Debug.i(TAG, "message: " + getString(displayMessage));
		} else {
			Debug.e(TAG, "No view object. Could not set display message: \n" + getString(displayMessage));
		}
	}
}
