vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
{
    vector<int> ans;
    
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    
    while(left <= right && top <= bottom){
        for(int i = left; i <= right && top <= bottom; i ++){
            ans.push_back(arr[top][i]);
        }top ++;
        
        for(int i = top; i <= bottom && left <= right; i ++){
            ans.push_back(arr[i][right]);
        }right --;
        
        for(int i = right; i >= left && top <= bottom; i --){
            ans.push_back(arr[bottom][i]);
        }bottom --;
        
        for(int i = bottom; i >= top && left <= right; i --){
            ans.push_back(arr[i][left]);
        }left ++;
    }
    
    return ans;
}