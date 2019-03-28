/**
 *  @file   controller.cpp
 *  @brief  
 */

#include <iostream>
#include "Controller.h"

Controller::Controller(Model* model, MainFrame* view) {
          this->SetModel(model);
          this->SetView(view);        
}

void Controller::SetModel(Model* model) {
    this->model = model;
}

void Controller::SetView(MainFrame* view) {
    this->view = view;
}

// when application starts
void Controller::OnLoad() {
    //this->view.Render();
}

void Controller::TestEvent(){
    cout << "Tu avais envie de voir ça..." << endl;
}