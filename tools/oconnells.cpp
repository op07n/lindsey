#include <iostream>

#include "daylite/node.hpp"
#include "daylite/spinner.hpp"
#include "button_states.hpp"

using namespace daylite;

int main()
{
  // Create and setup daylite node
  auto oconnells_node = node::create_node("oc_node");
  if(!oconnells_node)
  {
    std::cerr << "could not create daylite node" << std::endl;
    return 1;
  }
  
  bool ret = oconnells_node->join_daylite("127.0.0.1", 8374);
  if(!ret)
  {
    std::cerr << "could not connect to daylite gateway" << std::endl;
    return 1;
  }
  
  auto oconnells_pub = oconnells_node->advertise("/robot/button_states");
  if(!oconnells_pub)
  {
    std::cerr << "could not pub" << std::endl;
    return 1;
  }
  
  // Print commands
  std::cout << "u: scroll up" << std::endl;
  std::cout << "d: scroll down" << std::endl;
  std::cout << "q: quit" << std::endl;
  
  // Loop until quit command
  char input;
  std::cin >> input;
  while(input != 'q')
  {
    bson_bind::button_states bs;
    
    // Note: buttons are pressed, but never unpressed
    if(input == 'u')
    {
      bs.pressed.push_back(true);
      bs.pressed.push_back(false);
    }
    else if(input == 'd')
    {
      bs.pressed.push_back(false);
      bs.pressed.push_back(true);
    }
    else
    {
      std::cerr << "invalid command" << std::endl;
      break;
    }
    
    oconnells_pub->publish(bs.bind());
    spinner::spin_once();
    
    std::cin >> input;
  }
  
  return 0;
}