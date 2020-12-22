#include "Display.h"

Display* Display::object = nullptr;

Display* Display::Create() {
    if (object == nullptr) {
        object = new Display();
        return object;
    }
    return object;
}

Display::Display() {}
