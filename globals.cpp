#include <iostream>

#include "globals.hpp"

Globals::Globals()
:
    windowOpen(false),
    FPS(0),
    window(NULL)
{
    if(!arial.LoadFromFile("assets/arial.ttf")) {
        std::cerr << "couldn't load arial.ttf!" << std::endl;
    }

    FPSString.SetFont(arial);
    FPSString.SetSize(30);
    FPSString.SetColor(sf::Color::White);
    FPSString.SetPosition(20, 20);
}
