
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "lvglext/lvgl.h"
#include "esp_log.h"
#include "lvgl/lvgl.h"


extern "C"{	
	void app_main();
}


void OnClick(LVGL::Button* btn)
{
	ESP_LOGI("Main", "BtnClicked");
}

static void btn_event_cb(lv_obj_t * btn, lv_event_t event)
{
	if (event == LV_EVENT_CLICKED) {
		static uint8_t cnt = 0;
		cnt++;

		/*Get the first child of the button which is the label and change its text*/
		lv_obj_t * label = lv_obj_get_child(btn, NULL);
		lv_label_set_text_fmt(label, "Button: %d", cnt);
	}
}

void lv_ex_get_started_1(void)
{
	lv_obj_t * btn = lv_btn_create(lv_scr_act(), NULL);     /*Add a button the current screen*/
	lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
	lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
	lv_obj_set_event_cb(btn, btn_event_cb);                 /*Assign a callback to the button*/

	lv_obj_t * label = lv_label_create(btn, NULL);          /*Add a label to the button*/
	lv_label_set_text(label, "Button");                     /*Set the labels text*/
}

void app_main() 
{

	LVGL::Screen screen = LVGL::Init();

	//LVGL::Button btn(screen);	
	//LVGL::Label label(btn);
	//
	//btn.OnClick.Bind(&OnClick);
	
	lv_ex_get_started_1();

    while(1)
        vTaskDelay(1000);
}
