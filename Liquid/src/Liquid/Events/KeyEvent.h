#pragma once

#include "Event.h"

namespace LqD {
	// This class represents a keyboard event.
	class LIQUID_API KeyEvent : public Event
	{
	public:
		// This function returns the key code of the event.
		inline int GetKeyCode() const { return m_KeyCode; }
		
		// This macro defines the event category for keyboard events.
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
		
		// This member variable stores the key code of the event.
		int m_KeyCode;
	};
	
	// This class represents a keyboard press event.
	class LIQUID_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		// This function returns the repeat count of the event.
		inline int GetRepeatCount() const { return m_RepeatCount; }
		
		// This function converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		// This macro defines the event type for keyboard press events.
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		// This member variable stores the repeat count of the event.
		int m_RepeatCount;
	};

	// This class represents a keyboard release event.
	class LIQUID_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		// This function converts the event to a string.
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		// This macro defines the event type for keyboard release events.
		EVENT_CLASS_TYPE(KeyReleased)
	};
}