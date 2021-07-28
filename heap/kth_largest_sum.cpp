#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for(auto it : arr)
        cout << it << " ";
    cout << endl;
}

void printPQ(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }cout << endl;
}

int kthLargestSum(vector<int> arr, int n, int k){
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i ++){
        sum += arr[i];
        arr[i] = sum;
    }
    arr.insert(arr.begin(), 0);

    print(arr);
    // sum of subarray between i and j is now arr[j] - arr[i - 1]

    for(int i = 1; i < n; i ++){
        for(int j = 0; j < n; j ++){
            sum = arr[j] - arr[i - 1];

            cout <<  sum << " ";
            if(pq.size() <= k){
                pq.push(sum);
            }
            else{
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    // pop k - 1 largest element  // alternately return pq.top()
    cout << endl;
    while(pq.size() != 1){
        cout << pq.top() << " ";
        pq.pop();
    }

    return pq.top();
}

int main(){

    vector<int> arr = {10, -10, 20, -40};
    int k = 6;
    
    cout << kthLargestSum(arr, arr.size(), k) << endl;

    return 0;
}