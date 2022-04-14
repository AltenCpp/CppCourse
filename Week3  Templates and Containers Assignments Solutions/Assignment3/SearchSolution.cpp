/*We want to generate 1024 random integers, then given a new random number; find two integers which are the
closest to the given number (smaller, and bigger) with less than twelve lookups.
Main Editor:TaycirLouati
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int rand_num;
    std::set<int> random_set;
    for (int i=0; i<1024; i++)
    {
        rand_num = rand();
        random_set.insert(rand_num);
    }
    
    int searched_rand_number = rand();
    bool element_found = false; 

    int lookups_counter = 0;

    while (random_set.size()>3) 
    {
        //declare this iterator to get the address of the middle of the set
        std::set<int>::iterator itr_middle = random_set.begin();

        //get the address of the middle of the set
        uint half_size = random_set.size()/2;
        std::advance(itr_middle, half_size);

        lookups_counter ++;
        cout<<"lookups_counter = "<<lookups_counter<<"\n";
        cout<<random_set.size()<<"\n";
        cout<<random_set.size()/2<<"\n";
        

        if (searched_rand_number<*itr_middle)
        {
            itr_middle++;
            random_set.erase(itr_middle, random_set.end());
        }
        else
        {
            itr_middle--;
            random_set.erase(random_set.begin(), itr_middle);
        }
    }

    std::set<int>::iterator itr_middle = random_set.begin();
    itr_middle++; 
    std::set<int>::iterator itr = random_set.end();
    itr --;
    if (*itr_middle < searched_rand_number)
        cout<<"For the random number "<<searched_rand_number<<": The smaller number is "<<*itr_middle<<" and the bigger number is "<<*(itr)<<"\n";
    else   
        cout<<"For the random number "<<searched_rand_number<<": The smaller number is "<<*random_set.begin()<<" and the bigger number is "<<*itr_middle<<"\n";
    
    cout<<"lookups_counter = "<<lookups_counter<<"\n";
    return 0;
}