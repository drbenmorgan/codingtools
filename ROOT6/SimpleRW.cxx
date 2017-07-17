// Standard Library
#include <iostream>
#include <random>

// Third Party
// - ROOT
#include "TFile.h"
#include "TTree.h"

// This Project
#include "Simple.hpp"
#include "Properties.h"


void setSimple(Simple& s) {
  // Set ss to random type and value
  static std::default_random_engine gen;
  static std::uniform_int_distribution<int> dist(0,3);
  static auto type_roll = std::bind(dist, gen);

  int type = type_roll();

  switch (type) {
    case 0:
      s.setValue(42);
      break;
    case 1:
      s.setValue(3.14);
      break;
    case 2:
      s.setValue("somerandomstrng");
      break;
    case 3:
      s.setValue(std::vector<int> {1,2,3,4});
      break;
  }
}



void doRead(const char* infile) {
  std::cout << "reading... " << infile << std::endl;

  TFile f {infile, "READ"};

  TTree* t = dynamic_cast<TTree*>(f.Get("simple_tree"));

  Properties* p = dynamic_cast<Properties*>(f.Get("properties"));

  if(!t) {
    return;
  }

  Simple* s {nullptr};
  t->SetBranchAddress("simples",&s);

  for (Int_t i=0; i<t->GetEntries(); ++i) {
    t->GetEntry(i);
  }

  if(!p) {
    return;
  }
  //std::cout << p->data.get<std::string>("debug.filename") << std::endl;

}

void doWrite(const char* outfile) {
  std::cout << "writing... " << outfile << std::endl;
  TFile f {outfile, "RECREATE"};

  TTree t {"simple_tree", "Tree of simples"};
  Properties p;
  p.data.put("debug.filename", "foo.text");
  p.data.put("debug.level", 42);
  p.Write("properties");


  Simple s;

  t.Branch("simples","Simple",&s, 32000,0);

  for (size_t i {0}; i < 100; ++i) {
    setSimple(s);
    t.Fill();
  }

  f.Write();
  f.Close();
}

int main(int argc, char *argv[])
{
  if (argc != 3 ) {
    std::cerr << "need to supply operation and file" << std::endl;
    return 1;
  }

  std::string op {argv[1]};

  if (op == "read") {
    doRead(argv[2]);
  }
  else if (op == "write") {
    doWrite(argv[2]);
  }
  else {
    return 1;
  }

  return 0;
}

