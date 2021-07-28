/*

Given an array Arr of size N such that each element is from the range 0 to 9. 
Find the minimum possible sum of two numbers formed using the elements of the array. 
All digits in the given array must be used to form the two numbers.

*/

string solve(int arr[], int n) {
    
    sort(arr, arr + n);
    string res;
    int sum;
    int carry = 0;

    for(int i = n - 1; i >= 1; i -=2){
        sum = arr[i] + arr[i - 1] + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if(n % 2 != 0){
        sum = arr[0] + carry;
        carry = sum / 10;
        res += (sum % 10) + '0';
    }

    res += carry + '0';

    while(!res.empty() && res.back() == '0')
        res.pop_back();
        
    reverse(res.begin(), res.end());

    return res;
}