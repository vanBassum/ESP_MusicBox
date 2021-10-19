#pragma once

#include "../lib/FreeRTOS.h"
#include "lvgl/lvgl.h"
#include "esp_log.h"
#include "events.h"

#define LVGL_GLOBAL_EVENT
#define LVGL_SPECIFIC_EVENTS

namespace LVGL
{
	static FreeRTOS::Mutex* lvglMutex;
	
	
	class Widget
	{
	protected:
		lv_obj_t* handle = NULL;
		
	private:
		Callback<void, Widget*, lv_event_t> OnEvent;
		
		static void Event(lv_obj_t * sender, lv_event_t event)
		{
			Widget* obj = (Widget*)sender->user_data;
			if (obj != NULL)
			{
				if (obj->OnEvent.IsBound()) 
					obj->OnEvent.Invoke(obj, event); 
			}
			else
			{
				ESP_LOGE("LVGL::Widget", "User data == NULL, can't retrieve Widget*");
			}
		}
		
	public:
		
		Widget()
		{
		}
		
		~Widget()
		{
			lv_obj_del_async(handle);
		}
		
		template<typename T>
		void SetCallback(T* instance, void(T::*method)(Widget*, lv_event_t))
		{
			if(!OnEvent.IsBound())
				lv_obj_set_event_cb(handle, &Widget::Event);
			OnEvent.Bind(instance, method);
		}
		
		void SetCallback(void(*method)(Widget*, lv_event_t))
		{
			if (!OnEvent.IsBound())
				lv_obj_set_event_cb(handle, &Widget::Event);
			OnEvent.Bind(method);
		}
		
		
		lv_obj_t* GetHandle()
		{
			return handle;
		}
		
		
		void SetPosition(int x, int y)
		{
			lv_obj_set_pos(handle, x, y);  
		}
		
		void SetSize(int width, int height)
		{
			lv_obj_set_size(handle, width, height);
		}
		
		
		
	};
}