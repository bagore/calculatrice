#ifndef NUMPADPANEL_H
#define NUMPADPANEL_H

/* Inherited classes */
#include <wx/panel.h>

/* System includes */
#include <list>
#include <memory>

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



public:
protected:
private:

    std::list< std::shared_ptr<wxButton> >  m_buttonsList;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< NUMPADPANEL_H */
