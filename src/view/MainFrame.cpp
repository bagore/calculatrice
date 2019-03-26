/* Corresponding header inclusion */
#include  "MainFrame.h"

/* System includes */

/* Libraries includes */
#ifndef  WX_PRECOMP
#   include  <wx/wxprec.h>
#   include  <wx/wx.h>
#endif

#include <wx/valnum.h>

/* Project includes */
#include "EWidgetsIdentifiers.h"
#include "traces.h"

using namespace view;

/* ########################################################################## */
/* ########################################################################## */

#define TRACE_DBG(format,...) \
        TRACE_DBG_BASE( "view", format, ##__VA_ARGS__ );

#define TRACE_ERR(format,...) \
        TRACE_ERR_BASE( "view", format, ##__VA_ARGS__ );

/* ########################################################################## */
/* ########################################################################## */

BEGIN_EVENT_TABLE( MainFrame, wxFrame )
    EVT_NUMPADPANELEVENT( MainFrame::on_numPadPanel_panelEvent )
    EVT_OPERATIONSPANELEVENT( MainFrame::on_operationsPanel_panelEvent )
END_EVENT_TABLE()

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Default constructor.
 */
MainFrame::MainFrame ()
    :   wxFrame (  NULL , wxID_ANY,  "Bagore's Calculator" )
    ,   m_value( 0 )
{
    this->SetMinSize(wxSize( 500, 200 ) );

    this->_create_ui();
    this->_create_layout();
    this->_create_connections();

    this->m_textControlPtr.get()->SetEditable( false );
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Convenience method to declare callbacks.
 *
 *  @warning    Shall only be called once (in the constructor).
 */
void    MainFrame::_create_connections(void)
{
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Convenience method to create UI's layout.
 *
 *  @warning    Shall only be called once (in the constructor).
 */
void    MainFrame::_create_layout()
{
    wxSizer *p_sizerText    = new wxBoxSizer( wxHORIZONTAL );
    p_sizerText->Add( 25, 0, 0 );
    p_sizerText->Add( this->m_textControlPtr.get(),
                      100 );/*,
                      wxEXPAND,
                      5 );*/
    p_sizerText->Add( 25, 0, 0 );

    wxSizer *p_sizerInputs  = new wxBoxSizer( wxHORIZONTAL );
    p_sizerInputs->Add( this->m_numPadPanelPtr.get(), 1, wxEXPAND );
    p_sizerInputs->Add( this->m_operationsPanelPtr.get(), 1, wxEXPAND );


    wxSizer *p_sizerMain    = new wxBoxSizer( wxVERTICAL );

    p_sizerMain->Add( 0, 25, 100 );
    p_sizerMain->Add( p_sizerText, 0, wxEXPAND, 0 );
    p_sizerMain->Add( 0, 25, 100 );
    p_sizerMain->Add( p_sizerInputs, 1, wxEXPAND, 0 );
    p_sizerMain->Add( 0, 25, 100 );

    m_panelPtr->SetSizer( p_sizerMain );
    m_panelPtr->GetSizer()->Fit(this->m_panelPtr.get());
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Convenience function to instanciate the User Interface.
 *
 *  @warning    Shall only be called once (in the constructor).
 */
void    MainFrame::_create_ui(void)
{
    /* The panel shall be created first as it is used as a parent by other
     * widgets. */
    this->m_panelPtr
            = std::make_unique<wxPanel>(this, wxID_ANY);


    this->m_numPadPanelPtr
            = std::make_unique<NumPadPanel>( ID_NumPad,
                                             this->m_panelPtr.get() );

    this->m_operationsPanelPtr
            = std::make_unique<OperationsPanel>( ID_OperationsPanel,
                                                 this->m_panelPtr.get() );

    this->m_textControlPtr
            = std::make_unique<wxTextCtrl>( this->m_panelPtr.get(),
                                            ID_TextControl,
                                            wxEmptyString,
                                            wxDefaultPosition,
                                            wxDefaultSize,
                                            wxTE_RIGHT,
                                            wxMakeFloatingPointValidator
                                            (
                                                2,
                                                &this->m_value,
                                                wxNUM_VAL_THOUSANDS_SEPARATOR |
                                                wxNUM_VAL_NO_TRAILING_ZEROES
                                            ) );
}

/* ########################################################################## */
/* ########################################################################## */


void MainFrame::on_numPadPanel_panelEvent(NumPadPanelEvent &argEvent)
{
    if( argEvent.hasCommand() )
    {
        TRACE_DBG( "Receiving command %d",
                   (int)argEvent.command() );
    }
    else if( argEvent.hasValue() )
    {
        TRACE_DBG( "Receiving value %d.",
                   argEvent.value() );
    }
    else
    {
        throw   std::logic_error( std::string(__PRETTY_FUNCTION__)
                                  + "Can't determine event type!" );
    }
}

/* ########################################################################## */
/* ########################################################################## */


void MainFrame::on_operationsPanel_panelEvent(OperationsPanelEvent &argEvent)
{
    if( argEvent.operation() == '?' )
    {
        throw   std::logic_error( std::string(__PRETTY_FUNCTION__)
                                  + "Invalid operation!" );
    }
    else
    {
        TRACE_DBG( "Receiving operation %c",
                   argEvent.operation() );
    }
}

/* ########################################################################## */
/* ########################################################################## */
