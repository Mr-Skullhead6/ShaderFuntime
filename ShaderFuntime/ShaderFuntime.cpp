// ShaderFuntime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Qt\qapplication.h>
#include <MeGlWindow.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MeGlWindow meWindow;
	meWindow.show();
	return app.exec();
}