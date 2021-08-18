static bool myComp(Item a1, Item a2){
    double pw1 = double(a1.value) / double(a1.weight);
    double pw2 = double(a2.value) / double(a2.weight);
    
    return pw1 > pw2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, myComp);

    double profit = 0;
    int i = 0;
    
    while(i < n){
        if(W - arr[i].weight < 0)
            break;
            
        profit += arr[i].value;
        W -= arr[i].weight;
        i ++;
    }
    
    if(i == n)
        return profit;
        
    if(W > 0){
        profit += ((double(arr[i].value) / double(arr[i].weight)) * W);
    }

    return profit;
}