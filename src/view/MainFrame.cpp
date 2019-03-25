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
#include "NumPadPanel.h"


/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Default constructor.
 */
MainFrame::MainFrame ()
    :   wxFrame (  NULL , wxID_ANY,  "Convertor" )
    ,   m_value( 0 )
{
    this->SetMinSize(wxSize( 500, 200 ) );

    this->_create_ui();
    this->_create_layout();
    this->_create_connections();
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
