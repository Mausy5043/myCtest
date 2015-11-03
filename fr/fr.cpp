#include <iostream>
#include <fstream>
using namespace std;

int write2file() {
  streambuf *psbuf, *backup;
  ofstream filestr;
  filestr.open ("test.txt");

  backup = cout.rdbuf();          // back up cout's streambuf

  psbuf = filestr.rdbuf();        // get file's streambuf
  cout.rdbuf(psbuf);              // assign streambuf to cout

  cout << "This is written to the file";

  cout.rdbuf(backup);             // restore cout's original streambuf

  filestr.close();

  return 0;
}



int main(){
  cout << "This text is sent to `cout`." << endl;
  clog << "This text is sent to `clog`." << endl;
  cerr << "This text is sent to `cerr`." << endl;
  return 0;
}
