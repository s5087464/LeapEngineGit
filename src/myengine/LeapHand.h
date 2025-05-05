#pragma once

#include "Component.h"
#include <Leap.h>
#include "Model.h"
#include "ModelShader.h"

namespace myengine
{
    class LeapHand : public Component
    {
    public:
        void onInitialize() override;
        void onUpdate() override;
        void onRender() override;

    private:
        Leap::Controller controller;
        std::vector<Leap::Hand> hands;
        std::shared_ptr<Model> handModel;
        std::shared_ptr<ModelShader> handShader;
    };
} 