#include "GUIText.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "SDL_TTF\include\SDL_ttf.h"
#include "j1Render.h"



GUIText::GUIText(int id, ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, const char*Text, bool draggable) : ElementGUI(id, type, position, rect, isStatic, draggable, tex), Text(Text)
{
	tex = nullptr;
	

}
	


GUIText::~GUIText()
{
}




bool GUIText::Awake() {

	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}



	ColorText.r = 255;
	ColorText.g = 255;
	ColorText.b = 255;
	ColorText.a = 0;

	Textfont = App->font->default;

	tex = App->font->Print(Text, ColorText, Textfont);
	return true;
}
//Start
bool GUIText::Start() {


	return true;
}
//PreUpdate		
bool GUIText::PreUpdate() {

	return true;
}
//Update		
bool GUIText::Update() {
	UpdatePos();
	return true;
}
//PostUpdate	
bool GUIText::PostUpdate() {
	DisplayText();
	return true;
}
//CleanUp
bool GUIText::CleanUp() {

	return true;
}

void GUIText::DisplayText() {
	
	App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y,&rect,isStatic);
}

void GUIText::UpdatePos()
{
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}
}
