// given an array of distinct element

int minSwaps(vector<int>&nums)
{
    int n = nums.size(), count = 0;
    map<int, int> mp;
    
    for(int i = 0; i < n; i ++)
        mp[nums[i]] = i;
    
    auto it = mp.begin();
    for(int i = 0; i < n && it != mp.end(); i ++, it ++){
        if(it -> first != nums[i]){
            count ++;
            mp[nums[i]] = mp[it -> first];
            swap(nums[i], nums[mp[it -> first]]);
        }
    }
    
    return count;
}