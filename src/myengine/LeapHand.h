#pragma once

#include "Component.h"
#include <LeapC.h>
#include "Model.h"
#include "rend/ModelShader.h"

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
        std::shared_ptr<rend::ModelShader> handShader;
    };
} 