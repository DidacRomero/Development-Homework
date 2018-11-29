#include "ButtonClass.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"

ButtonClass::ButtonClass(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex) : ElementGUI(type, position, rect, isStatic, tex),id(id) {

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


	return true;
}
//PreUpdate		
bool ButtonClass::PreUpdate() {

	return true;
}
//Update		
bool ButtonClass::Update() {

	App->input->GetMousePosition(MousePos.x, MousePos.y);
	
	
	if (!(MousePos.x < rect.x || MousePos.x >rect.x+rect.w || MousePos.y < rect.y || MousePos.y >rect.y + rect.h))
	{

		hovering = true;


	}
	else
	{
		hovering = false;
		clicked = false;
	}

	if (App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN && hovering) {

		clicked = true;

	

	}
	if (hovering && App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_UP) {

		clicked = false;

	}



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
void ButtonClass::DisplayButton() {

	if(hovering)
	App->render->Blit(tex, position.x, position.y, &hoveringRect, isStatic);
	else if(clicked)
		App->render->Blit(tex, position.x, position.y, &clickedRect, isStatic);
	else
		App->render->Blit(tex, position.x, position.y, &rect, isStatic);

}