#include "app_engine.hpp"
#include "button_states.hpp"
#include "button_handler.hpp"

#include <QtWidgets/QApplication>
#include <QtWebEngine/qtwebengineglobal.h>

using namespace daylite;

int main(int argc, char **argv)
{ 
  QApplication app(argc, argv);
  
  ButtonHandler handler;
  
  QtWebEngine::initialize();
  
  ApplicationEngine appEngine;
  
  // Connect button signals to QML engine slots
  QObject::connect(&handler, SIGNAL(upReceived()), &appEngine, SLOT(callScrollUp()));
  QObject::connect(&handler, SIGNAL(downReceived()), &appEngine, SLOT(callScrollDown()));
  
  return app.exec();
}