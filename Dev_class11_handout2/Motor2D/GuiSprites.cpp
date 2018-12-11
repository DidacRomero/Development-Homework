#include "GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"


GuiSprites::GuiSprites(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable) : ElementGUI(id,type,position, rect, isStatic, draggable, tex){


}


GuiSprites::~GuiSprites()
{
}



bool GuiSprites::Awake() {

	
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}
	else
	{
		GlobalPosition.x = position.x;
		GlobalPosition.y = position.y;
	}
	InterRect.x = GlobalPosition.x;
	InterRect.y = GlobalPosition.y;
	InterRect.w = rect.w;
	InterRect.h = rect.h;


	return true;
}
//Start
bool GuiSprites::Start() {


	return true;
}
//PreUpdate		
bool GuiSprites::PreUpdate() {

	return true;
}
//Update		
bool GuiSprites::Update() {
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
			if (draggable)
			{
				dragging = true;
			}
		}
		if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP)
		{
			clicked = false;
		}

		//Once we know everything that is happening (and we are interacting with the button 
		//(hovering is necessary for any other action on the button)) we can pass that info to the modules
		App->UiElementCallback(this);
	}

	if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP && dragging == true)
	{
		dragging = false;
	}

	UpdatePos();

	return true;
}
//PostUpdate	
bool GuiSprites::PostUpdate() {
	DisplaySprite();
	return true;
}
//CleanUp
bool GuiSprites::CleanUp() {

	return true;
}

void GuiSprites::UpdatePos()
{
		if (Parent != nullptr) {
			GlobalPosition.x = Parent->GlobalPosition.x + position.x;
			GlobalPosition.y = Parent->GlobalPosition.y + position.y;

			InterRect.x = GlobalPosition.x;
			InterRect.y = GlobalPosition.y;
			InterRect.w = rect.w;
			InterRect.h = rect.h;
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

			InterRect.x = GlobalPosition.x;
			InterRect.y = GlobalPosition.y;
			InterRect.w = rect.w;
			InterRect.h = rect.h;
		}
}



void GuiSprites::DisplaySprite() {


	App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y,&rect,isStatic);

}