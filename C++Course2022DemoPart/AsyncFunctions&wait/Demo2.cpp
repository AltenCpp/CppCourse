// c++ program that demonstrates async
// library for std::cout
#include <iostream>
//library for std::async and std::future
#include <future>
// check whether it is prime number or not
//parameter is the number that has to be checked
bool fnprime (int num)
{
std::cout << "Process started. . . Just wait. . . \n";
//loop starts here
for ( int i = 2 ; i<num ; ++i )
//if the mod is 0, return false, else return zero
if (num%i==0)
{
return false ;
}
return true ;
}
//main method
int main ()
{
// call the function fnprime() asynchronously to check whether the number is prime or not:
std::future<bool> fobj = std::async (fnprime,4);
//print the line to show the status
std::cout << "check whether the number 4 is prime or not . . \n";
//waits for the the function fnprime to return
bool bobj = fobj.get();
//prints the result
if (bobj) std::cout << "The number given is prime . . .  ! \n";
else std::cout << "The number given is not prime . . .  ! \n\n";
return 0;
}

