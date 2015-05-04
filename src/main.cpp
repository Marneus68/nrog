#include <iostream>


#include "Application.h"

int main(int argc, const char *argv[])
{
    rog::Application app;
    app.run();
    /*
    sm::Machine * m = new sm::Machine();
    m->changeState(new sm::IdleState(m));
    m->saySomething();
    */

    return 0;
}
