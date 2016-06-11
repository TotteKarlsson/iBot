//---------------------------------------------------------------------------

#ifndef iBotDataModuleH
#define iBotDataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "DbxDevartSQLite.hpp"
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLDataSet *ribbonsDS;
	TDataSetProvider *ribbonsProvider;
	TClientDataSet *ribbonsCDS;
	TDataSource *ribbonsDSource;
	TIntegerField *ribbonsCDSid;
	TIntegerField *ribbonsCDSstatus;
	TSQLTimeStampField *ribbonsCDScreated;
	TSQLTimeStampField *ribbonsCDSmodified;
	TIntegerField *ribbonsCDSblock_id;
	TIntegerField *ribbonsCDSorder;
	TWideMemoField *ribbonsCDSnotes;
	void __fastcall ribbonsCDSnotesGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
