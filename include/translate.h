#ifndef LOCALE_TABLE_H_INCLUDED
#define LOCALE_TABLE_H_INCLUDED

#include <wx/string.h>
#include <wx/language.h>
#include <wx/debug.h>
#include <wx/defs.h>

enum LANG_NUMS
{
    AUTO_DETECT = 0,
    ENGLISH,
    SPANISH,

    TOTAL_COUNT
};

static const wxLanguage langIds[] =
{
    wxLANGUAGE_DEFAULT,
    wxLANGUAGE_ENGLISH_US,
    wxLANGUAGE_SPANISH,
};

const wxString langNames[] =
{
    "System default",
    "English",
    "Spanish",
};

// the arrays must be in sync
wxCOMPILE_TIME_ASSERT( WXSIZEOF(langNames) == WXSIZEOF(langIds),
                       LangArraysMismatch );
wxCOMPILE_TIME_ASSERT( WXSIZEOF(langNames) == LANG_NUMS::TOTAL_COUNT,
                       LangArraysMismatch );


#endif // LOCALE_TABLE_H_INCLUDED