#include "View.h"
//#include "model/Pile.h"


void View::setModel(Model* model){
    this->m_model = model;
}

void View::render(){

    std::stringstream ss;
    std::string stringToRender = "";

    std::stack<double> laPile = m_model->operandes()->getClonePile();
    while(!laPile.empty()){
        ss << "[";
        ss << laPile.top();
        laPile.pop();
        ss << "]";
    }
    
    ss << "[";
    ss << this->m_model->currentEntry()->value();
    wxString wxs_value = wxString(ss.str());

    this->ChangeValue(wxs_value);
    
}

std::string doubleToString(double leDouble){

    std::ostringstream strs;
    strs << leDouble;
    return strs.str();
}