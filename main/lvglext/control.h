#pragma once

#include "../lib/FreeRTOS.h"
#include "lvgl/lvgl.h"
#include "esp_log.h"


namespace LVGL
{
	static FreeRTOS::Mutex* lvglMutex;
	
	class Control
	{
	protected:
		lv_obj_t* handle = NULL;
		virtual void Create(lv_obj_t* parent) = 0;

	public:
		void AddControl(Control& ctrl)
		{
			//Here we actually initialize the object.
			if(ctrl.handle != NULL)
			{
				ctrl.Create(handle);
			}
			else
			{
				ESP_LOGI("Control", "Control already child of another control");
			}
		}
	};
}