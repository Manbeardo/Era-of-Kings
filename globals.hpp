#ifndef GLOBALS_HPP_INCLUDED
#define GLOBALS_HPP_INCLUDED

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

struct Globals {
    bool windowOpen;
    int FPS;
    sf::Mutex mutex;
    sf::RenderWindow * window;
    sf::Font arial;
    sf::String FPSString;

    Globals();
};

#ifdef DEBUG
    #define DEBUG_START_NOTIFY(_name_) \
        global.mutex.Lock(); \
        std::cout << _name_ << " started!" << std::endl; \
        global.mutex.Unlock();

    #define DEBUG_END_NOTIFY(_name_) \
        global.mutex.Lock(); \
        std::cout << _name_ << " ended!" << std::endl; \
        global.mutex.Unlock();
#else
    #define DEBUG_START_NOTIFY(_name_)
    #define DEBUG_END_NOTIFY(_name_)
#endif // DEBUG

#endif // GLOBALS_HPP_INCLUDED
