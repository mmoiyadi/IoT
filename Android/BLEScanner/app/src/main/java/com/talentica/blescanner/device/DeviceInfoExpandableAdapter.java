package com.talentica.blescanner.device;

		import android.content.Context;
		import android.view.LayoutInflater;
		import android.view.View;
		import android.view.ViewGroup;
		import android.widget.BaseExpandableListAdapter;
		import android.widget.Button;
		import android.widget.ImageButton;
		import android.widget.LinearLayout;
		import android.widget.TextView;

		import com.talentica.blescanner.R;

		import java.util.List;

/**
 * Created by NavalB on 24-05-2016.
 */
public class DeviceInfoExpandableAdapter extends BaseExpandableListAdapter {
	private List<BLEGattService> bleGattServiceList;
	private final Contract contract;

	interface Contract {
		Context getContext();

		void expand(int groupId);

		void collapse(int groupId);

		void readCharacteristic(BLEGattCharacteristic bleGattCharacteristic);

		void writeCharacteristic(BLEGattCharacteristic bleGattCharacteristic);
	}

	DeviceInfoExpandableAdapter(Contract contract) {
		this.contract = contract;
	}

	public void setGattServices(List<BLEGattService> bleGattServiceList) {
		this.bleGattServiceList = bleGattServiceList;
		notifyDataSetChanged();
	}

	@Override
	public int getGroupCount() {
		if (bleGattServiceList != null) {
			return bleGattServiceList.size();
		}
		return 0;
	}

	@Override
	public int getChildrenCount(int groupPosition) {
		return getGroup(groupPosition).getBleGattCharacteristics().size();
	}

	@Override
	public BLEGattService getGroup(int groupPosition) {
		return bleGattServiceList.get(groupPosition);
	}

	@Override
	public BLEGattCharacteristic getChild(int groupPosition, int childPosition) {
		return bleGattServiceList.get(groupPosition).getBleGattCharacteristics().get(childPosition);
	}

	@Override
	public long getGroupId(int groupPosition) {
		return groupPosition;
	}

	@Override
	public long getChildId(int groupPosition, int childPosition) {
		return 0;
	}

	@Override
	public boolean hasStableIds() {
		return false;
	}

