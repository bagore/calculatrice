/**
 *  @file   controller.cpp
 *  @brief  
 */

#include "controller.h"

Controller::Controller(const Model &model/*, const View &view*/) {
          this->SetModel(model);
          //this->SetView(view);        
        }

void Controller::SetModel(const Model &model) {
    this->model = model;
}

void Controller::SetView(/*const View &view*/) {
    //this->view = view;
}

// when application starts
void Controller::OnLoad() {
    //this->view.Render();
}