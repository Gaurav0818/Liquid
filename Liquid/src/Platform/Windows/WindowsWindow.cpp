#include "pch.h"
#include "WindowsWindow.h"

#include "Liquid/Log.h"
#include "Liquid/Events/ApplicationEvent.h"
#include "Liquid/Events/KeyEvent.h"
#include "Liquid/Events/MouseEvent.h"

namespace LqD
{
    // This static variable is used to track whether GLFW has been initialized.
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error_code, const char* description)
    {
        LQD_CORE_ERROR("GLFW Error ({0}): {1}", error_code, description);
    }

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

            glfwSetErrorCallback(LqD::GLFWErrorCallback);

            // Sets the flag to indicate that GLFW has been initialized.
            s_GLFWInitialized = true;
        }

        // Creates the GLFW window.
        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        // Makes the window's context current.
        glfwMakeContextCurrent(m_Window);
        // Sets the window user pointer to point to the window's data.
        // So that we can access the window's data from the GLFW callbacks.
        glfwSetWindowUserPointer(m_Window, &m_Data);
        // Sets  the VSync state to true.
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [] (GLFWwindow* window, int width, int height)
        {
            WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
            
            data.Width = width;
            data.Height = height;
            
            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window,[](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            switch (action)
            {
            case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_Window, []( GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));

            switch (action)
            {
            case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            case GLFW_REPEAT:
                {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window,[](GLFWwindow* window, double xoffset, double yoffset)
        {
            WindowData& data = *(WindowData*)(glfwGetWindowUserPointer(window));
            
            MouseScrolledEvent event((float)xoffset, (float)yoffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window,[](GLFWwindow* window, double xpos, double ypos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            MouseMovedEvent event((float)xpos, (float)ypos);
            data.EventCallback(event);
        });
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
