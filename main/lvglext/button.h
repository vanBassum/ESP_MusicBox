#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "control.h"


namespace LVGL
{
	class Button : public Control
	{
		
	protected:
		virtual void Create(lv_obj_t* parent) override
		{
			lvglMutex->Take();
			handle = lv_btn_create(parent, NULL);
			lv_obj_set_pos(handle, 10, 10);  
			lv_obj_set_size(handle, 120, 50);
			lvglMutex->Give();
		}
	};
}
