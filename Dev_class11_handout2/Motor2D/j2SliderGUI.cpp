#include "j2SliderGUI.h"
#include "j1Gui.h"
#include "j1App.h"


j2SliderGUI::j2SliderGUI(int id, const char* name, ElementType Element, ElementAction action, iPoint position, SDL_Rect rect, SDL_Rect buttonRect, bool isStatic, SDL_Texture*tex, bool draggable, bool interactable, bool invisible) 
	: ElementGUI(id, name, Element, action, position,rect,isStatic, draggable,interactable, invisible, tex)
{
	ElementGUI* SliderImage = App->gui->CreateElement(id, name, ElementType::SPRITE,ElementAction::NONE, {0,0}, rect, buttonRect, tex, true, ButtonType::NOT_BUTTON, nullptr, this, false);
	App->gui->CreateElement(id, name, ElementType::BUTTON, action, { 0,0 - buttonRect.h /2 } , buttonRect, buttonRect, tex, true, ButtonType::SLIDER, nullptr, this, true);
	
}


j2SliderGUI::~j2SliderGUI() 
{
}

bool j2SliderGUI::Start()
{
	length = rect.w - children.end->data->InterRect.w;	
	slider_unitVal = float(1000 / length);
	slider_unitVal *= 0.001;
	return true;
}

bool j2SliderGUI::PreUpdate()
{
	
	return true;
}

bool j2SliderGUI::Update()
{
	//If horizontal
	slider_value = slider_unitVal * (children.end->data->GlobalPosition.x - children.start->data->GlobalPosition.x);
	
	//As we needed to do an aproximation of the  slider_unitVal because it can be a really small value we will 
	if (slider_value > 0.98f)
	{
		slider_value = ceil(slider_value);
	}
	//If vertical

	UpdatePos();
	return true;
}

bool j2SliderGUI::PostUpdate()
{
	return true;
}

bool j2SliderGUI::CleanUp()
{
	return true;
}

void j2SliderGUI::UpdatePos()
{
	if (Parent != nullptr) {
		if (dragging)
		{
			position.x = MousePos.x - (LastMousePos.x - Parent->InterRect.x);
			position.y = MousePos.y - (LastMousePos.y - Parent->InterRect.y);
		}
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}
	else
	{
		if (dragging)
		{
			position.x = MousePos.x - (LastMousePos.x - InterRect.x);
			position.y = MousePos.y - (LastMousePos.y - InterRect.y);
		}

		GlobalPosition.x = position.x;
		GlobalPosition.y = position.y;
	}

	InterRect.x = GlobalPosition.x;
	InterRect.y = GlobalPosition.y;
}
