#include <vcl.h>
#pragma hdrstop
#include "TMemoLogger.h"
#include "TMainForm.h"
#include "mtkVCLUtils.h"
#include "Poco/Glob.h"
#include "mtkMoleculixException.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "mtkStringUtils.h"
#include "mtkSQLiteQuery.h"
#include "mtkLogger.h"
#include "mtkSQLiteTable.h"
#include "mtkSQLiteException.h"
#include "TShowFileContentForm.h"
#include "TSplashForm.h"
#include "TamFileEditor.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Timezone.h"
#include "iBotDataModule.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "mtkIniFileC"
#pragma link "TIntegerLabeledEdit"
#pragma resource "*.dfm"

TMainForm *MainForm;
using namespace mtk;
using namespace Poco;

extern string gLogFileName;
extern string gApplicationRegistryRoot;
extern string gDefaultAppTheme;
extern bool gIsDevelopmentRelease;
extern TSplashForm*  gSplashForm;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TRegistryForm(gApplicationRegistryRoot, "MainForm", Owner),

//    mDBConnectionName("amalytico"),
    mBottomPanelHeight(205),
    mMainTabIndex(0),
    mSplashProperties(gApplicationRegistryRoot, "Splash"),
    mShowSplashOnStartup(true),
    mLogLevel(lAny),
    mIsStyleMenuPopulated(false),
    gCanClose(true),
    logMsgMethod(&logMsg),
    mLogFileReader(joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), "iBot", gLogFileName), logMsgMethod)
{
    //Close any dataconnection created by stupid TSQLConnection
    mTempFileFolder = joinPath(getSpecialFolder(CSIDL_LOCAL_APPDATA), "iBot");
    TMemoLogger::mMemoIsEnabled = false;

    setupIniFile();
    setupAndReadIniParameters();
}

//This one is called from the reader thread
void __fastcall TMainForm::logMsg()
{
    infoMemo->Lines->Add(vclstr(mLogFileReader.getData()));
    mLogFileReader.purge();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::LogLevelCBChange(TObject *Sender)
{
    if(LogLevelCB->ItemIndex == 0)
    {
        mLogLevel = lInfo;
    }
    else if(LogLevelCB->ItemIndex == 1)
    {
        mLogLevel = lAny;
    }

    gLogger.setLogLevel(mLogLevel);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::AppInBox(mlxStructMessage &msg)
{
    if(msg.lparam == NULL)
    {
        return;
    }

    try
    {
        ApplicationMessageEnum aMsg = msg.lparam->mMessageEnum;

        switch(aMsg)
        {
            case amSplashWasClosed:
                Log(lDebug2) << "Splash form sent message that it was closed";
                gSplashForm = NULL;
            break;



            default:
            break ;
        }
	}
	catch(...)
	{
		Log(lError) << "Received an unhandled windows message!";
	}
}

void __fastcall TMainForm::MainPCChange(TObject *Sender)
{
    //Check what tb is open
}


void __fastcall TMainForm::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
//	if(Column->FieldName == "notes")
//    {
////	    //Column->Field->AsString;
//	 	DBGrid1->Canvas->FillRect(Rect);
//     	DBGrid1->Canvas->TextOut(Rect.Left + 3, Rect.Top + 3,
//              Column->Field->AsString);
//    }
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::DBLookupComboBox5CloseUp(TObject *Sender)
{
	//Fill out the slots drop downs
	String blockId = mBlocksCB->Text;
    if(blockId.Length())
    {
    	//Query db for ribbons
        TSQLQuery* q = new TSQLQuery(NULL);
        q->SQLConnection = atDM->SQLConnection1;
    	stringstream qs;
    	qs << "SELECT * from ribbon where block_id = "<<stdstr(atDM->blocksCDS->FieldByName("id")->AsString);
        string qstr = qs.str();
        q->SQL->Add(qstr.c_str());
        q->Open();

        clearSlots();
        //Get records and populate slots
        for(int i = 0; i < q->RecordCount; i++)
        {
			string ribbonID = stdstr(q->FieldByName("id")->AsString);
        	Log(lInfo) << ribbonID;
			addItemToSlots(ribbonID, NULL);
            q->Next();
        }
        q->Close();
    }
}

//---------------------------------------------------------------------------
void TMainForm::clearSlots()
{
	mCBSlot1->Clear();
	mCBSlot2->Clear();
	mCBSlot3->Clear();
	mCBSlot4->Clear();
}

void TMainForm::addItemToSlots(const string& id, TObject* o)
{
	mCBSlot1->Items->AddObject(vclstr(id), o);
	mCBSlot2->Items->AddObject(vclstr(id), o);
	mCBSlot3->Items->AddObject(vclstr(id), o);
	mCBSlot4->Items->AddObject(vclstr(id), o);

}

