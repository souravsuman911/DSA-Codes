#include<bits/stdc++.h>
using namespace std;

int parent(vector<int> &v, int i){
    return (i - 1) / 2;
}

int leftChild(vector<int> &v, int i){
    return (2 * i) + 1;
}

int rightChild(vector<int> &v, int i){
    return (2 * i) + 2;
}

void heapify(vector<int> &v, int i){
    int l = leftChild(v, i);
    int r = rightChild(v, i);

    if( (v[i] > v[l] && v[i] > v[r]) || l > v.size() - 1 || r > v.size())
        return;

    if(v[i] < v[l] || v[i] < v[r]){
        int prev;
        if(v[l] > v[r])
            prev = l;
        else  
            prev = r;

        swap(v[i], v[prev]);
        heapify(v, prev);
    }
    

    
}

void insertData(vector<int> &v, int data){
    v.push_back(data);
    int i = v.size() - 1;
    int p = parent(v, i);

    while(i >= 0 && p >= 0 && v[i] < v[p] ){
        swap(v[i], v[p]);
        i = p;
        p = parent(v, i);
    }
}

void deleteData(vector<int> &v, int data){
     
}


int main(){

    vector <int> v;
    int n;
    cin >> n;

    int item;
    for(int i = 0; i < n; i ++){
        cin >> item;
        insertData(v, item);
    }

    for(auto it : v)
        cout << it << " ";
    cout << endl;

    return 0;

    // 10 5 7 3 4 8 9 7 0 6 1
    // 3 4 8 6
}