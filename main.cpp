#include <iostream>
#include <string>
#include "ALU.h"
#include <bitset>


using namespace std;


int main()
{
    string binary = bitset<8>("00000111").to_string();
    cout << binary << "\n";

    unsigned long decimal = bitset<8>(binary).to_ulong();
    cout << decimal << "\n";


}

