#ifndef NUMPADPANEL_H
#define NUMPADPANEL_H

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

class   NumPadPanel
        :   public  wxPanel
{
public:

    NumPadPanel(int argID, wxPanel* argParent);



protected:
private:

    void    _create_buttonNum( wxGridSizer* argLayout, int argValue );

    void    _create_uiAndLayout(void);
    void    _create_connections(void);


    void    on_buttonCmd_clicked(wxCommandEvent& argEvent);
    void    on_buttonNum_clicked(wxCommandEvent& argEvent);



public:
protected:
private:

    std::shared_ptr<wxButton>                   m_buttonCmdComma;
    std::shared_ptr<wxButton>                   m_buttonCmdEnter;
    std::vector< std::shared_ptr<wxButton> >    m_buttonsNumList;

};

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Define a new event type.
 *
 *  @see https://docs.wxwidgets.org/3.1.0/overview_events.html#overview_events_custom
 */
class   NumPadPanelEvent
        :   public      wxCommandEvent
{
    DECLARE_DYNAMIC_CLASS( NumPadPanelEvent )

public:

    typedef enum    ENumPadPanelCmd
    {
        Cmd_Invalid = -1,

        CmdComma,
        CmdEnter
    }   TeNumPadPanelCmd;


    NumPadPanelEvent( wxWindow  *argWindow = (wxWindow*) NULL );


    /* Mandatory method */
    virtual wxEvent *Clone() const;


    // accessors
    bool    hasValue(void) const;
    int     value(void) const;
    void    setValue(const int &argValue);


    bool                hasCommand(void) const;
    TeNumPadPanelCmd    command(void) const;
    void                setCommand(const TeNumPadPanelCmd &argCmd);



private:

    TeNumPadPanelCmd    m_command;
    int                 m_value;

};


typedef void (wxEvtHandler::*myEventFunction)(NumPadPanelEvent&);


BEGIN_DECLARE_EVENT_TYPES()
    DECLARE_EVENT_TYPE( myEVT_NUMPADPANELEVENT, 1 )
END_DECLARE_EVENT_TYPES()


#define EVT_MYEVENT(func)                               \
    DECLARE_EVENT_TABLE_ENTRY( myEVT_NUMPADPANELEVENT,  \
        -1,                                    \
        -1,                                    \
        (wxObjectEventFunction)                \
        (myEventFunction) & func,              \
        (wxObject *) NULL ),

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< NUMPADPANEL_H */
