
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "lvglext/lvgl.h"
#include "esp_log.h"
#include "lvgl/lvgl.h"




extern "C"{	
	void app_main();
}


void OnClick(LVGL::Widget* btn, lv_event_t event)
{
	if (event == LV_EVENT_PRESSED)
		ESP_LOGI("Main", "LV_EVENT_PRESSED");
}


void app_main() 
{
	
	
	LVGL::Screen screen = LVGL::Init();
	LVGL::Button btn(screen);	
	LVGL::Label label(btn);
	
	btn.SetSize(200, 100);
	btn.SetPosition(50, 50);

	
	btn.SetCallback(&OnClick);
	
	//btn.OnPressed.Bind(&OnClick);

    while(1)
        vTaskDelay(1000);
}
