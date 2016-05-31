package com.talentica.blescanner.device;

import android.app.Activity;
import android.app.Dialog;
import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.DialogFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;

import com.talentica.blescanner.R;
import com.talentica.blescanner.base.Debug;

/**
 * A simple {@link DialogFragment} subclass.
 */
public class WriteStringDialog extends DialogFragment implements View.OnClickListener {

	private final static String TAG = WriteStringDialog.class.getSimpleName();

	private EditText editText;
	private String value;
	private String hint;
	private DialogInterface dialogInterface;

	public WriteStringDialog() {}

	public static DialogFragment newInstance(String value, String hint) {
		Bundle bundle = new Bundle();
		bundle.putString("value", value);
		bundle.putString("hint", hint);
		DialogFragment fragment = new WriteStringDialog();
		fragment.setArguments(bundle);
		return fragment;
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
		value = getArguments().getString("value");
		hint = getArguments().getString("hint");
	}

	@Nullable
	@Override
	public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
		return createView(inflater, container);
	}

	private void findViews(View rootView) {
		if (rootView != null) {
			editText = (EditText) rootView.findViewById(R.id.write_string_text);
			Button positiveButton = (Button) rootView.findViewById(R.id.positiveButton);
			Button negativeButton = (Button) rootView.findViewById(R.id.negativeButton);
			positiveButton.setOnClickListener(this);
			negativeButton.setOnClickListener(this);
			editText.setText(value);
			editText.setHint(hint);
			editText.setSelection(value.length());
		} else {
			Debug.e(TAG, "rootView provided is NULL.");
		}
	}


	@Override
	public void onStart() {
		super.onStart();
		Dialog dialog = getDialog();
		if (dialog != null) {
			dialog.getWindow().setLayout(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT);
		}
	}


	private View createView(LayoutInflater inflater, ViewGroup container) {
		return inflater.inflate(R.layout.fragment_write_string_dialog, container, false);
	}

	@Override
	public void onActivityCreated(@Nullable Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);
		findViews(getView());
		getDialog().getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
	}

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
			case R.id.positiveButton:
				String value = editText.getText().toString();
				if (!value.isEmpty()) {
					Debug.d(TAG, "trying to write characteristics " + value);
					dialogInterface.onDialogPositiveButtonClicked(value);
					dismiss();
				} else {
					Debug.e(TAG, "try to avoid empty data");
				}
				break;
			case R.id.negativeButton:
				dismiss();
				break;
		}
	}
}
