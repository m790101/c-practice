
// g++ -std=c++11 playground.cpp -o playground

#include <iostream>
#include <vector>
#include <unordered_map>


int main()
{
    std::vector<int> foo = {1, 3};
    // std::vector<int>::iterator it;
    for(auto it=foo.begin(); it != foo.end(); it++){

        // std::cout << *it << std::endl;
        *it = *it + 1;
         std::cout << *it << std::endl;
    }
    // for(auto &i : foo){
    //     std::cout << i << "\n";
    // }
    // std::cout << *foo.end()<<std::endl;
    return 0;
}
