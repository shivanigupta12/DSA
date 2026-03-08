class maxHeap {
  private:
    vector<int>arr;

  public:
  
    void heapify(int idx) {
        int n = arr.size();
        while(true){
            int largest = idx;
            int left = 2*idx+1;
            int right = 2*idx+2;
            if(left<n && arr[left]>arr[largest]){
                largest = left;
            }
            if(right<n && arr[right]>arr[largest]){
                largest = right;
            }
            if(idx == largest){
                break;
            }else{
                swap(arr[idx], arr[largest]);
                idx = largest;
            }
        }
    }

    void push(int x) {
        // Insert x into the heap
        arr.push_back(x);
        int n = arr.size();
        int idx = n-1;
        int par = (idx-1)/2;
        while(idx>=0 && arr[par]<arr[idx]){
            if(arr[par]>arr[idx]){
                break;
            }else{
                swap(arr[par], arr[idx]);
                idx = par;
                par = (par-1)/2;
            }
        }
    }

    void pop() {
        // Remove the top (maximum) element
        int n = arr.size();
        swap(arr[0], arr[n-1]);
        arr.pop_back();
        heapify(0);
    }

    int peek() {
        // Return the top element or -1 if empty
        if(arr.size()==0){
            return -1;
        }
        return arr[0];
    }

    int size() {
        // Return the number of elements in the heap
        return arr.size();
    }
};
