#include "pch.h"
#include "LayerStack.h"

LqD::LayerStack::LayerStack()
{
    // This Constructor initializes the m_LayerInsert Iterator to the beginning of the m_Layer vector.
    m_LayerInsert = m_Layers.begin();
}

LqD::LayerStack::~LayerStack()
{
    // This Destructor deletes all the layers in the m_Layers vector 
    for (auto layer : m_Layers)
        delete layer;
}

void LqD::LayerStack::PushLayer(Layer* layer)
{
    // This Function pushes a layer onto the stack.
    // The m_LayerInsert Iterator is updated to point at the new layer.
    m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
}

void LqD::LayerStack::PushOverlay(Layer* overlay)
{
    // This function pushes an overlay onto the stack.
    // Overlays are always drawn on top of layers, so they are inserted at the end of the m_layers vector.
    m_Layers.emplace_back(overlay);
}

void LqD::LayerStack::PopLayer(Layer* layer)
{
    // This function pops a layer off the stack.
    // The m_layerInset iterator is updated to point to the layer before the one that was popped.
    // If the layer that is popped is the last layer ( layer was not found), then function does nothing 
    auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if( it != m_Layers.end())
    {
        m_Layers.erase(it);
        m_LayerInsert--;
    }
}

void LqD::LayerStack::PopOverlay(Layer* overlay)
{
    // This function pops an overlay off the stack.
    // The `m_LayerInsert` iterator is not updated, because overlays are always drawn on top of layers.
    // If the overlay was not found, the function does nothing.
    auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
    if( it != m_Layers.end())
        m_Layers.erase(it);
}




