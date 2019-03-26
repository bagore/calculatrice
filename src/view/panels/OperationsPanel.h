#ifndef OPERATIONSPANEL_H
#define OPERATIONSPANEL_H

/* Inherited classes */
#include <wx/panel.h>

/* System includes */
#include <memory>
#include <vector>

/* Libraries includes */
#include <wx/button.h>

/* Project includes */


/*
 *  Forward declarations
 */
class   wxGridSizer;


/* ########################################################################## */
/* ########################################################################## */

class   OperationsPanel
        :   public  wxPanel
{
public:

    OperationsPanel(int argID, wxPanel* argParent);



protected:

    void    _create_button(const std::string   &argText);



private:

    void    on_m_buttons_clicked(wxCommandEvent& argEvent);



public:
protected:
private:

    std::vector< std::shared_ptr<wxButton> >    m_buttonsList;
    wxGridSizer*                                m_layoutMainPtr;


};

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Define a new event type.
 *
 *  @see https://docs.wxwidgets.org/3.1.0/overview_events.html#overview_events_custom
 */
class   OperationsPanelEvent
        :   public      wxCommandEvent
{
    DECLARE_DYNAMIC_CLASS( OperationsPanelEvent )

public:

    OperationsPanelEvent( wxWindow  *argWindow = (wxWindow*) NULL );


    /* Mandatory method */
    virtual wxEvent *Clone() const;


    // accessors
    char    operation(void) const;
    void    setOperation(const char &argOperation);



private:

    char    m_operation;


};


typedef void (wxEvtHandler::*operationsPanelEventFunction)(OperationsPanelEvent&);


BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( MYEVT_OPERATIONSPANELEVENT, 1 )
END_DECLARE_EVENT_TYPES()


#define EVT_OPERATIONSPANELEVENT(func)                      \
    DECLARE_EVENT_TABLE_ENTRY( MYEVT_OPERATIONSPANELEVENT,  \
        -1,                                    \
        -1,                                    \
        (wxObjectEventFunction)                \
        (myEventFunction) & func,              \
        (wxObject *) NULL ),

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< OPERATIONSPANEL_H */
