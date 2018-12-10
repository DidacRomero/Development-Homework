#include "GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"


GuiSprites::GuiSprites(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex) : ElementGUI(id,type,position, rect, isStatic,tex ){


}


GuiSprites::~GuiSprites()
{
}



bool GuiSprites::Awake() {

	
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->position.x + position.x;
		GlobalPosition.y = Parent->position.y + position.y;
	}


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



void GuiSprites::DisplaySprite() {


	App->render->Blit(tex, position.x, position.y,&rect,isStatic);

}