#pragma once

#include "Event.h"

namespace LqD {
	// This class represents a mouse moved event.
	class LIQUID_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}
		// This function returns the mouse x coordinate of the event.
		inline float GetX() const { return m_MouseX; }
		// This function returns the mouse y coordinate of the event.
		inline float GetY() const { return m_MouseY; }

		// This function converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}
		// This macro defines the event type for mouse moved events.
		EVENT_CLASS_TYPE(MouseMoved)
		// This macro defines the event category for mouse moved events.
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};
	
	// This class represents a mouse scrolled event.
	class LIQUID_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}
		// This function returns the mouse x scroll offset of the event.
		inline float GetXOffset() const { return m_XOffset; }
		// This function returns the mouse y scroll offset of the event.
		inline float GetYOffset() const { return m_YOffset; }
		
		// This function converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		// This macro defines the event type for mouse scrolled events.
		EVENT_CLASS_TYPE(MouseScrolled)
		// This macro defines the event category for mouse scrolled events.
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};

	// This class represents a mouse button event.
	class MouseButtonEvent : public Event {
	public:
		// This function returns the mouse button of the event.
		inline int GetMouseButton() const { return m_Button; }

		// This macro defines the event category for mouse button events.
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
		  : m_Button(button) {}
		
		int m_Button;
	};

	// This class represents a mouse button pressed event.
	class LIQUID_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}
		
		// This function converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		// This macro defines the event type for mouse scrolled events.
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	
	// This class represents a mouse button release event.
	class LIQUID_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		
		// This function converts the event to a string
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		// This macro defines the event type for mouse scrolled events.
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}