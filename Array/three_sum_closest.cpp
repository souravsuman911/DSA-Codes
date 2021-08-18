/*
Given an array Arr of N numbers and another number target, 
find three integers  in the array such that the sum is closest 
to target. Return the sum of the three integers.
*/

int threeSumClosest(vector<int> arr, int target) {
        
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int absolute = INT_MAX;
    int min_sum;
    
    for(int i = n - 1; i >= 0; i --){
        int j = i - 1;
        int k = 0;
        
        while(k < j){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < target){
                if(abs(target - sum) == absolute){
                    min_sum = max(min_sum, sum);
                }
                else if(abs(target - sum) < absolute){
                    absolute = abs(target - sum);
                    min_sum = sum;
                }
                k ++;
            }
            else if(sum > target){
                if(abs(target - sum) == absolute){
                    min_sum = max(min_sum, sum);
                }
                else if(abs(target - sum) < absolute){
                    absolute = abs(target - sum);
                    min_sum = sum;
                }
                j --;
            }
            else{
                return sum;
            }
        }
    }
    
    return min_sum;
}