#pragma once

#include <string>
#include "lvgl/lvgl.h"
#include "widget.h"



namespace LVGL
{
	class Label : public Widget
	{
		
	public:
		Label(Widget& parent)
		{
			lvglMutex->Take();
			handle = lv_label_create(parent.GetHandle(), NULL);
			lv_label_set_text(handle, "Label");    
			lv_obj_set_size(handle, 120, 50);
			lvglMutex->Give();
		}
		
		void SetText(std::string text)
		{
			lv_label_set_text(handle, text.c_str());
		}
		
		template<typename ...Args>
		void SetText(std::string text, Args... args)
		{
			lv_label_set_text_fmt(handle, text.c_str(), args...);
		}
		
	};
}
