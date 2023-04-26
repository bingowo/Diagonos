#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int reverse(int num){
    int n=num;
    int arr[32]={0};
    int j=0;
    while(n!=0){
        arr[j]=n%2;
        n/=2;
        j++;
    }
    //for(int k=0;k<32;k++) printf("%d",arr[k]);
    //printf("%d",j);
    int max=1,temp=1;
    for(int k=0;k<j;k++){
        if((arr[k]!=arr[k+1]) && (k+1)!=j){
            temp++;
            if(temp>max) max=temp;
        }
        else if((arr[k]==arr[k+1]) && (k+1)!=j){
            temp=1;
        }
    }
    return max;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        int num=0;
        scanf("%d",&num);
        int max=0;
        max=reverse(num);
        printf("%d\n",max);
    }
    return 0;
}
