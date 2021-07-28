vector <int> commonElements (int arr[], int brr[], int crr[], int n1, int n2, int n3)
        {
            unordered_map<int, int> mp1;
            unordered_map<int, int> mp2;
            unordered_map<int, int> mp3;
            vector<int> v;
            
            for(int i = 0; i < n1; i ++)
                mp1[arr[i]] ++;

            // coomented lines includes duplicates     
                
            for(int i = 0; i < n2; i ++){
                if(mp1.find(brr[i]) != mp1.end()){
                    mp2[brr[i]] ++;
                    // mp1[brr[i]] --;
                    // if(mp1[brr[i]] == 0)
                        mp1.erase(brr[i]);
                }
            }
            
            for(int i = 0; i < n3; i ++){
                if(mp2.find(crr[i]) != mp2.end()){
                    mp3[crr[i]] ++;
                    // mp2[crr[i]] --;
                    // if(mp2[crr[i]] == 0)
                        mp2.erase(crr[i]);
                }
            }
            
            for(int i = 0; i < n1; i ++){
                if(mp3.find(arr[i]) != mp3.end()){
                    v.push_back(arr[i]);
                    // mp3[arr[i]] --;
                    // if(mp3[arr[i]] == 0)
                        mp3.erase(arr[i]);
                }
            }
            
            return v;
            
            
}


// Better Solution

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    
    vector <int> res;
    int last = INT_MIN;
    while (i < n1 and j < n2 and k < n3)
    {
        if (A[i] == B[j] and A[i] == C[k] and A[i] != last) 
        {
            res.push_back (A[i]);
            last = A[i];
            i++;
            j++;
            k++;
        }
        else if (min ({A[i], B[j], C[k]}) == A[i]) i++;
        else if (min ({A[i], B[j], C[k]}) == B[j]) j++;
        else k++;
    }
    return res;
}