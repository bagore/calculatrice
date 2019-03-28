/* Corresponding header inclusion */
#include "MemoryPanel.h"

/* System includes */
#include <string>

/* Libraries includes */
#include <wx/log.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/tooltip.h>

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

    this->_create_button( C_LABEL_MEMORY_ADD ).get()
            ->SetToolTip( new wxToolTip( "Memory Add" ) );

    this->_create_button( C_LABEL_MEMORY_CLEAR ).get()
            ->SetToolTip( new wxToolTip( "Memory Clear" ) );

    this->_create_button( C_LABEL_MEMORY_RECALL ).get()
            ->SetToolTip( new wxToolTip( "Memory Recall" ) );
}

/* ########################################################################## */
/* ########################################################################## */

std::shared_ptr<wxButton>
        MemoryPanel::_create_button( const std::string    &argText )
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

    return p_button;
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


    if( p_button->GetLabel() == C_LABEL_MEMORY_ADD )
    {
        lEvent.setEventType( MemoryPanelEvent::EEventMemAdd );
    }
    else if( p_button->GetLabel() == C_LABEL_MEMORY_CLEAR )
    {
        lEvent.setEventType( MemoryPanelEvent::EEventMemClear );
    }
    else if( p_button->GetLabel() == C_LABEL_MEMORY_RECALL )
    {
        lEvent.setEventType( MemoryPanelEvent::EEventMemRecall );
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

IMPLEMENT_DYNAMIC_CLASS( MemoryPanelEvent, wxCommandEvent )

DEFINE_EVENT_TYPE( MYEVT_MEMORYPANELEVENT )

MemoryPanelEvent::MemoryPanelEvent(wxWindow *argWindow)
    :   m_eventType( EEventUnknown )
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

MemoryPanelEvent::TeEventType    MemoryPanelEvent::eventType(void) const
{
    return this->m_eventType;
}

/* ########################################################################## */
/* ########################################################################## */

void    MemoryPanelEvent::setEventType(const TeEventType &argEvent)
{
    this->m_eventType   = argEvent;
}

/* ########################################################################## */
/* ########################################################################## */

