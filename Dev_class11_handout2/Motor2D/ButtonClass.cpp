#include "ButtonClass.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Scene.h"

ButtonClass::ButtonClass(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable) : ElementGUI(id,type, position, rect, isStatic, draggable, tex) {

	hoveringRect={646,170,226,64};
	 clickedRect = {416,170,226,64 };

}


ButtonClass::~ButtonClass()
{
}




bool ButtonClass::Awake() {

	
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
		
		InterRect.x=GlobalPosition.x;
		InterRect.y = GlobalPosition.y;
		InterRect.w = rect.w;
		InterRect.h = rect.h;

	}


	return true;
}
//Start
bool ButtonClass::Start() {
	
	was_hovered = false;
	was_clicked = false;

	return true;
}
//PreUpdate		
bool ButtonClass::PreUpdate() {

	return true;
}
//Update		
bool ButtonClass::Update() {
	LastMousePos = MousePos;
	App->input->GetMousePosition(MousePos.x, MousePos.y);

	if (hovering != was_hovered)
	{
		was_hovered = hovering;
	}

	if (clicked != was_clicked)
	{
		was_clicked = clicked;
	}

	if (!(MousePos.x < InterRect.x || MousePos.x >InterRect.x + InterRect.w || MousePos.y < InterRect.y || MousePos.y >InterRect.y + InterRect.h))
	{
		hovering = true;
	}
	else
	{
		hovering = false;
		clicked = false;
	}

	if (hovering)
	{
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
		{
			clicked = true;

		}
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP)
		{
			clicked = false;
		}

		if (App->input->GetMouseButtonDown(SDL_BUTTON_RIGHT) == KEY_DOWN)
		{
			if (draggable)
			{
				dragging = true;
			}
		}

		//Once we know everything that is happening (and we are interacting with the button 
		//(hovering is necessary for any other action on the button)) we can pass that info to the modules
		App->UiElementCallback(this);
	}

	if (App->input->GetMouseButtonDown(SDL_BUTTON_RIGHT) == KEY_UP && dragging == true)
	{
		dragging = false;
	}

	if (hovering || clicked || dragging)
	{
		being_used = true;
	}
	else
	{
		being_used = false;
	}
	UpdatePos();

	return true;
}
//PostUpdate	
bool ButtonClass::PostUpdate() {
	DisplayButton();
	return true;
}
//CleanUp
bool ButtonClass::CleanUp() {

	return true;
}
void ButtonClass::DisplayButton() 
{
	 if(clicked)
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &clickedRect, isStatic);
	else if (hovering)
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &hoveringRect, isStatic);
	else
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &rect, isStatic);
}

void ButtonClass::UpdatePos()
{
	if (Parent != nullptr) {
		if (dragging)
		{
			position.x = MousePos.x - (LastMousePos.x - (InterRect.x - Parent->InterRect.x));
			position.y = MousePos.y - (LastMousePos.y - (InterRect.y - Parent->InterRect.y));
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
	InterRect.w = rect.w;
	InterRect.h = rect.h;
}
