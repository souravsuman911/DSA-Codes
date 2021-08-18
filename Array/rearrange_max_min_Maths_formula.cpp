void rearrange(long long *arr, int n) 
{ 
	int me = arr[n - 1] + 1;
	int max = n - 1;
	int min = 0;
	
	for(int i = 0; i < n; i ++){
	    if(i % 2 == 0){
	        arr[i] += (arr[max] % me) * me;
	        max--;
	    }
	    else{
	        arr[i] += (arr[min] % me) * me;
	        min ++;
	    }
	}
	
	for(int i = 0; i < n; i ++){
	    arr[i] /= me;
	}
	
	 
}