vector<int> factorial(int n){
    vector<int> v;
    v.push_back(1);
    
    int pro = 1, carry = 0;
    for(int i = 2; i <= n; i ++){
        for(int j = v.size() - 1; j >= 0; j --){
            pro = v[j] * i + carry;
            carry = pro / 10;
            v[j] = pro % 10;
        }
        while(carry){
            v.insert(v.begin(), carry % 10);
            carry /= 10;
        }
    }
    
    return v;
    
}