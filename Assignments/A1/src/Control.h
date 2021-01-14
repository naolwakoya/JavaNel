#ifndef CONTROL_H
#define CONTROL_H

using namespace std;

#include "UI.h"

class Control {

    public:
        Control();
        ~Control();
        void launch();
        
    private:
        UI ui;

};

#endif