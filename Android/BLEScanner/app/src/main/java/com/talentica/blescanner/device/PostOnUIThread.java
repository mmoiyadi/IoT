package com.talentica.blescanner.device;

import android.os.Handler;
import android.os.Looper;

import java.util.List;

/**
 * Created by NavalB on 25-05-2016.
 */
public class PostOnUIThread implements GattResult {
	private final GattResult originalCallback;
	private final Handler uiHandler;

	PostOnUIThread(GattResult originalCallback) {
		this.originalCallback = originalCallback;
		uiHandler = new Handler(Looper.getMainLooper());
	}

	@Override
	public void loadServices(final List<BLEGattService> gattServiceList) {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.loadServices(gattServiceList);
			}
		});
	}

	@Override
	public void onConnected() {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.onConnected();
			}
		});
	}

	@Override
	public void onDisconnected() {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.onDisconnected();
			}
		});
	}

	@Override
	public void onSuccessfulCharacteristicRead() {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.onSuccessfulCharacteristicRead();
			}
		});
	}

	@Override
	public void onSuccessfulCharacteristicWrite() {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.onSuccessfulCharacteristicWrite();
			}
		});
	}

	@Override
	public void onFailureCharacteristicWrite() {
		uiHandler.post(new Runnable() {
			@Override
			public void run() {
				originalCallback.onFailureCharacteristicWrite();
			}
		});
	}
}
