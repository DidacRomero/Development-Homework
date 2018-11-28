#include "GUIText.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "SDL_TTF\include\SDL_ttf.h"



GUIText::GUIText() : ElementGUI(type, position, rect, tex) 
{

	tex = nullptr;
}
	


GUIText::~GUIText()
{
}




bool GUIText::Awake() {

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

	return true;
}
//CleanUp
bool GUIText::CleanUp() {

	return true;
}

void GUIText::DisplayText() {

	App->font->Print(Text,ColorText,Textfont);
	

}