#ifndef  MAINFRAME_H
#define  MAINFRAME_H

/* Inherited classes */
#include <wx/frame.h>

/* System includes */
#include <memory>

/* Libraries includes */
#include <wx/panel.h>
#include <wx/textctrl.h>

/* Project includes*/
#include "NumPadPanel.h"

/* ########################################################################## */
/* ########################################################################## */

class   MainFrame
        :   public      wxFrame
{
public:

    MainFrame();



protected:

    void    on_numPadPanel_panelEvent(NumPadPanelEvent& argEvent);


private:

    void    _create_ui(void);
    void    _create_layout(void);
    void    _create_connections(void);



public:
protected:
private:

    /** @brief  The panel containing everything. */
    std::unique_ptr<wxPanel>    m_panelPtr;

    std::unique_ptr<NumPadPanel>    m_numPadPanelPtr;
    std::unique_ptr<wxTextCtrl>     m_textControlPtr;

    float                       m_value;


    DECLARE_EVENT_TABLE()
};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MAINFRAME_H */
