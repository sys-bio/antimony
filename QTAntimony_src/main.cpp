#include <cstdio>
#include <QApplication>
#include <QString>
#include <QRegExp>
#include "Translator.h"
#include "QTAntimony.h"

#include <cstdio>

//void myMessageOutput(QtMsgType type, const char *msg)
//{
//	switch (type) {
//	 case QtDebugMsg:
//#ifndef NDEBUG
//		 fprintf(stderr, "Debug: %s\n", msg);
//#endif
//		 break;
//	 case QtWarningMsg:
//#ifndef NDEBUG
//		 fprintf(stderr, "Warning: %s\n", msg);
//#endif
//		 break;
//	 case QtCriticalMsg:
//		 fprintf(stderr, "Critical error from QT: %s\n", msg);
//		 break;
//	 case QtFatalMsg:
//		 fprintf(stderr, "Fatal error from QT: %s\n", msg);
//		 abort();
//	}
//}

void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	QByteArray localMsg = msg.toLocal8Bit();
	const char* file = context.file ? context.file : "";
	const char* function = context.function ? context.function : "";
	switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
		break;
	case QtInfoMsg:
		fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
		break;
	case QtWarningMsg:
		fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
		break;
	case QtFatalMsg:
		fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
		break;
	}
}

int main(int argc, char* argv[])
{
	qInstallMessageHandler(myMessageOutput);
	QTAntimony a(argc, argv);
	if (argc == 1) {
		a.NewWindow();
	}
	else {
		a.NewWindow(argv[1]);
	}

	return a.exec();
}
