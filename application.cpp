#include "application.h"
#include "main.h"

wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame();
	frame->Show(true);
	return true;
}