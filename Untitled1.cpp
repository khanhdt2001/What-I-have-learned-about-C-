#include<iostream>
#include<vector>
#include<sstream>
#include <string>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;
bool check(long long n){
	while( n > 0 ){
		int last1 = n%10;
		n = n /10;
		int last2 = n %10;
		if( last1 - last2 !=1) return false;
	}
	return true;
}
int sumInt(int n ){
	int sum =0;
	while(n >0) {
		int last1 = n %10;
		n= n /10;
		sum += last1;
	}
	return sum;
}
int sqInt(int n){
	int sq =1;
	while(n >0) {
		int last1 = n %10;
		n= n /10;
		sq = sq * last1;
	}
	return sq;
}
vector<long long> sequenceNumber(long long l, long long r)
{
	long long base[]= {1, 2, 3, 4, 5, 6, 7, 8, 9,
                12, 23, 34, 45, 56, 67, 78, 89,
                123, 234, 345, 456, 567, 678, 789,
                1234, 2345, 3456, 4567, 5678, 6789,
                12345, 23456, 34567, 45678, 56789,
                123456, 234567, 345678, 456789,
                1234567, 2345678, 3456789,
                12345678, 23456789,
                123456789};
    vector<long long> result;
    for(int i =0; i < 200; i ++) {
    	if( base[ i]>= l && base[i] <= r) {
    		result.push_back(base[i]);
		}
		if(base[i]> r) {
			break;
		}
	}
    return result;
}
int average(vector<int> a){
	int sum =0;
	for(int i =0; i < a.size();i ++){
		sum += a[i];
	}
	return sum/a.size();
}
int sumNumbersLargerAverage(vector<int> a)
{
	int avg= average(a);
	int sum =0;
	for(int i =0; i < a.size(); i ++){
		if(a[i] > avg) {
			sum +=a[i];
		}
	}
	return sum;
}
int minn(int arr[], int n) {
	int m = arr[0];
	for(int i = 1 ; i < n;i++){
		if (m > arr[i]){
			m = arr[i];
		}
	}
	return m;
}
int solve(int arr[], int n)
{
	
	int count =0;
	int m = minn(arr, n);
    
	for(int i =0 ; i < n-1; i ++){
		if(arr[i]== m ){
			i++;
		}
		for (int j = i +1; j < n; j ++){
			
			if(arr[i]> arr[j]){
				count++;  
			}
		}
	}
	return count;
}
bool checkhr(int a[], int n){
	int count=0;
	for (int i =0; i <n; i ++){
		count+= a[i];
	}
	if(count == a[0]*n) return false;
	return true;
}
long long legoWall(int n, int m)
{
/*
	n = height, m = weidth
	has 3 props : 1-1
				  1-2
				  1-3
				  1-4
	problem how many ways to create n-m
*/
	srand(time(NULL));
	int count =0;
	int arr[n];
	for (int i =0 ; i < n; i ++){
		arr[i]=0;
	}
	int randmax = m > 4 ? m : 4;
	while(true){
		for(int i =0 ; i < n; i ++){
			int ran = rand()% randmax;
			arr[i]= ran;
		}
		if(checkhr(arr, n)) count ++;
	}
}
int main(){
	int a[4] ={ 1, 2, 1 ,1 };
	if(checkhr(a, 4)) cout<<"yes";
}
