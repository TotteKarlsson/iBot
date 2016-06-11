object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 405
  Width = 647
  object SQLConnection1: TSQLConnection
    ConnectionName = 'ATDebug'
    DriverName = 'DevartSQLite'
    LoginPrompt = False
    Params.Strings = (
      'DriverName=DevartSQLite'
      'DriverUnit=DbxDevartSQLite'
      
        'DriverPackageLoader=TDBXDynalinkDriverLoader,DBXCommonDriver170.' +
        'bpl'
      
        'MetaDataPackageLoader=TDBXDevartSQLiteMetaDataCommandFactory,Dbx' +
        'DevartSQLiteDriver170.bpl'
      'ProductName=DevartSQLite'
      'LibraryName=dbexpsqlite40.dll'
      'VendorLib=sqlite3.dll'
      'Database=p:\iBot\db\ATdatabase.db'
      'LocaleCode=0000'
      'IsolationLevel=ReadCommitted'
      'ASCIIDataBase=False'
      'BusyTimeout=0'
      'EnableSharedCache=False'
      'MaxBlobSize=-1'
      'FetchAll=True'
      'ForceCreateDatabase=False'
      'ForeignKeys=True'
      'UseUnicode=True'
      'EnableLoadExtension=False'
      'BlobSize=-1')
    Connected = True
    Left = 48
    Top = 40
  end
  object ribbonsDS: TSQLDataSet
    CommandText = 'select * from ribbon'
    DataSource = ribbonsDSource
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 48
    Top = 112
  end
  object ribbonsProvider: TDataSetProvider
    DataSet = ribbonsDS
    Options = [poFetchBlobsOnDemand, poUseQuoteChar]
    Left = 144
    Top = 112
  end
  object ribbonsCDS: TClientDataSet
    Active = True
    Aggregates = <>
    Params = <>
    ProviderName = 'ribbonsProvider'
    Left = 248
    Top = 112
    object ribbonsCDSid: TIntegerField
      FieldName = 'id'
    end
    object ribbonsCDSstatus: TIntegerField
      FieldName = 'status'
    end
    object ribbonsCDScreated: TSQLTimeStampField
      FieldName = 'created'
    end
    object ribbonsCDSmodified: TSQLTimeStampField
      FieldName = 'modified'
    end
    object ribbonsCDSblock_id: TIntegerField
      FieldName = 'block_id'
    end
    object ribbonsCDSorder: TIntegerField
      FieldName = 'order'
    end
    object ribbonsCDSnotes: TWideMemoField
      FieldName = 'notes'
      OnGetText = ribbonsCDSnotesGetText
      BlobType = ftWideMemo
    end
  end
  object ribbonsDSource: TDataSource
    DataSet = ribbonsCDS
    Left = 344
    Top = 112
  end
end
