#include "LeapHand.h"
#include "Entity.h"
#include "Transform.h"
#include "Resources.h"
#include "Core.h"

namespace myengine
{
    void LeapHand::onInitialize()
    {
        // Leap Motionコントローラーの初期化
        controller.setPolicy(Leap::Controller::POLICY_OPTIMIZE_HMD);

        // 手のモデルとシェーダーの読み込み
        handModel = getCore()->getResources()->load<Model>("models/hand.obj");
        handShader = getCore()->getResources()->load<ModelShader>("shaders/model");
    }

    void LeapHand::onUpdate()
    {
        // フレームデータの取得
        Leap::Frame frame = controller.frame();
        hands = frame.hands();

        // 手の位置と回転を更新
        if (!hands.empty())
        {
            Leap::Hand hand = hands[0];
            Leap::Vector palmPosition = hand.palmPosition();
            Leap::Vector palmNormal = hand.palmNormal();
            Leap::Vector direction = hand.direction();

            // 位置の更新
            getEntity()->getTransform()->setPosition(
                palmPosition.x / 1000.0f,  // mmからmに変換
                palmPosition.y / 1000.0f,
                palmPosition.z / 1000.0f
            );

            // 回転の更新（簡易的な実装）
            // 実際の実装では、より正確な回転計算が必要です
            getEntity()->getTransform()->setRotation(
                direction.pitch() * 180.0f / M_PI,
                direction.yaw() * 180.0f / M_PI,
                0.0f
            );
        }
    }

    void LeapHand::onRender()
    {
        if (handModel && handShader)
        {
            // モデルのレンダリング
            handModel->render(handShader);
        }
    }
} 