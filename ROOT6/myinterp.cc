// Basically Root interpreter...
// We may want to customize the CLI so that specific settings, libraries
// etc are applied/loaded automatically. May also want to prevent, or at
// least minimize, user overriding of settings (e.g. plot style).

#include <iostream>

#include "TROOT.h"
#include "TRint.h"
#include "TEnv.h"
#include "TString.h"

#include "myinterp_BinReloc.h"
std::string getApplicationDir() {
  char* exePath(0);
  exePath = br_find_exe_dir("");
  //boost::filesystem::path sExePath(exePath);
  std::string cExePath(exePath);
  free(exePath);
  //boost::filesystem::path cExePath = boost::filesystem::canonical(sExePath);
  return cExePath; //cExePath.string();
}



int main(int argc, char *argv[])
{
  // BinReloc setup
  BrInitError err;
  if(!br_init(&err)) {
    std::cerr << "failed to initialize binreloc" << std::endl;
    return 1;
  }
  std::string thisAppPath(getApplicationDir());


  // Initial gROOT call to ensure the system is set up. This should
  // create gEnv and allow us to manipulate that
  gROOT->GetVersion();
  // Can delete gEnv if needed (not clear yet)
  //if(gEnv) {
  //  delete gEnv;
  //  "Empty" env to which individual files can be added
  //  gEnv = new TEnv("");
  //}

  // Just try and use local file to override settings. Have to use
  // kEnvChange to guarantee overwrite.
  // If we want the order
  // - System .rootrc
  // - User app settings
  // - Our own settings
  // Then have to have empty env and load files one by one.
  // Have used local file, but could also use app dir
  // Set up things we can't derive directly from config file - e.g.
  // search paths relative to exe location
  gEnv->ReadFile("myconfig", kEnvChange);

  // Handle MacroPath and DynamicLoader Path here so we can
  // prefer our own directories whilst not overidding any
  // core/user ones
  TString appMacroPath(thisAppPath+"/macros");
  TString curMacroPath(gROOT->GetMacroPath());
  gROOT->SetMacroPath(appMacroPath+":"+curMacroPath);


  TRint theApp("MyInterp", &argc, argv);// 0, 0, kTRUE);
  // The SetPrompt method is the correct method, but a bug in Root6
  // changed behaviour so that the old root prompt is always switched
  // back to:
  // https://sft.its.cern.ch/jira/browse/ROOT-6372
  theApp.SetPrompt("myinterp [%d]: ");
  theApp.Run();
  return 0;
}
