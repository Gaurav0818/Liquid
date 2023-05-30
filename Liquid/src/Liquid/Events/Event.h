#pragma once

#include "Liquid\Core.h"

namespace LqD {

	// Events are currently blocking, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.
	// For the future, a better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	// An enumeration of all possible event types.
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// An enumeration of all possible event categories.
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	// A macro that defines the static type and virtual functions for an event class.
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	// A macro that defines the category flags for an event class.
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// The base class for all events.
	class LIQUID_API Event
	{
		friend class EventDispatcher;
	public:
		// Returns the type of the event.
		virtual EventType GetEventType() const = 0;
		// Returns the name of the event.
		virtual const char* GetName() const = 0;
		// Returns the category flags for the event.
		virtual int GetCategoryFlags() const = 0;
		// Converts the event to a string.
		virtual std::string ToString() const { return GetName(); }
		// Returns true if the event is in the specified category.
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		// Whether the event has been handled.
		bool m_Handled = false;
	};

	// A class that dispatches events.
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		// Creates a new event dispatcher for the specified event.
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}
		// Dispatches the event to the specified function.
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		// The event that is being dispatched.
		Event& m_Event;
	};

	// Overloads the << operator to output an event to a stream.
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
