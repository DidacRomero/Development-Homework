#include "ElementGUI.h"
#include "j1Render.h"
#include "j1App.h"

ElementGUI::ElementGUI(int id, const char* name, ElementType Element,iPoint position, SDL_Rect rect, bool isStatic, bool interactable, bool draggable, bool invisible, SDL_Texture*tex) : id(id), name(name), type(Element),position(position), rect(rect), tex(tex), isStatic(isStatic), draggable(draggable),invisible(invisible),interactable(interactable) {


}


ElementGUI::~ElementGUI()
{
}

void ElementGUI::debugDraw()
{
	App->render->DrawQuad(InterRect,255,0,0,255,false,false);
}




