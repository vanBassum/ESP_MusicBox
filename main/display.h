#pragma once


/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"
#include "lib/FreeRTOS.h"


#define LV_TICK_PERIOD_MS 10

 /**********************
  *  STATIC PROTOTYPES
  **********************/
static void lv_tick_task(void* arg);
void guiTask(void* pvParameter);



class Display
{
	FreeRTOS::Mutex lvglMutex;
	FreeRTOS::Timer tickTimer = FreeRTOS::Timer("LVGL Tick");
	FreeRTOS::Task guiTask = FreeRTOS::Task("LVGL task");

	void GuiTask(void* args)
	{
		lvglMutex.Take();

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
        lvglMutex.Give();
		
        while (1) 
        {
            vTaskDelay(1);
            lvglMutex.Take();
            lv_task_handler();
            lvglMutex.Give();
        }
	}

    void Tick(FreeRTOS::Timer* t)
    {
        lv_tick_inc(t->GetPeriod());
    }
	

public:

	Display()
	{
        guiTask.Bind(this, &Display::GuiTask);
		guiTask.RunPinned(0, 4096 * 2, 1, NULL);
        tickTimer.Bind(this, &Display::Tick);
        tickTimer.SetPeriod(10);
        tickTimer.Start();
    }

    void Test()
    {
        lvglMutex.Take();
        lv_obj_t* btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
        lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
        lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
        lv_obj_t* label = lv_label_create(btn, NULL);          /*Add a label to the button*/
        lv_label_set_text(label, "Button");                     /*Set the labels text*/
        lvglMutex.Give();
    }

};











