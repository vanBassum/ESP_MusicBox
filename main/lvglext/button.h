#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "widget.h"
#include "../lib/Misc/Callback.h"




namespace LVGL
{
	
	class Button : public Widget
	{		
	public:
		Button(Widget& parent)
		{
			lvglMutex->Take();
			handle = lv_btn_create(parent.GetHandle(), NULL);
			handle->user_data = this;
			lvglMutex->Give();
		}
	};
}
