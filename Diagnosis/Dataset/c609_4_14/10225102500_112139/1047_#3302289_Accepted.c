#include <stdio.h>
#include <stdlib.h>
    typedef struct big{
    int cnt;
    int num[100];
    } BIGINT;
    void MUL(int* e1,int e2){
    for(int j=0;j<99;j++){
    e1[j]=e1[j]*e2;
    }
    for(int j=0;j<98;j++){
    int carry;
    carry=e1[j]/10;
    while(carry>0){
    e1[j+1]=e1[j+1]+carry;
    e1[j]=e1[j]%10;
    carry=e1[j]/10;
    }
    }

    }
    int main()
    {int t;
     scanf("%d",&t);
     for(int k=0;k<t;k++){
            printf("case #%d:\n",k);
     int a,n;
     scanf("%d %d",&a,&n);
     BIGINT sum={1,{1}};
     for(int i=0;i<n;i++){
     MUL(sum.num,a);
     }
     int i;
     for( i=99;i>=0;i--){
     if(sum.num[i]!=0) break;
     }
     for(;i>=0;i--){
     printf("%d",sum.num[i]);
     }
     printf("\n");
     }

    return 0;
    }
