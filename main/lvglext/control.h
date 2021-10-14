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
		
	public:
		lv_obj_t* GetHandle()
		{
			return handle;
		}
		
	};
}