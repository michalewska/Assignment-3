/* File Scanner */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "GenStack.h"
#include "fileScanner.h"

using namespace std;

fileScanner::fileScanner()
{

}

fileScanner::~fileScanner()
{

}

int fileScanner::scanner(string fileName)
{

  //to be able to process another file
  char choice;

  do {
    cout << "Opening file: " << fileName << endl;
    ifstream inFile;
    inFile.open(fileName.c_str());
    stringstream sstr;
    if(inFile.is_open() == false)
    {
      cout << "File not found. Try again: " << endl;
      cin >> fileName;
    }

    //stack for opening and closing delimiters
    GenStack<char> open(20);
    GenStack<char> close(20);

    //variables keeping track of line number
    int lineCount = 0;
    //code is a string that contains all the code from the input file
    string code;

    while (getline(inFile, code))
    {
      //iterating through code to add delimiters to temp stacks
      for (int i = 0; i < code.length(); ++i)
      {
        //stack with all opening delimiters
        if (code[i] == '(' || code[i] == '[' || code[i] == '{')
        {
          open.push(code[i]);
          cout << open.peek() << " pushed to stack: open." << endl;
        }
        else if (code[i] == ')' || code[i] == ']' || code[i] == '}')
        {
          close.push(code[i]);
          cout << close.peek() << " pushed to stack: close." << endl;
        }


        //checking for matching delimiters
        //if the first element in the stack is '(' and the index in the string is ')'
        //the top is removed from the stack and the following element becomes the top
        else if(open.peek() == '(' && close.peek() == ')')
        {
          cout << "The open peek is: " << open.peek() << endl;
          cout << "The close peek is: " << close.peek() << endl;

          cout << "in matched" << endl;
          open.pop();
          cout << "Line " << lineCount << ": " << "() matched." << endl;
        }

        else if(open.peek() == '[' && close.peek() == ']')
        {
          open.pop();
          cout << "Line " << lineCount << ": " << "[] matched." << endl;
        }

        else if(open.peek() == '{' && close.peek() == '}')
        {
          open.pop();
          cout << "Line " << lineCount << ": " << "{} matched." << endl;
        }

        //checking mismatched delimiters
        //if peek is a certain delimeter and there is no matching one
        //print error
        else if (open.peek() == '(' && (close.peek() == ']' || close.peek() == '}'))
        {
          cout << "Line " << lineCount << ": " << "')' expected, not found." << endl;
        }
        else if (open.peek() == '[' && (close.peek() == ')' || close.peek() == '}'))
        {
          cout << "Line " << lineCount << ": " << "']' expected, not found." << endl;
        }
        else if (open.peek() == '{' && (close.peek() == ']' || close.peek() == ')'))
        {
          cout << "Line " << lineCount << ": " << "'}' expected, not found." << endl;
        }
        //increment line number
        ++lineCount;
      }
    }


    //processing another file
    cout << "Would you like to process another file? (y/n)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
      cout << "Enter the name of your file: " << endl;
      cin >> fileName;
      continue;
    }
    else if (choice == 'n' || choice == 'N')
    {
      cout << "End of program." << endl;
      inFile.close();
      return 0;
    }
    else
    {
      while (choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N')
      {
        cout << "Invalid input, try again: " << endl;
        cin >> choice;
        cout << "Enter the name of your file: " << endl;
        cin >> fileName;
      }
    }

  } while (choice == 'y' || choice == 'Y');

  return 0;
}
