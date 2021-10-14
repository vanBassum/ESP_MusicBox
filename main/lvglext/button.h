#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "control.h"


namespace LVGL
{
	class Button : public Control
	{
	public:
		Button(Control& parent)
		{
			lvglMutex->Take();
			handle = lv_btn_create(parent.GetHandle(), NULL);
			lv_obj_set_pos(handle, 10, 10);  
			lv_obj_set_size(handle, 120, 50);
			lvglMutex->Give();
		}
	};
}
