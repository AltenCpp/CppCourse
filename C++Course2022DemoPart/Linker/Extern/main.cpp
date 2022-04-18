#include <iostream>

using namespace std;
extern int f1(void);

int main(void)
{
    int x;
    x=10*f1();
    cout<<x<<endl;
    return 0;
}