#include "Displayable.hpp"

Displayable::Displayable()
{
    //ctor
}

Displayable::~Displayable()
{
    //dtor
}

unsigned int Displayable::GetLayer() {
    return myLayer;
}

void Displayable::SetLayer(unsigned int val) {
    myLayer = val;
}

sf::Drawable Displayable::GetDrawable() {
    return myDrawable;
}

void Displayable::SetDrawable(sf::Drawable val) {
    myDrawable = val;
}

