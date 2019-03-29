#include "View.h"
//#include "model/Pile.h"


void View::setModel(Model* model){
    this->m_model = model;
}

void View::render(){

    std::stringstream ss;
    std::string stringToRender = "";
    std::string lValueString    = "";

    std::stack<double> laPile = m_model->operandes()->getClonePile();
    while(!laPile.empty()){
        lValueString    = "[";
        ss.str("");
        ss << laPile.top();
        lValueString   += ss.str();
        lValueString   += "]";
        
        stringToRender = lValueString + stringToRender;
        /*
        ss << "[";
        ss << laPile.top();*/
        laPile.pop();
       // ss << "]";
    }
    
   // ss << "[";
    stringToRender += "[";
    stringToRender += std::to_string(this->m_model->currentEntry()->value());
    wxString wxs_value = wxString(stringToRender);

    this->ChangeValue(wxs_value);
    
}

std::string doubleToString(double leDouble){

    std::ostringstream strs;
    strs << leDouble;
    return strs.str();
}