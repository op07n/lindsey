#include "app_engine.hpp"
#include <QtWidgets/QApplication>
#include <QtWebEngine/qtwebengineglobal.h>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QtWebEngine::initialize();

    ApplicationEngine appEngine;

    return app.exec();
}