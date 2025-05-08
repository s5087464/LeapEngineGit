#include "LeapInitialize.h"
#include <iostream>

namespace myengine
{

	void LeapInitialize::OnConnect()
	{
		OpenConnection();
		while (!IsConnected)
			millisleep(600);
	}

	void LeapInitialize::OnDevice()
	{
		LEAP_DEVICE_INFO* props = GetDeviceProperties();
		if (props)
		{
			std::cout << "Leap Connected.\n" << std::endl;
			std::cout << "Found device : " << props->serial << "\n" << std::endl;
		}
	}

	//void LeapInitialize::on_initialize()
	//{
	//	m_is_connected = false;
	//	connectionHandle = OpenConnection();

	//	if (!connectionHandle)
	//	{
	//		std::cout << "Leap Motionの接続に失敗しました。" << std::endl;
	//		return;
	//	}

	//	// 接続状態のコールバックを設定
	//	ConnectionCallbacks.on_connection = [this]() {
	//		m_is_connected = true;
	//		std::cout << "Leap Motionに接続しました。" << std::endl;
	//	};

	//	ConnectionCallbacks.on_connection_lost = [this]() {
	//		m_is_connected = false;
	//		std::cout << "Leap Motionとの接続が切れました。" << std::endl;
	//	};

	//	ConnectionCallbacks.on_device_failure = [this](const eLeapDeviceStatus failure_code, const LEAP_DEVICE failed_device) {
	//		m_is_connected = false;
	//		std::cout << "Leap Motionデバイスでエラーが発生しました。エラーコード: " << failure_code << std::endl;
	//	};
	//}

	

	/*void LeapInitialize::on_destroy()
	{
		if (connectionHandle)
		{
			CloseConnection();
			DestroyConnection();
			connectionHandle = nullptr;
		}
	}*/
} 