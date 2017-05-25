#include "ditto_ana_wwwanalysis.h"

int main(int argc, char* argv[])
{
  if (argc != 3 && argc != 4)
  {
    PrintUtil::print("Usage:");
    PrintUtil::print("");
    PrintUtil::print("        ./ditto_ana_wwwanalysis INPUT_FILE_PATH OUTPUT.root [MAXEVENTS]  # the last three argument must be provided at the same time");
    PrintUtil::print("");
    PrintUtil::error("Please check your arguement!");
  }

  const char* input_file_path = argv[1];
  const char* output_file_path = argv[2];

  int max_nevents = -1;
  // When 4 arguments are provided
  if (argc == 4)
    max_nevents = atoi(argv[3]);

  TChain *chsig = new TChain("MyBaby");
  chsig->Add(input_file_path);
  MyBabyLooper(chsig, output_file_path, max_nevents);

}
