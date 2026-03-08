
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

int main()
{
    vector<int>arr;
    vector<int>values = {10, 3, 2, 4, 5, 1};
    int n = values.size();
    for (int i = 0; i < n; i++) {
        insert(arr, values[i]);
        cout << "Inserted " << values[i]
             << " into the min-heap: ";
        for (int j = 0; j <arr.size(); j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
