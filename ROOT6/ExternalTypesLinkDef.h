
#ifdef __ROOTCLING__
#pragma link C++ namespace Poco;
#pragma link C++ namespace Poco::Dynamic;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;

// O.k., but VarHolderImpl has no default constructor, and don't seem
// to be able to provide an ioctortype...
#pragma link C++ class Poco::Dynamic::Var+;



#endif
