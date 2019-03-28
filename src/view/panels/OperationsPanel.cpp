/* Corresponding header inclusion */
#include "OperationsPanel.h"

/* System includes */
#include <string>

/* Libraries includes */
#include <wx/log.h>
#include <wx/sizer.h>

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

static const std::string    C_LABEL_OPERATION_ADD( "+" );
static const std::string    C_LABEL_OPERATION_DIVIDE( "/" );
static const std::string    C_LABEL_OPERATION_MULTIPLY( "x" );
static const std::string    C_LABEL_OPERATION_SUBSTRACT( "-" );

/* ########################################################################## */
/* ########################################################################## */

OperationsPanel::OperationsPanel(int argID, wxPanel *argParent)
    :   wxPanel( argParent,
                 argID,
                 wxDefaultPosition,
                 wxSize( -1, 30 ),
                 wxBORDER_DEFAULT )
    ,   m_layoutMainPtr( new wxGridSizer( 4, 0,
                                       3, 3 ) )
{
    this->SetSizer( this->m_layoutMainPtr );

    this->_create_button( C_LABEL_OPERATION_ADD );
    this->_create_button( C_LABEL_OPERATION_SUBSTRACT );
    this->_create_button( C_LABEL_OPERATION_MULTIPLY );
    this->_create_button( C_LABEL_OPERATION_DIVIDE );
}

/* ########################################################################## */
/* ########################################################################## */

void    OperationsPanel::_create_button( const std::string    &argText )
{
    std::shared_ptr<wxButton>   p_button
            = std::make_shared<wxButton>( this,
                                          wxID_ANY,
                                          argText );

    p_button.get()->SetMinSize( C_BUTTONS_DEFAULTSIZE );
    p_button.get()->SetMaxSize( C_BUTTONS_DEFAULTSIZE );
    p_button.get()->SetBackgroundColour(wxColour( "cyan" ) );
    p_button.get()->SetForegroundColour( C_BUTTONS_COLOR_FOREGROUND );
    p_button.get()->SetFont( C_BUTTONS_FONT_DEFAULT );


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
                    OperationsPanel::on_m_buttons_clicked ) );


    this->m_buttonsList.push_back( p_button );
}

/* ########################################################################## */
/* ########################################################################## */

void    OperationsPanel::on_m_buttons_clicked(wxCommandEvent &argEvent)
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
    OperationsPanelEvent lEvent( this );

    char lChar  = '\0';
    p_button->GetLabel().at( 0 ).GetAsChar( &lChar );

    lEvent.setOperation( lChar );

    if ( ProcessEvent( lEvent ) == false )
    {
        wxLogWarning( _("Could not process event!") );
    }
}

/* ########################################################################## */
/* ########################################################################## */

IMPLEMENT_DYNAMIC_CLASS( OperationsPanelEvent, wxCommandEvent )

DEFINE_EVENT_TYPE( MYEVT_OPERATIONSPANELEVENT )

OperationsPanelEvent::OperationsPanelEvent(wxWindow *argWindow)
    :   m_operation( '?' )
{
    SetEventType( MYEVT_OPERATIONSPANELEVENT );
    SetEventObject( argWindow );
}

/* ########################################################################## */
/* ########################################################################## */

wxEvent*    OperationsPanelEvent::Clone(void) const
{
    return new OperationsPanelEvent(*this);
}

/* ########################################################################## */
/* ########################################################################## */

char    OperationsPanelEvent::operation(void) const
{
    return this->m_operation;
}

/* ########################################################################## */
/* ########################################################################## */

void    OperationsPanelEvent::setOperation(const char &argOperation)
{
    this->m_operation   = argOperation;
}

/* ########################################################################## */
/* ########################################################################## */

