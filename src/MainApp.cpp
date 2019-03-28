// For compilers that don't support precompilation, include "wx/wx.h"
#ifndef WX_PRECOMP
#   include <wx/wxprec.h>
#   include <wx/wx.h>
#endif

#include "MainApp.h"
#include "view/MainFrame.h"

wxDECLARE_APP(MainApp);

bool MainApp::OnInit ()
{
    MainFrame *p_frame = new MainFrame();
    p_frame->Show( true );

    p_frame->setText( "Hello, World !" );

    return true;
}
