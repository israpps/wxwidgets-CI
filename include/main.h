#ifndef __MAIN_H__
#define __MAIN_H__

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/string.h>
#include <wx/utils.h> 

class MyFrame : public wxFrame
{
public:
	MyFrame(wxWindow* parent, wxLocale& locale, unsigned long FLG = 0, wxWindowID id = wxID_ANY);
	
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	
public: //vars
	unsigned long flags;
    wxLocale& m_locale;
};

enum FID
{
	Hello = 1
};

#endif //__MAIN_H__

