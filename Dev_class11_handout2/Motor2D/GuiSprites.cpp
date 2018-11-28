#include "GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"


GuiSprites::GuiSprites(ElementType type, iPoint position, SDL_Rect &rect, SDL_Texture* tex) : ElementGUI(type,position, rect,tex){


}


GuiSprites::~GuiSprites()
{
}



bool GuiSprites::Awake() {

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

	return true;
}
//CleanUp
bool GuiSprites::CleanUp() {

	return true;
}



void GuiSprites::DisplaySprite() {


	App->render->Blit(tex, position.x, position.y,&rect);

}