#ifndef MEMORYPANEL_H
#define MEMORYPANEL_H

/* Inherited classes */
#include <wx/panel.h>

/* System includes */
#include <memory>
#include <vector>

/* Libraries includes */
#include <wx/button.h>

/* Project includes */
#include "view/view_constants.h"
using namespace view;


/*
 *  Forward declarations
 */
class   wxGridSizer;


/* ########################################################################## */
/* ########################################################################## */

class   MemoryPanel
        :   public  wxPanel
{
public:

    MemoryPanel(int argID, wxPanel* argParent);



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
class   MemoryPanelEvent
        :   public      wxCommandEvent
{
    DECLARE_DYNAMIC_CLASS( MemoryPanelEvent )

public:

    typedef enum
    {
        EEventUnknown   = -1,
        EEventMemClear  = 0,
        EEventMemAdd,
        EEventMemRecall
    }   TeEventType;


    MemoryPanelEvent( wxWindow  *argWindow = (wxWindow*) NULL );


    /* Mandatory method */
    virtual wxEvent *Clone() const;


    // accessors
    TeEventType  eventType(void) const;
    void        setEventType(const TeEventType &argEvent);



private:

    TeEventType  m_eventType;


};


typedef void (wxEvtHandler::*memoryPanelEventFunction)(MemoryPanelEvent&);


BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( MYEVT_MEMORYPANELEVENT, 1 )
END_DECLARE_EVENT_TYPES()


#define EVT_MEMORYPANELEVENT(func)                      \
    DECLARE_EVENT_TABLE_ENTRY( MYEVT_MEMORYPANELEVENT,  \
        -1,                                    \
        -1,                                    \
        (wxObjectEventFunction)                \
        (myEventFunction) & func,              \
        (wxObject *) NULL ),

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< MEMORYPANEL_H */
