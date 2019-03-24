#ifndef MAINAPP_H
#define MAINAPP_H

// For compilers that don't support precompilation, include "wx/wx.h"
#ifndef WX_PRECOMP
#   include <wx/wxprec.h>
#   include <wx/wx.h>
#endif

class   MainApp
        :   public  wxApp
{
public:

    virtual bool OnInit ();

};

wxDECLARE_APP( MainApp );

#endif  /*< MAINAPP_H */

