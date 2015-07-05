#include "button_handler.hpp"
#include "button_states.hpp"

#include "daylite/node.hpp"
#include "daylite/spinner.hpp"

#include <iostream>

using namespace daylite;
using namespace std::placeholders;

ButtonHandler::ButtonHandler()
{
  // Set up the daylite node
  _node = node::create_node("l_node");
  if(!_node)
    std::cerr << "could not create daylite node" << std::endl;
  
  const bool ret = _node->join_daylite("127.0.0.1", 8374);
  if(!ret)
    std::cerr << "could not connect to daylite gateway" << std::endl;
  
  _sub = _node->subscribe("/robot/button_states", std::bind(&ButtonHandler::receivedMessage, this, _1, _2));
  
  connect(&_spin_timer, &QTimer::timeout, [] () { spinner::spin_once(); });
  _spin_timer.start(100);
}

void ButtonHandler::receivedMessage(const bson_t *msg, void *)
{
  using namespace bson_bind;
  
  button_states bs = button_states::unbind(msg);
  if(bs.pressed[0])
    emit upReceived();
  if(bs.pressed[1])
    emit downReceived();
}