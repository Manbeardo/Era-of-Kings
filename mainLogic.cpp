#include <cstdio>

#include "globals.hpp"
#include "mainLogic.hpp"

void updateFramesString(Globals & global) {
    static int oldFPS = 0;
    global.mutex.Lock();
    if(global.FPS != oldFPS) {
        static char str[20];
        sprintf(str, "FPS: %d", global.FPS);
        global.FPSString.SetText(str);
        oldFPS = global.FPS;
    }
    global.mutex.Unlock();
}

void mainLogic(Globals & global) {
    DEBUG_START_NOTIFY("mainLogic")

    while(global.windowOpen) {
        updateFramesString(global);
    }

    DEBUG_END_NOTIFY("mainLogic")
}
