#pragma once

#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"
#include "lib/FreeRTOS.h"
#include "esp_log.h"


namespace LVGL
{
	class Control
	{
	protected:
		lv_obj_t* handle;
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