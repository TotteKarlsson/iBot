#include <System.hpp>
#pragma hdrstop
USEFORM("Source\Forms\TamFileEditor.cpp", amFileEditor);
USEFORM("Source\Forms\TShowFileContentForm.cpp", ShowFileContentForm);
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Package source.
//---------------------------------------------------------------------------


#pragma argsused
extern "C" int _libmain(unsigned long reason)
{
    return 1;
}

//---------------------------------------------------------------------------

#pragma comment(lib, "mtkCommon.lib")
#pragma comment(lib, "mtkDataBase.lib")
#pragma comment(lib, "poco_foundation-static.lib")
#pragma comment(lib, "iBotCore-static.lib")


#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneComponents.bpi")
#pragma comment(lib, "vcl.bpi")

