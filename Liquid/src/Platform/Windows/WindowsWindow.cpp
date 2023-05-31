#include "pch.h"
#include "WindowsWindow.h"

#include "Liquid/Log.h"

namespace LqD
{
    // This static variable is used to track whether GLFW has been initialized.
    static bool s_GLFWInitialized = false;

    // This function creates a new Window object.
    Window* Window::Create(const WindowProps& props)
    {
        // Returns a new WindowsWindow object with the specified properties.
        return new WindowsWindow(props);
    }

    // This constructor creates a new WindowsWindow object with the specified properties.
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        // Initializes the window.
        Init(props);
    }

    // This destructor destroys the WindowsWindow object.
    WindowsWindow::~WindowsWindow()
    {
        // Shuts down the window.
        Shutdown();
    }

    // This function initializes the window.
    void WindowsWindow::Init(const WindowProps& props)
    {
        // Sets the window's Properties
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        // Log a message to the console, indicating that the window is being created.
        LQD_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        // Check if GLFW has been initialized.
        if(!s_GLFWInitialized)
        {
            // Initialize GLFW.
            int success = glfwInit();
            // Log an error to the console if GLFW failed to initialize.
            LQD_CORE_ASSERT(success, "Could not initialize GLFW!");

            // Sets the flag to indicate that GLFW has been initialized.
            s_GLFWInitialized = true;
        }

        // Creates the GLFW window.
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        // Makes the window's context current.
        glfwMakeContextCurrent(m_Window);
        // Sets the window user pointer to point to the window's data.
        glfwSetWindowUserPointer(m_Window, &m_Data);
        // Sets  the VSync state to true.
        SetVSync(true);
    }

    void WindowsWindow::Shutdown()
    {
        // Destroys the GLFW window.
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        // Polls for events.
        glfwPollEvents();
        // Swaps the buffers.
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if(enabled)
            //The swap interval is a value that specifies
            //how many frames the graphics card will wait before displaying a new frame.
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        // Updates the window data struct.
        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

}
