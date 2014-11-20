// test_unique_ptr - See what unique_ptr can and cannot do
//
// Copyright (c) 2014 by Ben Morgan <bmorgan.warwick@gmail.com>
// Copyright (c) 2014 by The University of Warwick

#include <memory>
#include <list>
#include <map>
#include <string>


class ELdestination {
 public:
};


int main(int argc, char *argv[])
{
  std::list<std::unique_ptr<ELdestination> > sinks;
  std::map<std::string, std::unique_ptr<ELdestination> > attachedDests;

  sinks.emplace_back(new ELdestination);
  attachedDests["foo"] = sinks.back();

  return 0;
}

