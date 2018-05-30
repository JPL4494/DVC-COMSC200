/*
Lab 72, The string member functions program
Programmer: Joshua Long
Editor used: Notepad
Compiler used: CodeBlocks
*/

#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

int main()
{
  cout << "Lab 71, The string member functions Program" << endl;
  cout << "Programmer: Joshua Long" << endl;
  cout << "Editor used: Notepad" << endl;
  cout << "Compiler used: CodeBlocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string string1("noon is 12 PM; midnight is not.");
  int location;

  cout << "Original string: " << endl << string1 << endl << endl;
  cout << "Running find first occurrence of \"is\", expected result 5"
    << endl << "(find) \"is\" was found at: " << string1.find("is") << endl << endl;
  cout << "Running find last occurrence of \"is\", expected result 24"
    << endl << "(rfind) \"is\" was found at: " << string1.rfind("is");

    cout << endl << endl << "Running find first match of any of following \"misop\", expected result o and  1";
    location = string1.find_first_of("misop");
    cout << endl << "(find_first_of) found '" << string1[location]
      << "' from the group \"misop\" at: " << location;

    cout << endl << endl << "Running find last match of any of following \"misop\", expected result o and 28";
    location = string1.find_last_of("misop");
      cout << endl << "(find_last_of) found '" << string1[location]
      << "' from the group \"misop\" at: " << location;

    cout << endl << endl << "Running find first non-match of following \"misop\", expected result 1 and 8";
    location = string1.find_first_not_of("noi spm");
    cout << endl << "(find_first_not_of) found '" << string1[location]
      << "' is not contained in \"noi spm\" and was found at: " << location;

    cout << endl << endl << "Running find first non-match of following \"misop\", expected result P and 11";
    location = string1.find_first_not_of("12noi spm");
    cout << endl << "(find_first_not_of) found '" << string1[location]
      << "' is not in \"12noi spm\" and was found at: " << location;

    cout << endl << endl << "Running find first missing of \"noon is 12 PM; midnight is not.\"" << endl;
    cout << "Expected result -1 because all matching";
    location = string1.find_first_not_of("noon is 12 PM; midnight is not.");
    cout << endl << "(find_first_not_of) found (\"noon is 12 PM; midnight is not\")"
      << " returned: " << location << endl;

    string string2("Midnight is 12 AM; noon is not.");

    cout << endl << endl;
    cout << "Testing swap memeber function, outputing original string now:" << endl;
    cout << string2 << endl;
    cout << "Now swapping strings, expexted output \"noon is 12 PM; midnight is not.\"" << endl;
    string1.swap(string2);
    cout << string2 << endl;

    cout << endl << endl;
}
