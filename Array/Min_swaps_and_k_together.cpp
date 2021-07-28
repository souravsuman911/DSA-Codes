int minSwap(int *arr, int n, int a) {
    
    if(n <= 2)
    return 0;

    int count = 0;
    int countb = 0;

    for(int i = 0; i < n; i ++){
        if(arr[i] <= a)
            count ++;
    }

    for(int i = 0; i < count; i ++){
        if(arr[i] > a)
            countb ++;
    }

    int minm = countb;

    for(int i = 1; i <= n - count; i ++){
        if(arr[i - 1] > a)
            countb --;
        
        if(arr[i + count - 1] > a)
            countb ++;
            
        minm = min(minm, countb);
    }

    return minm;
}

/*

Find count of all elements which are less 
than or equals to ‘k’. Let’s say the count
 is ‘cnt’.

Using two pointer technique for window of 
length ‘cnt’, each time keep track of how 
many elements in this range are greater 
than ‘k’. Let’s say the total count is 
‘countb’.

Repeat step 2, for every window of 
length ‘cnt’ and take minimum of count 
‘countb’ among them. This will be the final answer.


*/
