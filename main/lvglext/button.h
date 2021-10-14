#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "lvgl_helpers.h"
#include "lib/FreeRTOS.h"
#include "esp_log.h"
#include "control.h"


namespace LVGL
{
	class Button : public Control
	{
		
	protected:
		virtual void Create(lv_obj_t* parent) override
		{
			lv_obj_t* btn = lv_btn_create(parent, NULL);
			lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
			lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
			//lv_obj_t* label = lv_label_create(btn, NULL);          /*Add a label to the button*/
			//lv_label_set_text(label, "Button");                     /*Set the labels text*/
		}
	};
}
