#include<iostream>
#include<windows.h> // for Sleep()
#include<string>
using namespace std;

int main(){
    
    string introduce= "Hello, it `s me Khanh";
    string hello=" Can I be your friend ?";
    int introduceLen = introduce.length();
    string base;

    for(int i =0; i < introduceLen; i++){
        base.push_back('_');
        Sleep(200);
        cout<<base[i];
    }
    
    if (system("CLS")) system("clear");

    for(int i =0; i < introduceLen; i ++){
        base[i] = introduce[i];
        cout<< base;
        Sleep(200);
        if (system("CLS"))
        {
            system("clear");
        }
        
    }
    // Sleep(1000);
    // if (system("CLS")) system("clear");
}