#include <iostream>
#include <fstream>
//#include <syslog>
using namespace std;



int write2file() {
  // declarations
  streambuf *psbuf, *backup;
  ofstream filestr;
  backup = cout.rdbuf();          // back up cout's streambuf
  filestr.open("test.txt");
    psbuf = filestr.rdbuf();        // get file's streambuf
    cout.rdbuf(psbuf);              // assign streambuf to cout
      cout << "This is written to the file\n";
    cout.rdbuf(backup);             // reassign cout's original streambuf
  filestr.close();
  return 0;
}

int invoer(){
  int sum = 0, value = 0;
  // read until end-of-file, calculating a running total of all values read
  cout << "Enter numbers to add. (^D to end input)" << endl;
  while (cin >> value){
    sum += value; // equivalent to sum = sum + value
  }
  cout << "Sum is: " << sum << endl;
  return 0;
}

int main(){
  int r = 0;
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
  r = write2file();
  r = invoer();
  return r;
}
