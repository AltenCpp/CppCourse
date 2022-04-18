// Example of checking the number is even or not using async
#include <iostream>       // library used for std::cout
#include <future>         // library used for std::async and std::futur
// function for checking the number is even or not
bool check_even (int num) {
std::cout << "Hello I am inside the function!! \n";
//checking the divisibility of number by 2 and returning a bool value
if(num%2==0)
{
return true;
}
return false;
}
int main ()
{
// calling the above function check_even asynchronously and storing the result in future object
std::future<bool> ft = std::async (check_even,10);
std::cout << "Checking whether the number 10 is even or not.\n";
// retrieving the exact value from future object and waiting for check_even to return
bool rs = ft.get();
if (rs) {
std::cout << "Number mentioned by you is even \n";
}
else {
std::cout << "Sorry the number is odd \n";
}
return 0;
}