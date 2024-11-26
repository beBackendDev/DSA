#include <iostream>
#include <vector>
using namespace std;
vector <int> initArray( int n){
    vector<int> arr(n);
    cout<<"\nType value of Array: ";
    for (int i = 0; i< n; i++){
        cin>>arr[i];
    }
    return arr;
}

//Exercise 1:
//Given an unsorted array arr containing only non-negative integers, your task is to find a continuous subarray 
//(a contiguous sequence of elements) whose sum equals a specified value s. You need to return the 1-based 
//indices of the leftmost and rightmost elements of this subarray.
vector<int> Bai1_subarraySum(vector<int> &arr, int s) {
        // code here
        int sum = 0;
        int start = 0, end = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            while(sum >= s){
                if(sum == s){
                    return {start+1, i+1};
                }
                else {
                    sum -= arr[start];
                    start ++;
                }
            }
            
        }
        return {-1};
    }
int main(){
    int numArray;
    cout<<"\nNhap so luong phan tu Array: ";
    cin>>numArray;
    vector <int> arr = initArray(numArray);

    
    int goal;
    cout<<"\nNhap gia tri mong muon: ";
    cin>>goal;
    vector <int> result = Bai1_subarraySum(arr, goal);
    for (int i : result)
        cout<<i<<" ";
    return 0;
}