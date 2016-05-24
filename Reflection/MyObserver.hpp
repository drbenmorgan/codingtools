#ifndef MYOBSERVER_HH
#define MYOBSERVER_HH

#include <ponder/observer.hpp>
#include <ponder/class.hpp>

class MyObserver : public ponder::Observer {
  virtual void classAdded(const ponder::Class& added) {
    std::cout << "MyObserver::classAdded : " << added.name() << std::endl;
  }
};

#endif // MYOBSERVER_HH

