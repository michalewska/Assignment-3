/* Main */

#include <iostream>
#include <fstream>
#include <string>

#include "fileScanner.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char **argv) {

  fileScanner fc;

  //if the user didn't provide 2 arguments, let the user know how to do it and end program
  if(argc != 2)
  {
  	cout << "Usage: " << argv[0] << " filename.txt" << endl;
  	return 1;
  }
  else {
    string fileName = argv[1];
    fc.scanner(fileName);
  }

  return 0;

}
