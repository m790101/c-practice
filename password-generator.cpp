// g++ -std=c++11 password-generator.cpp -o password-generator 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>
#include <algorithm>

int getRandomNum(int optionLength);

int main()
{
    std::string password = "";
    int times = 6;
    int optionLength;
    char option = '2';
    std::vector<char> optionV;
    std::vector<char> numV = {'0','1','2','3','4','5','6','7','8','9'};
    std::vector<char> lowLetterV = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::vector<char> captitalLetterV = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    switch(option){
    // 1 -> only number 
    case '1': 
        optionLength = numV.size();
        optionV = numV;
        break;
        
    // 2 -> lower letter with num
    case '2': 
        optionLength = numV.size() + lowLetterV.size();
        optionV.resize(optionLength);
        std::merge(numV.begin(), numV.end(), lowLetterV.begin(), lowLetterV.end(), optionV.begin());
        break;

    // 3 -> lower + captital + num
    case '3': 
        optionLength = numV.size() + lowLetterV.size() + captitalLetterV.size();
        break;
    }


    for(int i = 0; i < times ; i++){
        int randomNum =  getRandomNum(optionLength);
        password += optionV[randomNum];
    }

    printf("password is %s\n", password.c_str());

    return 0;
 }


int getRandomNum(int optionLength){
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0,optionLength-1);
    int randomNum = distribution(gen);
    return randomNum;

}