#ifndef _BUTTON_HANDLER_HPP_
#define _BUTTON_HANDLER_HPP_

#include "daylite/node.hpp"

#include <QObject>
#include <QTimer>

using namespace daylite;

class ButtonHandler : public QObject
{
  Q_OBJECT
    
public:
  ButtonHandler();
  
signals:
  void upReceived();
  void downReceived();
  
private:
  void receivedMessage(const bson_t *msg, void *);
  
  std::shared_ptr<node> _node;
  std::shared_ptr<subscriber> _sub;
  QTimer _spin_timer;  
};

#endif