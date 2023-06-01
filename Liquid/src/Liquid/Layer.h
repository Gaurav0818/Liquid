#pragma once

#include "Liquid/Core.h"
#include "Liquid/Events/Event.h"

namespace LqD
{
    // This class represents a layer in the Liquid engine
    class LIQUID_API Layer
    {
    public:
        // Constructs a new layer with the given name.
        Layer(const std::string& name = "Layer") : m_DebugName(name){}
        // Destroys the layer.
        virtual ~Layer();

        // Called when the layer is attached to the engine.
        virtual void OnAttach();
        // Called when the layer is detached from the engine.
        virtual void OnDetach();
        // Called every frame.
        virtual void OnUpdate();
        // Called when an event occurs.
        virtual void OnEvent(Event& event){}

        // Returns the name of the layer.
        inline const std::string& GetName() const { return m_DebugName; }

    protected:
        // The name of the layer.
        std::string m_DebugName;
    
    };
}

