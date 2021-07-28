#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	int n = arr.size();

	// index by index
	for(int i = 0; i < n; i ++){
		for(int j = i; j < n; j ++){
			for(int k = i; k <= j; k ++)
				cout << arr[k] << " ";
			cout << endl;
		}cout << endl;
	}cout << endl;

	// size by size
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n - i + 1; j ++){
			for(int k = j; k < j + i; k ++){
				cout << arr[k] << " ";
			}cout << endl;
		}cout << endl;
	}cout << endl;


	return 0;
}