#include "SqlLiteLoader.h"



SqlLiteLoader::SqlLiteLoader():openFlag(false){
	try {
		if (QSqlDatabase::contains("sqliteConn")) {
			this->db = QSqlDatabase::database("sqliteConn");
		}else {
			//�����ֶ�������ݿ����������򱨴�
			QSqlDatabase::drivers();
			this->db = QSqlDatabase::addDatabase("QSQLITE", "sqliteConn");
			this->db.setDatabaseName(QCoreApplication::applicationDirPath()+"/qtrequire/required/facerenzheng.db");
			if (!db.open()) {
				openFlag = false;
			}else {
				openFlag = true;
			}
		}

	}catch (const std::exception &e){
		openFlag = false;
	}


}


SqlLiteLoader::~SqlLiteLoader()
{
	if (db.open()) {
		db.close();
		//db.~QSqlDatabase();
	}
}
