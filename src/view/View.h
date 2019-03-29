#ifndef  VIEW_H
#define  VIEW_H

#include <wx/textctrl.h>
#include <sstream>
#include <iostream>


#include "model/Model.h"

using namespace std;
// Model is responsible for data get and set

std::string doubleToString(double);


class View : public wxTextCtrl {
    public:
        using wxTextCtrl::wxTextCtrl;

        
        void setModel(Model* model);
        void render();
    private:
    Model* m_model;
};

#endif  /*< VIEW_H */
