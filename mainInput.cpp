#include <SFML/Window.hpp>

#include "globals.hpp"
#include "mainInput.hpp"

void initWindow(Globals & global) {
    global.window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "Era of Kings II: Empires");
    global.window->SetActive(false);

    // set window icon
    sf::Image windowIcon;
    if(windowIcon.LoadFromFile("assets/ficons-1.1/64x64/helmet.png")) {
        global.window->SetIcon(64, 64, windowIcon.GetPixelsPtr());
    }
    else {
        global.mutex.Lock();
        std::cerr << "Failed to load window icon!" << std::endl;
        global.mutex.Unlock();
    }


    // flag window as open for other threads
    global.windowOpen = true;
}

void mainInput(Globals & global) {
    DEBUG_START_NOTIFY("mainInput")

    initWindow(global);

    sf::Event inputEvent;
    while(global.windowOpen) {
        while(global.window->GetEvent(inputEvent)) {
            if(inputEvent.Type == sf::Event::Closed) {
                global.windowOpen = false;
            }
        }
    }

    DEBUG_END_NOTIFY("mainInput")
}
