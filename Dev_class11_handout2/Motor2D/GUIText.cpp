#include "GUIText.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "SDL_TTF\include\SDL_ttf.h"
#include "j1Render.h"



GUIText::GUIText(ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex) : ElementGUI(type, position, rect,isStatic,tex)
{

	tex = nullptr;
}
	


GUIText::~GUIText()
{
}




bool GUIText::Awake() {

	Text = "hello there,   aaaaaaahhhhh General Kenobiiii";
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
	
	App->render->Blit(tex,position.x,position.y,&rect,isStatic);
}