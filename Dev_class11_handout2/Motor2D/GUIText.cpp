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


void GUIText::DisplayText() {

	App->font->Print(Text,ColorText,Textfont);
	

}