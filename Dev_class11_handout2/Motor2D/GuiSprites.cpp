#include "GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"


GuiSprites::GuiSprites() : ElementGUI(type,position, rect,tex){


}


GuiSprites::~GuiSprites()
{
}



bool GuiSprites::Awake() {


}
//Start
bool GuiSprites::Start() {

}
//PreUpdate		
bool GuiSprites::PreUpdate() {


}
//Update		
bool GuiSprites::Update() {


}
//PostUpdate	
bool GuiSprites::PostUpdate() {


}
//CleanUp
bool GuiSprites::CleanUp() {


}



void GuiSprites::DisplaySprite() {


	App->render->Blit(tex, position.x, position.y,&rect);

}