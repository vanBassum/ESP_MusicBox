#pragma once


#include "lvgl/lvgl.h"
#include "control.h"



namespace LVGL
{
	class Label : public Control
	{
		
	public:
		Label(Control& parent)
		{
			lvglMutex->Take();
			handle = lv_label_create(parent.handle, NULL);
			lv_label_set_text(handle, "Label");    
			lv_obj_set_size(handle, 120, 50);
			lvglMutex->Give();
		}
	};
}
