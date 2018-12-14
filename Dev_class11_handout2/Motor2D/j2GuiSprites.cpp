#include "j2GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Textures.h"


j2GuiSprites::j2GuiSprites(const char* name, ElementType type, ElementAction action, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable, bool interactuable,bool invisible) 
	: ElementGUI(name, type, action, position, rect, isStatic, draggable, interactuable, invisible, tex){


}


j2GuiSprites::~j2GuiSprites()
{
}



bool j2GuiSprites::Awake() {

	
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
bool j2GuiSprites::Start() {


	return true;
}
//PreUpdate		
bool j2GuiSprites::PreUpdate() {

	return true;
}
//Update		
bool j2GuiSprites::Update() {
	LastMousePos = MousePos;
	App->input->GetMousePosition(MousePos.x, MousePos.y);

	UpdatePos();

	return true;
}
//PostUpdate	
bool j2GuiSprites::PostUpdate() {
	DisplaySprite();
	return true;
}


bool j2GuiSprites::InteractionUpdate()
{
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

	return true;
}

void j2GuiSprites::UpdatePos()
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



void j2GuiSprites::DisplaySprite() {


	App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y,&rect,isStatic);

}