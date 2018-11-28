#include "ElementGUI.h"

ElementGUI::ElementGUI(ElementType Element,iPoint position, SDL_Rect rect, SDL_Texture*tex) : type(Element),position(position), rect(rect), tex(tex) {


}


ElementGUI::~ElementGUI()
{
}



