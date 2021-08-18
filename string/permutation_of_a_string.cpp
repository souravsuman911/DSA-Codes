/*
Given a string S. The task is to print all permutations of a 
given string.
Return them in sorted order.
*/

void permute(string s, int l, int r, vector<string> &ans){
    if(l == r){
        ans.push_back(s);
        return;
    }
    else{
        for(int i = l; i <= r; i ++){
            swap(s[i], s[l]);
            permute(s, l + 1, r, ans);
            swap(s[i], s[l]);
        }
    }
}

vector<string>find_permutation(string s)
{
    vector<string> ans;
    permute(s, 0, s.size() - 1, ans);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}