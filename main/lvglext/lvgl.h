#pragma once

#define CONFIG_LVGL_FEATURE_USE_USER_DATA

#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"
#include "../lib/FreeRTOS.h"
#include "esp_log.h"

#include "widget.h"
#include "screen.h"
#include "button.h"
#include "label.h"

namespace LVGL
{
	
	
	static FreeRTOS::Timer* tickTimer;
	static FreeRTOS::Task* guiTask;
		
	static void GuiTask(void* args)
	{
		while (1) 
		{
			vTaskDelay(2);
			lvglMutex->Take();
			lv_task_handler();
			lvglMutex->Give();
		}
	}
	
	static void Tick(FreeRTOS::Timer* t)
	{
		lv_tick_inc(t->GetPeriod());
	}
		
		
	static Screen& Init()
	{
		lvglMutex = new FreeRTOS::Mutex();
		lv_init();
		lvgl_driver_init();

		static lv_color_t buf1[DISP_BUF_SIZE];
		static lv_color_t buf2[DISP_BUF_SIZE];
		static lv_disp_buf_t disp_buf;
		uint32_t size_in_px = DISP_BUF_SIZE;
		lv_disp_buf_init(&disp_buf, buf1, buf2, size_in_px);
		lv_disp_drv_t disp_drv;
		lv_disp_drv_init(&disp_drv);
		disp_drv.flush_cb = disp_driver_flush;
		disp_drv.buffer = &disp_buf;
		lv_disp_drv_register(&disp_drv);
		
		lv_indev_drv_t indev_drv;
		lv_indev_drv_init(&indev_drv);
		indev_drv.read_cb = touch_driver_read;
		indev_drv.type = LV_INDEV_TYPE_POINTER;
		lv_indev_drv_register(&indev_drv);
			
		guiTask = new FreeRTOS::Task("LVGL");
		guiTask->Bind(&LVGL::GuiTask);
		guiTask->RunPinned(0, 4096 * 2, 1, NULL);
		
		tickTimer = new FreeRTOS::Timer("LVGL");
		tickTimer->Bind(&LVGL::Tick);
		tickTimer->SetPeriod(10);
		tickTimer->Start();

		Screen* screen = new Screen();
		return *screen;
	}
}
