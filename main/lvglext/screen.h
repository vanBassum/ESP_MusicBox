#pragma once


/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "control.h"

namespace LVGL
{
	class Screen : public Control
	{
	public:
		
		virtual void Create(lv_obj_t* parent) override
		{
			//the only control that doenst need to be created.
		}

		Screen(lv_obj_t* h)
		{
			this->handle = h;
		}	
	};	
}












