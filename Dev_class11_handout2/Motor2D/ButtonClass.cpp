#include "ButtonClass.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Scene.h"

ButtonClass::ButtonClass(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex) : ElementGUI(id,type, position, rect, isStatic, tex) {

	hoveringRect={646,170,226,64};
	 clickedRect = {416,170,226,64 };

}


ButtonClass::~ButtonClass()
{
}




bool ButtonClass::Awake() {

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

	return true;
}
//PostUpdate	
bool ButtonClass::PostUpdate() {
	
	App->input->GetMousePosition(MousePos.x, MousePos.y);

	if (hovering != was_hovered)
	{
		was_hovered = hovering;
	}
	
	if (clicked != was_clicked)
	{
		was_clicked = clicked;
	}
	
	if (!(MousePos.x < position.x || MousePos.x > position.x+rect.w || MousePos.y < position.y || MousePos.y >position.y + rect.h))
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

		//Once we know everything that is happening (and we are interacting with the button 
		//(hovering is necessary for any other action on the button)) we can pass that info to the modules
			App->UiElementCallback(this);
	}
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
		App->render->Blit(tex, position.x, position.y, &clickedRect, isStatic);
	else if (hovering)
		App->render->Blit(tex, position.x, position.y, &hoveringRect, isStatic);
	else
		App->render->Blit(tex, position.x, position.y, &rect, isStatic);
}