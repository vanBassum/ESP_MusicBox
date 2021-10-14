#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "control.h"


namespace LVGL
{
	class Label : public Control
	{
		
	protected:
		virtual void Create(lv_obj_t* parent) override
		{
			lvglMutex->Take();
			handle = lv_label_create(parent, NULL);
			lv_label_set_text(handle, "Label");    
			lvglMutex->Give(); 
		}
	};
}
