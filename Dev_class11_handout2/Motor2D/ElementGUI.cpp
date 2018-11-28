#include "ElementGUI.h"

ElementGUI::ElementGUI(ElementType Element,iPoint position, SDL_Rect rect, bool isStatic, SDL_Texture*tex) : type(Element),position(position), rect(rect), tex(tex), isStatic(isStatic) {


}


ElementGUI::~ElementGUI()
{
}



