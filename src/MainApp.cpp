// For compilers that don't support precompilation, include "wx/wx.h"
#ifndef WX_PRECOMP
#   include <wx/wxprec.h>
#   include <wx/wx.h>
#endif

#include "MainApp.h"

wxDECLARE_APP(MainApp);

bool MainApp::OnInit ()
{
    Model* p_model = new Model(0);

    MainFrame *p_frame = new MainFrame();
    p_frame->SetModel(p_model);
    p_frame->Show( true );

    return true;
}
