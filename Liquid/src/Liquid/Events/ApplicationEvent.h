#pragma once

#include "Event.h"

namespace LqD {
	// Represents a window resize event.
	class LIQUID_API WindowResizeEvent : public Event
	{
	public:
		// Constructs a window resize event with the specified width and height.
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}
		// Returns the width of the window.
		inline unsigned int GetWidth() const { return m_Width; }
		// Returns the height of the window.
		inline unsigned int GetHeight() const { return m_Height; }

		// Converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}
		// Defines the static type of the event.
		EVENT_CLASS_TYPE(WindowResize)
		// Defines the category flags for the event.
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	// Represents a window close event.
	class LIQUID_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}
		// Defines the static type of the event.
		EVENT_CLASS_TYPE(WindowClose)
		// Defines the category flags for the event.
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Represents an application tick event.
	class LIQUID_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		// Defines the static type of the event.
		EVENT_CLASS_TYPE(AppTick)
		// Defines the category flags for the event.
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Represents an application update event.
	class LIQUID_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		// Defines the static type of the event.
		EVENT_CLASS_TYPE(AppUpdate)
		// Defines the category flags for the event.
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	// Represents an application render event.
	class LIQUID_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		// Defines the static type of the event.
		EVENT_CLASS_TYPE(AppRender)
		// Defines the category flags for the event.
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}