/*
Given a string s, remove all its adjacent duplicate characters 
recursively. 
*/

string remove(string s){
    int n = s.size();
    if(n <= 1)
        return s;
    
    string check = s;
    string str = "";
    
    if(s[0] != s[1])
        str += s[0];
        
    for(int i = 1; i < n - 1; i ++){
        if(s[i] != s[i + 1] && s[i] != s[i - 1]){
            str += s[i];
        }
    }
    
    if(s[n - 1] != s[n - 2])
        str += s[n - 1];
        
    if(str == check)
        return check;
        
    return remove(str);
    
    
}