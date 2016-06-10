#include <System.hpp>
#pragma hdrstop
USEFORM("Source\Forms\TShowFileContentForm.cpp", ShowFileContentForm);
USEFORM("Source\Forms\TGoodbyeForm.cpp", GoodbyeForm);
USEFORM("Source\Frames\TAboutAmalyticoFrame.cpp", AboutAmalyticoFrame); /* TFrame: File Type */
USEFORM("Source\Forms\TamFileEditor.cpp", amFileEditor);
USEFORM("Source\Forms\TAboutAmalyticoForm.cpp", AboutAmalyticoForm);
USEFORM("Source\Forms\TValidateSerialKeyForm.cpp", ValidateSerialKeyForm);
USEFORM("Source\Frames\TEnterSerialKeyFrame.cpp", EnterSerialKeyFrame); /* TFrame: File Type */
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
#pragma comment(lib, "amalyticoCore-static.lib")


#pragma comment(lib, "VCLCommon.bpi")
#pragma comment(lib, "DuneComponents.bpi")
#pragma comment(lib, "vcl.bpi")
#pragma comment(lib, "CSKGenerator.bpi")

