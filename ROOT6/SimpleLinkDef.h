#ifdef __ROOTCLING__

#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ class boost::property_tree::ptree+;
#pragma link C++ class Properties+;

#pragma link C++ struct TypeWrapper<int>+;
#pragma link C++ struct TypeWrapper<double>+;
#pragma link C++ struct TypeWrapper<bool>+;
#pragma link C++ struct TypeWrapper<std::string>+;
#pragma link C++ struct TypeWrapper<std::vector<int> >+;

#pragma link C++ class Simple-;


#endif
