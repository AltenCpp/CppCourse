#include <iostream>
using namespace std;

extern int f1(void);
int main() {
    int x=10 *f1();
   cout << "Value of X" << x <<endl; // This prints Hello, World!
   return 0;
}