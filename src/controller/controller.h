#ifndef  CONTROLLER_H
#define  CONTROLLER_H
/**
 *  @file   controller.h
 *  @brief  
 */

#include "model/model.h"
#include "view/MainFrame.h"
 
// Controller combines Model and View

// TODO : ADD VIEW
class Controller {
    public:
        Controller(Model* model, MainFrame* view);
        void SetModel(Model* model);
        void SetView(MainFrame* view);
        // when application starts
        void OnLoad();
        void TestEvent();
    private:
        Model* model;
        MainFrame* view;
};

#endif  /*< CONTROLLER_H */