	@Override
	public View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
		GroupViewHolder groupViewHolder;
		if (convertView == null) {
			convertView = LayoutInflater.from(contract.getContext()).inflate(R.layout.item_device_info_service, parent, false);
			groupViewHolder = new GroupViewHolder(convertView, contract);
			convertView.setTag(groupViewHolder);
		}
		groupViewHolder = (GroupViewHolder) convertView.getTag();
		groupViewHolder.changeData(getGroup(groupPosition), isExpanded, groupPosition);
		return convertView;
	}

	@Override
	public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
		ChildViewHolder childViewHolder;
		if (convertView == null) {
			convertView = LayoutInflater.from(contract.getContext()).inflate(R.layout.item_device_info_characteristics, parent, false);
			childViewHolder = new ChildViewHolder(convertView, contract);
			convertView.setTag(childViewHolder);
		}
		childViewHolder = (ChildViewHolder) convertView.getTag();
		childViewHolder.changeData(getChild(groupPosition, childPosition));
		return convertView;
	}

	@Override
	public boolean isChildSelectable(int groupPosition, int childPosition) {
		return false;
	}

	private static class GroupViewHolder implements View.OnClickListener {
		private ImageButton expandButton;
		private TextView serviceSpecificationName;
		private TextView serviceUUID;
		private TextView serviceType;
		private final View convertView;
		private int groupPosition;
		private boolean isExpanded;
		private final Contract contract;

		GroupViewHolder(View convertView, Contract contract) {
			this.convertView = convertView;
			this.contract = contract;
			findViews();
		}

		private void findViews() {
			expandButton = (ImageButton) convertView.findViewById(R.id.device_info_btn_group_expand);
			serviceSpecificationName = (TextView) convertView.findViewById(R.id.device_info_tv_service_name);
			serviceUUID = (TextView) convertView.findViewById(R.id.device_info_tv_service_uuid);
			serviceType = (TextView) convertView.findViewById(R.id.device_info_tv_service_type);
			expandButton.setOnClickListener(this);
			convertView.setOnClickListener(this);
		}

		public void setExpandButton(BLEGattService bleGattService, boolean isExpanded) {
			if (!bleGattService.getBleGattCharacteristics().isEmpty()) {
				expandButton.setVisibility(View.VISIBLE);
				if (isExpanded) {
					expandButton.setImageResource(R.drawable.ic_expand_less_black_24dp);
				} else {
					expandButton.setImageResource(R.drawable.ic_expand_more_black_24dp);
				}
			} else {
				expandButton.setVisibility(View.INVISIBLE);
			}
		}

		public void changeData(BLEGattService bleGattService, boolean isExpanded, int groupPosition) {
			setExpandButton(bleGattService, isExpanded);
			this.isExpanded = isExpanded;
			this.groupPosition = groupPosition;
			serviceSpecificationName.setText(bleGattService.getServiceSpecificationName());
			serviceUUID.setText(bleGattService.getServiceUUID());
			serviceType.setText(bleGattService.getServiceType().getType());
		}

		@Override
		public void onClick(View v) {
			if (v.getId() == R.id.device_info_btn_group_expand || v.getId() == R.id.device_info_layout_group_header) {
				expandCollapse();
			}
		}

		private void expandCollapse() {
			if (isExpanded) {
				contract.collapse(groupPosition);
			} else {
				contract.expand(groupPosition);
			}
		}
	}

	private static class ChildViewHolder implements View.OnClickListener {
		private TextView characteristicsSpecificationName;
		private TextView characteristicsUUID;
		private TextView characteristicsPermissions;
		private TextView characteristicsWriteTypes;
		private TextView characteristicsProperties;
		private TextView characteristicsValue;
		private LinearLayout characteristicsPropertiesActions;
		private Button characteristicsPropertyRead;
		private Button characteristicsPropertyWrite;
		private Button characteristicsPropertyNotify;
		private final View convertView;
		private final Contract contract;
		private BLEGattCharacteristic bleGattCharacteristic;

		ChildViewHolder(View convertView, Contract contract) {
			this.convertView = convertView;
			this.contract = contract;
			findViews();
		}

		private void findViews() {
			characteristicsSpecificationName = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_name);
			characteristicsUUID = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_uuid);
			characteristicsPermissions = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_permissions);
			characteristicsWriteTypes = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_write_type);
			characteristicsProperties = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_properties);
			characteristicsValue = (TextView) convertView.findViewById(R.id.device_info_tv_characteristic_value);
			characteristicsPropertiesActions = (LinearLayout) convertView.findViewById(R.id.device_info_layout_characteristic_properties_action);
			characteristicsPropertyRead = (Button) convertView.findViewById(R.id.device_info_btn_characteristic_read);
			characteristicsPropertyWrite = (Button) convertView.findViewById(R.id.device_info_btn_characteristic_write);
			characteristicsPropertyNotify = (Button) convertView.findViewById(R.id.device_info_btn_characteristic_notify);
			characteristicsPropertyRead.setOnClickListener(this);
			characteristicsPropertyWrite.setOnClickListener(this);
			characteristicsPropertyNotify.setOnClickListener(this);
		}

		public void changeData(BLEGattCharacteristic bleGattCharacteristic) {
			this.bleGattCharacteristic = bleGattCharacteristic;
			characteristicsSpecificationName.setText(bleGattCharacteristic.getCharacteristicSpecificationName());
			characteristicsUUID.setText(bleGattCharacteristic.getCharacteristicUUID());
			characteristicsPermissions.setText(bleGattCharacteristic.getPermissionsString());
			characteristicsWriteTypes.setText(bleGattCharacteristic.getWriteTypesString());
			characteristicsValue.setText(bleGattCharacteristic.getValue());
			characteristicsProperties.setText(bleGattCharacteristic.getPropertiesString());
			setPropertiesLayout(bleGattCharacteristic);
		}

		private void setAllActionsGone() {
			characteristicsPropertyRead.setVisibility(View.GONE);
			characteristicsPropertyWrite.setVisibility(View.GONE);
			characteristicsPropertyNotify.setVisibility(View.GONE);
		}

		private void setPropertiesLayout(BLEGattCharacteristic bleGattCharacteristic) {
			List<CharacteristicProperty> propertyList = bleGattCharacteristic.getCharacteristicProperties();
			if (!propertyList.isEmpty()) {
				characteristicsPropertiesActions.setVisibility(View.VISIBLE);
				setAllActionsGone();
				for (CharacteristicProperty characteristicProperty : propertyList) {
					makePropertyActionVisible(characteristicProperty);
				}
			} else {
				characteristicsPropertiesActions.setVisibility(View.INVISIBLE);
			}
		}

		private void makePropertyActionVisible(CharacteristicProperty characteristicProperty) {
			switch (characteristicProperty) {
				case PROPERTY_READ:
					characteristicsPropertyRead.setVisibility(View.VISIBLE);
					break;
				case PROPERTY_WRITE_NO_RESPONSE:
					characteristicsPropertyWrite.setVisibility(View.VISIBLE);
					break;
				case PROPERTY_WRITE:
					characteristicsPropertyWrite.setVisibility(View.VISIBLE);
					break;
				case PROPERTY_SIGNED_WRITE:
					characteristicsPropertyWrite.setVisibility(View.VISIBLE);
					break;
				case PROPERTY_NOTIFY:
					characteristicsPropertyNotify.setVisibility(View.VISIBLE);
					break;
			}
		}

		@Override
		public void onClick(View v) {
			switch (v.getId()) {
				case R.id.device_info_btn_characteristic_read:
					contract.readCharacteristic(bleGattCharacteristic);
					break;
				case R.id.device_info_btn_characteristic_write:
					contract.writeCharacteristic(bleGattCharacteristic);
					break;
				case R.id.device_info_btn_characteristic_notify:
					break;
			}
		}
	}
}
