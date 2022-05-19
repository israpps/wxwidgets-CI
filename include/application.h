#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <wx/app.h>

class MyApp : public wxApp
{
public:
    MyApp() {m_lang = wxLANGUAGE_UNKNOWN;}
	virtual bool OnInit();
protected:
	wxLanguage m_lang;  // language specified by user
	wxLocale m_locale;  // locale we'll be using
};
