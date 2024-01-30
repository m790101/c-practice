#include <stdio.h>
#include <iostream>
#include <vector> // Include the <vector> header file
#include <string>

using namespace std; // Use the std namespace
void printVector(vector<string> vec);

int main()
{
    // vector<int> foo = {1,3};
    vector<string> foo = {"0", "yo"};
    // foo.push_back("Hello");
    // foo.push_back("World");

    string bar = "1231231";

    foo.push_back("World");
    printVector(foo);
    foo.pop_back();
    printVector(foo);
    foo.insert(foo.begin(), bar);
    printVector(foo);
    return 0;
}

void printVector(vector<string> vec)
{
    cout<<"--------------"<<endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}
