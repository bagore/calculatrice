/* Corresponding header inclusion */
#include "MemoryPanel.h"

/* System includes */
#include <string>

/* Libraries includes */
#include <wx/log.h>
#include <wx/sizer.h>
#include <wx/stattext.h>

/* Project includes */
#include "traces.h"

/* ########################################################################## */
/* ########################################################################## */

#define TRACE_DBG(format,...) \
        TRACE_DBG_BASE( "view", format, ##__VA_ARGS__ );

#define TRACE_ERR(format,...) \
        TRACE_ERR_BASE( "view", format, ##__VA_ARGS__ );

/* ########################################################################## */
/* ########################################################################## */

static const std::string    C_LABEL_MEMORY_ADD( "MEM+" );
static const std::string    C_LABEL_MEMORY_RECALL( "MR" );
static const std::string    C_LABEL_MEMORY_CLEAR( "MC" );

/* ########################################################################## */
/* ########################################################################## */

MemoryPanel::MemoryPanel(int argID, wxPanel *argParent)
    :   wxPanel( argParent,
                 argID,
                 wxDefaultPosition,
                 wxSize( -1, 30 ),
                 wxBORDER_DEFAULT )
    ,   m_layoutMainPtr( new wxGridSizer( 4, 0,
                                       3, 3 ) )
{
    this->SetSizer( this->m_layoutMainPtr );

    this->m_layoutMainPtr->Add( new wxStaticText(this, wxID_ANY, "Memory"),
                                0,
                                wxSHRINK|wxALIGN_CENTER );

    this->_create_button( C_LABEL_MEMORY_ADD );
    this->_create_button( C_LABEL_MEMORY_CLEAR );
    this->_create_button( C_LABEL_MEMORY_RECALL );
}

/* ########################################################################## */
/* ########################################################################## */

void    MemoryPanel::_create_button( const std::string    &argText )
{
    std::shared_ptr<wxButton>   p_button
            = std::make_shared<wxButton>( this,
                                          wxID_ANY,
                                          argText );

    p_button.get()->SetMinSize( C_BUTTONS_DEFAULTSIZE );
    p_button.get()->SetMaxSize( C_BUTTONS_DEFAULTSIZE );


    if(     (   this->m_layoutMainPtr->GetItemCount()
            %   this->m_layoutMainPtr->GetRows() )
        ==  0 )
    {
        this->m_layoutMainPtr->SetCols( this->m_layoutMainPtr->GetCols() + 1 );
    }
    this->m_layoutMainPtr->Add( p_button.get(), 0, wxSHRINK|wxALIGN_CENTER );


    p_button->Connect(
                wxEVT_COMMAND_BUTTON_CLICKED,
                wxCommandEventHandler(
                    MemoryPanel::on_m_buttons_clicked ) );


    this->m_buttonsList.push_back( p_button );
}

/* ########################################################################## */
/* ########################################################################## */

void    MemoryPanel::on_m_buttons_clicked(wxCommandEvent &argEvent)
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
    MemoryPanelEvent lEvent( this );

#if 0
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
#elif 0
    char lChar  = '\0';
    p_button->GetLabel().at( 0 ).GetAsChar( &lChar );

    lEvent.setOperation( lChar );
#else
    TRACE_ERR( "Unimplemented method !" )
#endif

    if ( ProcessEvent( lEvent ) == false )
    {
        wxLogWarning( _("Could not process event!") );
    }
}

/* ########################################################################## */
/* ########################################################################## */

IMPLEMENT_DYNAMIC_CLASS( MemoryPanelEvent, wxCommandEvent )

DEFINE_EVENT_TYPE( MYEVT_MEMORYPANELEVENT )

MemoryPanelEvent::MemoryPanelEvent(wxWindow *argWindow)
    :   m_operation( '?' )
{
    SetEventType( MYEVT_MEMORYPANELEVENT );
    SetEventObject( argWindow );
}

/* ########################################################################## */
/* ########################################################################## */

wxEvent*    MemoryPanelEvent::Clone(void) const
{
    return new MemoryPanelEvent(*this);
}

/* ########################################################################## */
/* ########################################################################## */

char    MemoryPanelEvent::operation(void) const
{
    return this->m_operation;
}

/* ########################################################################## */
/* ########################################################################## */

void    MemoryPanelEvent::setOperation(const char &argOperation)
{
    this->m_operation   = argOperation;
}

/* ########################################################################## */
/* ########################################################################## */

