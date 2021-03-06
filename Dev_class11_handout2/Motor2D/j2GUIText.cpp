#include "j2GUIText.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "SDL_TTF\include\SDL_ttf.h"
#include "j1Render.h"



j2GUIText::j2GUIText(const char* name, ElementType type, ElementAction action, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, const char*Text, bool draggable, bool interactuable, bool invisible) 
	: ElementGUI(name, type, action, position, rect, isStatic, draggable, interactuable, invisible, tex), Text(Text)
{
	tex = nullptr;
}
	


j2GUIText::~j2GUIText()
{
}




bool j2GUIText::Awake() {
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}
	else
	{
		GlobalPosition.x = position.x;
		GlobalPosition.y = position.y;
	}

	if (Parent != nullptr)
	{
		Parent->children.add(this);
	}

	InterRect.w = rect.w;
	InterRect.h = rect.h;

	ColorText.r = 255;
	ColorText.g = 255;
	ColorText.b = 255;
	ColorText.a = 0;

	Textfont = App->font->default;

	tex = App->font->Print(Text, ColorText, Textfont);
	return true;
}
//Start
bool j2GUIText::Start() {
	was_hovered = false;
	was_clicked = false;
	clicked = false;
	hovering = false;
	dragging = false;

	return true;
}
//PreUpdate		
bool j2GUIText::PreUpdate() {

	return true;
}
//Update		
bool j2GUIText::Update() {
	UpdatePos();
	return true;
}
//PostUpdate	
bool j2GUIText::PostUpdate() {
	DisplayText();
	return true;
}


void j2GUIText::DisplayText() {
	
	App->render->Blit(tex, GlobalPosition.x, GlobalPosition.y,&rect,isStatic);
}


void j2GUIText::UpdatePos()
{
	if (Parent != nullptr) {
		GlobalPosition.x = Parent->GlobalPosition.x + position.x;
		GlobalPosition.y = Parent->GlobalPosition.y + position.y;
	}

	InterRect.x = GlobalPosition.x;
	InterRect.y = GlobalPosition.y;
}
