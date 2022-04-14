/*Generate random numbers between 0-33, ten thousand times, then print how many duplicates of each number
you have generated -- print in ascending order.
Main Editor:TaycirLouati
*/

#include <iostream>
#include <map>

int main()
{
    int rand_num;
    std::map<int,int> random_map;
    for (int i=0; i<10000; i++)
    {
        rand_num = (rand() % 33);
        if ((rand_num < 0) || (rand_num > 33))
            std::cout<<"Error! random number is not between 0-33\n";
        random_map[rand_num] ++;
    }
    for (auto &e: random_map)
    {
        std::cout<<"the number "<<e.first<<" has "<<e.second<<" duplicates.\n";
    }
    
    return 0;
}