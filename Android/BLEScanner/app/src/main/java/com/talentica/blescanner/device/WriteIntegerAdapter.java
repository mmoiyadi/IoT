package com.talentica.blescanner.device;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.SpinnerAdapter;
import android.widget.TextView;

import com.talentica.blescanner.R;

import java.util.ArrayList;

/**
 * Created by NavalB on 27-05-2016.
 */
public class WriteIntegerAdapter extends BaseAdapter implements SpinnerAdapter {

	private final ArrayList<Integer> array;
	private final Context context;


	WriteIntegerAdapter(ArrayList<Integer> array, Context context){
		this.array = array;
		this.context = context;
	}
	@Override
	public int getCount() {
		return array.size();
	}

	@Override
	public Integer getItem(int position) {
		return array.get(position);
	}

	@Override
	public long getItemId(int position) {
		return position;
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		SpinnerViewModel spinnerViewModel;
		if(convertView == null){
			convertView = LayoutInflater.from(context).inflate(R.layout.item_spinner_write_dialog,parent,false);
			 spinnerViewModel = new SpinnerViewModel(convertView);
			convertView.setTag(spinnerViewModel);
		}
		spinnerViewModel = (SpinnerViewModel) convertView.getTag();
		spinnerViewModel.changeData(getItem(position));
		return convertView;
	}


	private static class SpinnerViewModel{
		private TextView value;
		private final View convertView;

		SpinnerViewModel(View convertView){
			this.convertView = convertView;
			findViews();
		}

		private void findViews() {
			value = (TextView) convertView.findViewById(R.id.item_spinner_value);
		}

		public void changeData(Object object){
			value.setText(String.valueOf(object));
		}
	}
}
