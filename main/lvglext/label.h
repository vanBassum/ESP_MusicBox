#pragma once


#include "lvgl/lvgl.h"
#include "control.h"



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
		
		
	};
}
