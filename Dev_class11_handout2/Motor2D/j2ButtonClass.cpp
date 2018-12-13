#include "j2ButtonClass.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Scene.h"

j2ButtonClass::j2ButtonClass(int id, const char* name, ElementType type, ElementAction action, ButtonType buttonType, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable, bool interactable, bool invisible)
	: ElementGUI(id, name, type, action, position, rect, isStatic, interactable, draggable,  invisible, tex), bType(buttonType) {

	hoveringRect={646,170,226,64};
	 clickedRect = {416,170,226,64 };

}


j2ButtonClass::~j2ButtonClass()
{
}


bool j2ButtonClass::Awake() {

	
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
		
		InterRect.x=GlobalPosition.x;
		InterRect.y = GlobalPosition.y;
		InterRect.w = rect.w;
		InterRect.h = rect.h;

	}

	if (draggable)
	{
		switch (bType)
		{
		case ButtonType::DEFAULT:
			draggable_x = true;
			draggable_y = true;
			break;
		case ButtonType::SLIDER:
			draggable_x = true;
			draggable_y = false;
			break;
		}
	}


	return true;
}

//Start
bool j2ButtonClass::Start() {
	
	was_hovered = false;
	was_clicked = false;

	return true;
}

//PreUpdate		
bool j2ButtonClass::PreUpdate() {

	return true;
}

//Update		
bool j2ButtonClass::Update() {
	
	UpdatePos();

	return true;
}

//PostUpdate	
bool j2ButtonClass::PostUpdate() {
	DisplayButton();
	return true;
}

//CleanUp
bool j2ButtonClass::CleanUp() {

	return true;
}

void j2ButtonClass::DisplayButton()
{
	 if(clicked)
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &clickedRect, isStatic);
	else if (hovering)
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &hoveringRect, isStatic);
	else
		App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y, &rect, isStatic);
}

bool j2ButtonClass::InteractionUpdate()
{
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

	return true;
}

void j2ButtonClass::UpdatePos()
{
	if (Parent != nullptr) {
		if (dragging)
		{
			if (draggable_x)
			position.x = MousePos.x - (LastMousePos.x - (InterRect.x - Parent->InterRect.x));
			
			if (draggable_y)
			position.y = MousePos.y - (LastMousePos.y - (InterRect.y - Parent->InterRect.y));
		}
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}
	else
	{
		if (dragging)
		{
			if(draggable_x)
			position.x = MousePos.x - (LastMousePos.x - InterRect.x);
			
			if(draggable_y)
			position.y = MousePos.y - (LastMousePos.y - InterRect.y);
		}

		GlobalPosition.x = position.x;
		GlobalPosition.y = position.y;

	}

	if (bType == ButtonType::SLIDER && Parent != nullptr)
	{
		if (GlobalPosition.x + InterRect.w > Parent->GlobalPosition.x + Parent->rect.w)
			GlobalPosition.x = Parent->GlobalPosition.x + Parent->rect.w -InterRect.w;

		if (GlobalPosition.x < Parent->GlobalPosition.x)
			GlobalPosition.x = Parent->GlobalPosition.x;
		
	}

	InterRect.x = GlobalPosition.x;
	InterRect.y = GlobalPosition.y;
}
