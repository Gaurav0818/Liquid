#pragma once

#include "Liquid/Window.h"

#include "GLFW/glfw3.h"

namespace LqD
{
    class WindowsWindow : public Window
    {
    public:
        // This constructor creates a new WindowsWindow object with the specified properties.
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();
        
        // This function is called every frame to update the window.
        void OnUpdate() override;

        // This function returns the width of the window.
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        // This function returns the height of the window.
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        // Window attributes
        // This function sets the window's event callback function.
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        // This function sets the window's VSync state.
        void SetVSync(bool enabled) override;
        // This function returns the window's VSync state.
        bool IsVSync() const override;

    private:
        // This function initializes the window.
        virtual void Init(const WindowProps& props);
        // This function shuts down the window.
        virtual void Shutdown();

    private:
        // This is a pointer to the GLFW window object.
        GLFWwindow* m_Window;

        // This struct contains the window's data.
        struct WindowData
        {
            // The window's title.
            std::string Title;
            // The window's width and height.
            unsigned int Width, Height;
            // The window's VSync state.
            bool VSync;

            // The window's event callback function
            EventCallbackFn EventCallback;
        };

        // This is the window's data.
        WindowData m_Data;    
    
    };
}

