/* Corresponding header inclusion */
#include "NumPadPanel.h"

/* System includes */

/* Libraries includes */
#include <wx/log.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

/* Project includes */
#include "traces.h"
#include "view/view_constants.h"
using namespace view;

/* ########################################################################## */
/* ########################################################################## */

#define TRACE_DBG(format,...) \
        TRACE_DBG_BASE( "view", format, ##__VA_ARGS__ );

#define TRACE_ERR(format,...) \
        TRACE_ERR_BASE( "view", format, ##__VA_ARGS__ );

/* ########################################################################## */
/* ########################################################################## */

static const std::string    C_LABEL_COMMA( "," );
static const std::string    C_LABEL_ENTER( "Enter" );

/* ########################################################################## */
/* ########################################################################## */

NumPadPanel::NumPadPanel(int argID, wxPanel *argParent)
    :   wxPanel( argParent,
                 argID,
                 wxDefaultPosition,
                 wxSize( -1, 30 ),
                 wxBORDER_DEFAULT )
{
    this->_create_uiAndLayout();
    this->_create_connections();
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::_create_buttonNum(wxGridSizer *argLayout, int argValue)
{
    std::shared_ptr<wxButton>   p_button
            = std::make_shared<wxButton>( this,
                                          wxID_ANY,
                                          std::to_string( argValue ),
                                          wxPoint(20, 20) );


    argLayout->Add( p_button.get(), 0, wxSHRINK|wxALIGN_CENTER );

    p_button.get()->SetMinSize( C_BUTTONS_DEFAULTSIZE );
    p_button.get()->SetMaxSize( C_BUTTONS_DEFAULTSIZE );

    p_button->Connect(
                wxEVT_COMMAND_BUTTON_CLICKED,
                wxCommandEventHandler( NumPadPanel::on_buttonNum_clicked ) );


    this->m_buttonsNumList.push_back( p_button );
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::_create_connections(void)
{
    this->m_buttonCmdComma.get()
            ->Connect(
                wxEVT_COMMAND_BUTTON_CLICKED,
                wxCommandEventHandler( NumPadPanel::on_buttonCmd_clicked ) );

    this->m_buttonCmdEnter.get()
            ->Connect(
                wxEVT_COMMAND_BUTTON_CLICKED,
                wxCommandEventHandler( NumPadPanel::on_buttonCmd_clicked ) );
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::_create_uiAndLayout(void)
{
    this->m_buttonCmdComma
            = std::make_shared<wxButton>( this,
                                          wxID_ANY,
                                          C_LABEL_COMMA );
    this->m_buttonCmdComma.get()->SetMinSize( C_BUTTONS_DEFAULTSIZE );
    this->m_buttonCmdComma.get()->SetMaxSize( C_BUTTONS_DEFAULTSIZE );


    this->m_buttonCmdEnter
            = std::make_shared<wxButton>( this,
                                          wxID_ANY,
                                          C_LABEL_ENTER );
    this->m_buttonCmdEnter.get()->SetMinSize( C_BUTTONS_DEFAULTSIZE );
    this->m_buttonCmdEnter.get()->SetMaxSize( C_BUTTONS_DEFAULTSIZE );

    wxGridSizer*    p_layoutMain    = new wxGridSizer( 4, 3,
                                                       10, 10 );

    this->_create_buttonNum( p_layoutMain, 7 );
    this->_create_buttonNum( p_layoutMain, 8 );
    this->_create_buttonNum( p_layoutMain, 9 );
    this->_create_buttonNum( p_layoutMain, 4 );
    this->_create_buttonNum( p_layoutMain, 5 );
    this->_create_buttonNum( p_layoutMain, 6 );
    this->_create_buttonNum( p_layoutMain, 1 );
    this->_create_buttonNum( p_layoutMain, 2 );
    this->_create_buttonNum( p_layoutMain, 3 );
    p_layoutMain->Add(this->m_buttonCmdComma.get(), 0, wxSHRINK|wxALIGN_CENTER);
    this->_create_buttonNum( p_layoutMain, 0 );
    p_layoutMain->Add(this->m_buttonCmdEnter.get(), 0, wxSHRINK|wxALIGN_CENTER);

    this->SetSizer( p_layoutMain );
    this->SetMinSize(wxSize(400, 300));
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::on_buttonCmd_clicked(wxCommandEvent &argEvent)
{
    /*
     * Cast the event emiter as a wxButton.
     * The cast shall not fail.
     * If it does fail, then it means we fucked up implementation of this class.
     * So just throw an exception.
     */
    wxButton*   p_button
            = wxDynamicCast( argEvent.GetEventObject(), wxButton );

    if( p_button == NULL )
    {
        throw std::logic_error( std::string( __PRETTY_FUNCTION__ )
                                + "::Event not coming from a wxButton !" );
    }


    /*
     *  Generate a custom event to propagate the num pad selected button.
     */
    NumPadPanelEvent lEvent( this );

    if( p_button->GetLabel() == C_LABEL_COMMA )
    {
        TRACE_DBG( "Command button 'Comma' pressed." );
        lEvent.setCommand( NumPadPanelEvent::CmdComma );
    }
    else if( p_button->GetLabel() == C_LABEL_ENTER )
    {
        TRACE_DBG( "Command button 'Enter' pressed." );
        lEvent.setCommand( NumPadPanelEvent::CmdEnter );
    }
    else
    {
        throw std::logic_error( std::string( __PRETTY_FUNCTION__ )
                                + "::Event coming from an unknown button!" );
    }

    if ( ProcessEvent( lEvent ) == false )
    {
        wxLogWarning( _("Could not process event!") );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::on_buttonNum_clicked(wxCommandEvent &argEvent)
{
    /*
     * Cast the event emiter as a wxButton.
     * The cast shall not fail.
     * If it does fail, then it means we fucked up implementation of this class.
     * So just throw an exception.
     */
    wxButton*   p_button
            = wxDynamicCast( argEvent.GetEventObject(), wxButton );

    if( p_button == NULL )
    {
        throw std::logic_error( std::string( __PRETTY_FUNCTION__ )
                                + "::Event not coming from a wxButton !" );
    }


    /*
     *  Generate a custom event to propagate the num pad selected button.
     */
    NumPadPanelEvent lEvent( this );
    lEvent.setValue( atoi( p_button->GetLabel().c_str().AsChar() ) );

    if ( ProcessEvent( lEvent ) == false )
    {
        wxLogWarning( _("Could not process event!") );
    }
}

/* ########################################################################## */
/* ########################################################################## */

IMPLEMENT_DYNAMIC_CLASS( NumPadPanelEvent, wxCommandEvent )

DEFINE_EVENT_TYPE( myEVT_NUMPADPANELEVENT )

NumPadPanelEvent::NumPadPanelEvent(wxWindow    *argWindow)
    :   m_command( Cmd_Invalid )
    ,   m_value( INT_MIN )
{
    SetEventType( myEVT_NUMPADPANELEVENT );
    SetEventObject( argWindow );
}

/* ########################################################################## */
/* ########################################################################## */

wxEvent*    NumPadPanelEvent::Clone(void) const
{
    return new NumPadPanelEvent(*this);
}

/* ########################################################################## */
/* ########################################################################## */

NumPadPanelEvent::TeNumPadPanelCmd  NumPadPanelEvent::command(void) const
{
    return this->m_command;
}

/* ########################################################################## */
/* ########################################################################## */

bool    NumPadPanelEvent::hasCommand(void) const
{
    return (this->m_command != Cmd_Invalid );
}

/* ########################################################################## */
/* ########################################################################## */

bool    NumPadPanelEvent::hasValue(void) const
{
    return (this->m_value != INT_MIN );
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanelEvent::setCommand(const TeNumPadPanelCmd &argCmd)
{
    this->m_command = argCmd;
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanelEvent::setValue(const int &argValue)
{
    this->m_value   = argValue;
}

/* ########################################################################## */
/* ########################################################################## */

int NumPadPanelEvent::value(void) const
{
    return this->m_value;
}

/* ########################################################################## */
/* ########################################################################## */
