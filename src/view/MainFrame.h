#ifndef  MAINFRAME_H
#define  MAINFRAME_H

/* Inherited classes */
#include <wx/frame.h>

/* System includes */
#include <memory>
#include <string>

/* Libraries includes */
#include <wx/panel.h>
#include <wx/textctrl.h>

/* Project includes*/
#include "panels/MemoryPanel.h"
#include "panels/NumPadPanel.h"
#include "panels/OperationsPanel.h"
#include "model/Model.h"
#include "view/View.h"

/* ########################################################################## */
/* ########################################################################## */

class   MainFrame
        :   public      wxFrame
{
public:

    MainFrame();
    void SetModel(Model* model);

    void    setText(const std::string& pText);



protected:

    void    on_memoryPanel_panelEvent(MemoryPanelEvent& argEvent);
    void    on_numPadPanel_panelEvent(NumPadPanelEvent& argEvent);
    void    on_operationsPanel_panelEvent(OperationsPanelEvent& argEvent);


private:

    void    _create_ui(void);
    void    _create_layout(void);
    void    _create_connections(void);

public:
protected:
private:

    /** @brief  The panel containing everything. */
    std::unique_ptr<wxPanel>    m_panelPtr;

    std::unique_ptr<MemoryPanel>        m_memoryPanelPtr;
    std::unique_ptr<NumPadPanel>        m_numPadPanelPtr;
    std::unique_ptr<OperationsPanel>    m_operationsPanelPtr;

    View*                       m_view;

    float                       m_value;

    Model*                      m_model;

    DECLARE_EVENT_TABLE()
};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINFRAME_H */
