#pragma once
#ifndef FACEREG_COMMONUTIL_H
#define FACEREG_COMMONUTIL_H
#include <iostream>
#include <QString>
#include <QtCore/QStringList>
#include <QDir>
#include <QDebug>

namespace timeFormat {
	static QString formatTime(QString source) {
		QString year = "";
		QString month = "";
		QString day = "";
		QString result = "";
		if (source.contains(" ")) {
			source = source.split(" ")[0];
		}
		QStringList sources = source.split("-");
		if (sources.length()>0) {
			year = sources[0];
			if (sources.length()>1) {
				month = sources[1];
				if (month[0] == '0') {
					month = month[1] + "";
				}
				if (sources.length()>2) {
					day = sources[2];
					if (day[0] == '0') {
						day = day[1] + "";
					}

				}

			}


		}

		result.append(year);
		if (month != "") {
			result.append("-");
			result.append(month);
			if (day != "") {
				result.append("-");
				result.append(day);
			}

		}
		return result;

	}

}

namespace stringUtil {

	static QString getFormatStr(const QString &str) {

		if (str == "«Î—°‘Ò" || str == NULL || str.trimmed() == "") {

			return  "";
		}
		else {
			return  str.trimmed();

		}

	}
}

namespace DeleteDirAndFile {
	static bool delDirAndFile(const QString &path) {
		if (path.isNull() || path.isEmpty()) {
			return false;
		}
		QDir dir(path);
		if (!dir.exists()) {
			return true;
		}

		dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
		QFileInfoList infoList = dir.entryInfoList();
		for (QFileInfo fi : infoList) {
			if (fi.isFile()) {
				fi.dir().remove(fi.fileName());
			}
			else {
				delDirAndFile(fi.absoluteFilePath());
			}

		}
	}

}

#endif // !FACEREG_COMMONUTIL_H
