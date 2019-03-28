#ifndef  VIEW_H
#define  VIEW_H

#include <wx/textctrl.h>

#include "model/Model.h"

using namespace std;
// Model is responsible for data get and set


class View : public wxTextCtrl {
    public:
        using wxTextCtrl::wxTextCtrl;

        
        void setModel(Model* model);
        void setAffichage(double valeur);
    private:
    Model* m_model;
};

#endif  /*< VIEW_H */
