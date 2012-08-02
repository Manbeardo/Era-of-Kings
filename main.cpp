#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>

#include "globals.hpp"
#include "mainRender.hpp"
#include "mainLogic.hpp"
#include "mainInput.hpp"

Globals global;

void inputThreadFunc(void * userData) {
    mainInput(global);
}

void renderThreadFunc(void * userData) {
    mainRender(global);
}

void logicThreadFunc(void * userData) {
    mainLogic(global);
}

int main()
{
    sf::Thread inputThread(&inputThreadFunc);
    sf::Thread renderThread(&renderThreadFunc);
    sf::Thread logicThread(&logicThreadFunc);

    inputThread.Launch();
    // wait for input thread to create window
    while(!global.windowOpen);
    renderThread.Launch();
    logicThread.Launch();

    inputThread.Wait();
    renderThread.Wait();
    logicThread.Wait();

    global.window->Close();
    delete global.window;

    return EXIT_SUCCESS;
}
