#include <iostream>
#include <fstream>
using namespace std;

int write2file() {
  // declarations
  streambuf *psbuf, *backup;
  ofstream filestr;

  backup = cout.rdbuf();          // back up cout's streambuf

  filestr.open ("test.txt");
  psbuf = filestr.rdbuf();        // get file's streambuf
  cout.rdbuf(psbuf);              // assign streambuf to cout

  cout << "This is written to the file\n";

  cout.rdbuf(backup);             // reassign cout's original streambuf

  filestr.close();

  return 0;
}



int main(){
  int r;
  cout << "This text is sent to `cout`." << endl;
  clog << "This text is sent to `clog`." << endl;
  cerr << "This text is sent to `cerr`." << endl;
  r = write2file();
  return r;
}
