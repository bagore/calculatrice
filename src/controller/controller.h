/**
 *  @file   controller.h
 *  @brief  
 */

#include "model/model.h"
 
// Controller combines Model and View

// TODO : ADD VIEW
class Controller {
    public:
        Controller(const Model &model/*, const View &view*/);
        void SetModel(const Model &model);
        void SetView(/*const View &view*/);
        // when application starts
        void OnLoad();
    private:
        Model model;
        //View view;
};