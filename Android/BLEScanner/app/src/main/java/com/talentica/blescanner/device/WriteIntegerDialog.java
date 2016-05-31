package com.talentica.blescanner.device;

import android.app.Activity;
import android.app.Dialog;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCharacteristic;
import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.PopupWindow;
import android.widget.Spinner;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;

import java.util.ArrayList;

/**
 * A simple {@link Fragment} subclass.
 */
public class WriteIntegerDialog extends DialogFragment implements View.OnClickListener{

	private static final String TAG = WriteIntegerDialog.class.getSimpleName();


	private Spinner spinner;
	private  WriteIntegerAdapter spinnerAdapter;
	private  int formatType;
	private DialogInterface dialogInterface;

	public WriteIntegerDialog(){

	}

	@Override
	public void onAttach(Context context) {
		super.onAttach(context);
		Activity activity = getActivity();
		if (activity instanceof DialogInterface) {
			dialogInterface = (DialogInterface) activity;
		} else {
			throw new UnsupportedOperationException("kuch kar lo.. khali hi baithe ho");
		}
	}

	@Override
	public void onCreate(@Nullable Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		ArrayList<Integer> array = getArguments().getIntegerArrayList("array");
		formatType = getArguments().getInt("formatType");
		spinnerAdapter = new WriteIntegerAdapter(array, getContext());
	}

	@Nullable
	@Override
	public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		return createView(inflater,container);
	}
	private View createView(LayoutInflater inflater, ViewGroup container) {
		return inflater.inflate(R.layout.fragment_write_integer_dialog, container, false);
	}

	@Override
	public void onStart() {
		super.onStart();
		Dialog dialog = getDialog();
		if (dialog != null) {
			dialog.getWindow().setLayout(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
		}
	}

	@Override
	public void onActivityCreated(@Nullable Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);
		findViews(getView());
		getDialog().getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
	}

	private void findViews(View rootView){
		spinner = (Spinner) rootView.findViewById(R.id.write_integer_spinner);
		Button positiveButton = (Button) rootView.findViewById(R.id.positiveButton);
		Button negativeButton = (Button) rootView.findViewById(R.id.negativeButton);
		spinner.setAdapter(spinnerAdapter);
		positiveButton.setOnClickListener(this);
		negativeButton.setOnClickListener(this);
	}


	public static DialogFragment newInstance(ArrayList<Integer> array,int formatType) {
		DialogFragment dialogFragment = new WriteIntegerDialog();
		Bundle bundle = new Bundle();
		bundle.putIntegerArrayList("array",array);
		bundle.putInt("formatType",formatType);
		dialogFragment.setArguments(bundle);
		return dialogFragment;
	}


	@Override
	public void onClick(View v) {
		switch (v.getId()){
			case R.id.positiveButton:
				int value =spinnerAdapter.getItem(spinner.getSelectedItemPosition());
				Debug.i(TAG,"Writing integer characteristic "+value);
				dialogInterface.onDialogPositiveButtonClicked(value,formatType);
				dismiss();
				break;
			case R.id.negativeButton:
				dismiss();
		}
	}
}
