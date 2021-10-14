
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


void app_main() 
{

	LVGL::Screen screen = LVGL::Init();

	LVGL::Button btn(screen);	
	LVGL::Label label(btn);
	
	btn.OnClick.Bind(&OnClick);

    while(1)
        vTaskDelay(1000);
}
