#include "ElementGUI.h"

ElementGUI::ElementGUI(int id,ElementType Element,iPoint position, SDL_Rect rect, bool isStatic, bool draggable, SDL_Texture*tex) : id(id),type(Element),position(position), rect(rect), tex(tex), isStatic(isStatic), draggable(draggable) {


}


ElementGUI::~ElementGUI()
{
}




