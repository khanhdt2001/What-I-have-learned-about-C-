#include<iostream>
using namespace std;
// This is what i learn about Pointer in c++
int main(){
    int base = 10;
    int* ptr= &base;



    /* int base có vùng giá trị = 10
     và đại chỉ trên ô nhớ bằng 0x6ffe14
     kí tự & là tham chiếu 
    */

    cout<< base << endl; 
    cout<< &base << endl;
    cout<< ptr << endl;
    cout<< *ptr <<endl;

    *ptr =20;
    cout<< base << endl; 
    cout<< &base << endl;
    cout<< ptr << endl;
    cout<< *ptr <<endl;
    //pointer can be used in arr

    int arr[5] = {1,2,3,4,5};
    for(int i =0; i<5; i ++) {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    int array[5][5] = {{1,2,3,4,5},{1,3,4,5,2},{1,4,5,2,3},{1,5,2,3,4},{2,3,4,5,1}};
    for(int i =0; i < 5; i ++) {
        for(int j =0; j < 5; j ++) {
            cout<<*(*(array+i)+j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}