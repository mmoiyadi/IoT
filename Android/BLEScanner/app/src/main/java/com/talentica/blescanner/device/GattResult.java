package com.talentica.blescanner.device;

import java.util.List;

/**
 * Created by NavalB on 24-05-2016.
 */
public interface GattResult {
	void loadServices(List<BLEGattService> gattServiceList);
	void onConnected();
	void onDisconnected();
	void onSuccessfulCharacteristicRead();

	void onSuccessfulCharacteristicWrite();

	void onFailureCharacteristicWrite();
}
