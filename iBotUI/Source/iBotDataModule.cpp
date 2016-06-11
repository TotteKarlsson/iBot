#pragma hdrstop
#include "iBotDataModule.h"
#include "mtkVCLUtils.h"

using namespace mtk;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma link "DbxDevartSQLite"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TDataModule1::ribbonsCDSnotesGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
//	TField* field = dynamic_cast<TField*>(Sender);
//
//	if(field == ribbonsCDSnotes)
//	{
//		Text = field->AsString;
//	}
}

