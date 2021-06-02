#include "Window.h"
#include "FirstFrame.h"

IMPLEMENT_APP(Window)

bool Window::OnInit()
{
    FirstFrame* MainFrame = new FirstFrame(wxT("Solar Battery"));
    MainFrame->Show(true);

    return true;
}