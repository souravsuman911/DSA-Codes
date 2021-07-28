void arrangeArray(vector<int> &arr){

	int i = 0;
	int j = arr.size() - 1;

	while(i < j){
		while(arr[i] < a && i < j) i ++;
		while(arr[j] >= a && i < j) j --;
		
		swap(arr[i], arr[j]);
	}
}

// -12, 11, -13, -5, 6, -7, 5, -3, -6