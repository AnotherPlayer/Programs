#include<stdio.h>
#include<stdlib.h>

int cutRodRecur(int i, vector<int> &price) {
    
    // Base case
    if(i==0)
        return 0;
    
    int ans = 0;
    
    for (int j=1 ; j<=i ; j++) 
        ans = max(ans, price[j-1]+cutRodRecur(i-j, price));
        
    return ans;

}

int cutRod(vector<int> &price) {

    int n = price.size();
    return cutRodRecur(n, price);
    
}

int main(){

    int price;
    int[] price = {2,4,5,10,15,20};

    printf("Digite una longitd para la varilla");
    scanf("%d",);

}