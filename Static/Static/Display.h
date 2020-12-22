#pragma once
//Pattern Singleton
class Display {
private:
    Display();
    static Display* object;
public:
    static Display* Create();

};
