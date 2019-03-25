/* Corresponding header inclusion */
#include "NumPadPanel.h"

/* System includes */

/* Libraries includes */
#include <wx/sizer.h>
#include <wx/stattext.h>

/* Project includes */


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

    argLayout->Add( p_button.get(), 0, wxEXPAND );
    this->m_buttonsList.push_back( p_button );
}

/* ########################################################################## */
/* ########################################################################## */

void    NumPadPanel::_create_uiAndLayout(void)
{
    wxGridSizer*    p_layoutMain    = new wxGridSizer( 4, 3,
                                                       3, 3 );

    this->_create_buttonNum( p_layoutMain, 7 );
    this->_create_buttonNum( p_layoutMain, 8 );
    this->_create_buttonNum( p_layoutMain, 9 );
    this->_create_buttonNum( p_layoutMain, 4 );
    this->_create_buttonNum( p_layoutMain, 5 );
    this->_create_buttonNum( p_layoutMain, 6 );
    this->_create_buttonNum( p_layoutMain, 1 );
    this->_create_buttonNum( p_layoutMain, 2 );
    this->_create_buttonNum( p_layoutMain, 3 );
    p_layoutMain->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
    this->_create_buttonNum( p_layoutMain, 0 );

    this->SetSizer( p_layoutMain );
    this->SetMinSize(wxSize(400, 300));
}

/* ########################################################################## */
/* ########################################################################## */
