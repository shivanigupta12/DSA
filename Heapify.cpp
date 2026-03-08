#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>& arr, int val) {
    arr.push_back(val);
    int idx = arr.size()-1;
    int par = (idx -1)/2;
    while(par>=0 || arr[par]>arr[idx]) {
        if(arr[par]>arr[idx]){
            swap(arr[par], arr[idx]);
            idx = par;
            par = (par-1)/2;
        }else{
            break;
        }
    }
}

void heapify(vector<int>&arr, int idx) {
    while(true) {
        int smallest = idx;
        int left = idx*2+1;
        int right = idx*2+2;
        if(left<arr.size() && arr[left]<arr[smallest]){
            smallest = left;
        }
        if(right<arr.size() && arr[right]<arr[smallest]){
            smallest = right;
        }
        if(smallest == idx){
            break;
        }else{
            swap(arr[idx], arr[smallest]);
            idx = smallest;
        }
        
    }
}

void deleteMin(vector<int>&arr, int val){
    int index = -1;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(arr[i] == val){
            index = i;
            break;
        }
    }
    swap(arr[index], arr[n-1]);
    arr.pop_back();
    heapify(arr, index);
}

int main()
{
    vector<int>arr;
    vector<int>values = { 13, 16, 31, 41, 51, 100 };
    int n = values.size();
    for (int i = 0; i < n; i++) {
        insert(arr, values[i]);
    }
    cout << "Initial heap: ";
    for (int j = 0; j < arr.size(); j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

    deleteMin(arr, 13);
    cout << "Heap after deleting 13: ";
    for (int j = 0; j < arr.size(); j++) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}
