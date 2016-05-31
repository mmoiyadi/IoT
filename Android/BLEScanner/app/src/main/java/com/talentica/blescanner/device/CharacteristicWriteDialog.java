package com.talentica.blescanner.device;

import android.support.v4.app.DialogFragment;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by NavalB on 27-05-2016.
 */
public class CharacteristicWriteDialog {

	public static DialogFragment create(BLEGattCharacteristic bleGattCharacteristic) {
		Characteristic characteristic = GattCharacteristicSpecification.getCharacteristic(bleGattCharacteristic.getAssignedNumberHexString());
		if (characteristic != null) {
			switch (characteristic.getDataType()) {
				case STRING:
					return WriteStringDialog.newInstance(bleGattCharacteristic.getValue(),"Enter device name");
				case INTEGER:
					ArrayList<Integer> arrayList = new ArrayList<>();
					for (Object object : Arrays.asList(characteristic.getPermissibleValue())){
						if(object instanceof Integer)
							arrayList.add((Integer) object);
				}
				return WriteIntegerDialog.newInstance(arrayList, characteristic.getFormatType());
			}
		} return null;
	}
}
