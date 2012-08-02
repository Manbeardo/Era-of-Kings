#include <SFML/System.hpp>

#include "globals.hpp"
#include "mainRender.hpp"

void mainRender(Globals & global) {
    DEBUG_START_NOTIFY("mainRender")

    sf::Clock secondClock;
    int frames = 0;
    while(global.windowOpen) {
        global.window->Clear();
        global.window->Draw(global.FPSString);
        global.window->Display();
        frames++;
        if(secondClock.GetElapsedTime() >= 1.0f) {
            global.FPS = frames;
            frames = 0;
            secondClock.Reset();
        }
    }

    DEBUG_END_NOTIFY("mainRender")
}
