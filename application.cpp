#include "application.h"
#include "main.h"

wxIMPLEMENT_APP(MyApp);


bool MyApp::OnInit()
{
	/**************[LNG INIT]**************/
	
    wxFileName fname( wxTheApp->argv[0] );
    wxString config_file = fname.GetPath(wxPATH_GET_VOLUME|wxPATH_GET_SEPARATOR) + "Common\\config.INI";
    wxFileConfig * main_config = new wxFileConfig( wxEmptyString, wxEmptyString, config_file);
	if (m_lang == wxLANGUAGE_UNKNOWN)
    {
        int lng;
        main_config->Read("Init/language", &lng, 0);
        m_lang = lng == -1 ? wxLANGUAGE_DEFAULT : langIds[lng];
        std::cout <<"Loading lang ID ["<< lng <<"]\n";
    }
    if ( !m_locale.Init(m_lang, wxLOCALE_DONT_LOAD_DEFAULT) )
        wxLogWarning(_("This language is not supported by the system."));
    ///-lang init
    ///catalog init and search:
    wxLocale::AddCatalogLookupPathPrefix("./Lang");
    const wxLanguageInfo* pInfo = wxLocale::GetLanguageInfo(m_lang);
    if (!m_locale.AddCatalog("HDLBinst"))///add program specific catalog
    {
        COLOR(0c)
        std::cout << wxString::Format(_("Couldn't find/load the 'HDLBinst' catalog for locale '%s'.\nThe translation file must be placed here: \"Lang\\%s\\HDLBinst.mo\"\n"),
                   pInfo ? pInfo->GetLocaleName() : _("unknown"),
                   m_locale.GetCanonicalName());
        COLOR(07)
    }
    if (!m_locale.AddCatalog("wxstd"))///add wxwidgets standard catalog
        std::cerr << "can't find wxstd.mo\n";
	/**************[LNG INIT]**************/
	MyFrame *frame = new MyFrame(0, m_locale);
	frame->Show(true);
	return true;
}