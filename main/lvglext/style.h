#pragma once

#include "../lib/FreeRTOS.h"
#include "lvgl/lvgl.h"
#include "esp_log.h"



namespace LVGL
{
	class Style
	{
		lv_style_t handle;
	public:
		
		Style()
		{
			lv_style_init(&handle);
		}
		
		
		void SetBackgroundColor()
		{
			lv_style_set_bg_color(&handle, LV_STATE_DEFAULT, LV_COLOR_SILVER);
		}

		lv_style_t* GetHandle()
		{
			return &handle;
		}
		
	};
}
