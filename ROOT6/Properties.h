#ifndef PROPERTIES_HH
#define PROPERTIES_HH

// Standard Library

// Third Party
// - A

// This Project

// Designed to model a nested name-value structure
// id0 : properties {
//   id1 : int = 1
//   id2 : double = 2
//   id3 : int = {1,2,3,4}
//   id4 : properties {
//     id5 : string = "foo"
//   }

#include "TObject.h"
#include "boost/property_tree/ptree.hpp"

struct Properties : public TObject{
 Properties() : TObject() {};

 ClassDef(Properties, 1);

 // NB not serializable... or at least, no data stored/retrived!!
 boost::property_tree::ptree data;
};

#endif // PROPERTIES_HH

