#pragma once


namespace LVGL
{
	
	enum class Events
	{
		PRESSED,
		PRESSING,
		PRESS_LOST,
		SHORT_CLICKED,
		LONG_PRESSED,
		LONG_PRESSED_REPEAT,
		CLICKED,
		RELEASED,
		DRAG_BEGIN,
		DRAG_END,
		DRAG_THROW_BEGIN,
		GESTURE,
		KEY,
		FOCUSED,
		DEFOCUSED,
		LEAVE,
		VALUE_CHANGED,
		INSERT,
		REFRESH,
		APPLY,
		CANCEL,
		DELETE,
	};
}
