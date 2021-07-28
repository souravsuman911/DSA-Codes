void rearrange(int arr[], int n) {
	    vector<int> pos;
	    vector<int> neg;
	    
	    for(int i = 0; i < n; i ++){
	        if(arr[i] >= 0)
	            pos.push_back(arr[i]);
	        else
	            neg.push_back(arr[i]);
	    }
            
        int i = 0, j = 0, idx = 0;
        
        while(i < pos.size() && j < neg.size()){
            arr[idx ++] = pos[i ++];
            arr[idx ++] = neg[j ++];
        }
        
        while(j < neg.size())
            arr[idx ++] = neg[j ++];
            
        while(i < pos.size())
            arr[idx ++] = pos[i ++];
	}