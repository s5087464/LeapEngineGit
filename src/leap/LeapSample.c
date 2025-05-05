#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "LeapC.h"
#include "ExampleConnection.h"

#ifdef __cplusplus
extern "C" {
#endif

int64_t lastFrameID = 0; //The last frame received

// 座標データを取得するための構造体
typedef struct {
    float x;
    float y;
    float z;
} LeapPosition;

// 回転データを取得するための構造体
typedef struct {
    float x;
    float y;
    float z;
    float w;
} LeapRotation;

// 手のデータを取得するための構造体
typedef struct {
    LeapPosition position;
    LeapRotation rotation;
    int id;
    int type;  // 0: 左手, 1: 右手
} LeapHandData;

// 初期化関数
bool InitLeapMotion() 
{
    OpenConnection();
    while (!IsConnected)
        millisleep(100); //wait a bit to let the connection complete

    printf("Connected to Leap Motion.\n");
    LEAP_DEVICE_INFO* deviceProps = GetDeviceProperties();
    if (deviceProps) {
        printf("Using device %s.\n", deviceProps->serial);
        return true;
    }
    return false;
}

// 終了関数
void CleanupLeapMotion()
{
    CloseConnection();
    DestroyConnection();
}

// 手のデータを取得する関数
LeapHandData GetHandData(int handIndex) {
    LeapHandData handData = {0};
    LEAP_TRACKING_EVENT* frame = GetFrame();
    
    if (frame && frame->nHands > handIndex) {
        LEAP_HAND* hand = &frame->pHands[handIndex];
        
        // 位置データ
        handData.position.x = hand->palm.position.x;
        handData.position.y = hand->palm.position.y;
        handData.position.z = hand->palm.position.z;
        
        // 回転データ
        handData.rotation.x = hand->palm.orientation.x;
        handData.rotation.y = hand->palm.orientation.y;
        handData.rotation.z = hand->palm.orientation.z;
        handData.rotation.w = hand->palm.orientation.w;
        
        // 手のIDとタイプ
        handData.id = hand->id;
        handData.type = (hand->type == eLeapHandType_Left) ? 0 : 1;
        
        // ログ出力
        printf("Hand %d (ID: %d, Type: %s) - Position: (%.2f, %.2f, %.2f), Rotation: (%.2f, %.2f, %.2f, %.2f)\n",
            handIndex,
            handData.id,
            handData.type == 0 ? "Left" : "Right",
            handData.position.x,
            handData.position.y,
            handData.position.z,
            handData.rotation.x,
            handData.rotation.y,
            handData.rotation.z,
            handData.rotation.w);
    }
    
    return handData;
}

// 手の数を取得する関数
int GetHandCount() {
    LEAP_TRACKING_EVENT* frame = GetFrame();
    return frame ? frame->nHands : 0;
}

// フレームIDを取得する関数
int64_t GetFrameID() {
    LEAP_TRACKING_EVENT* frame = GetFrame();
    return frame ? frame->tracking_frame_id : 0;
}

#ifdef __cplusplus
}
#endif
//End-of-Sample