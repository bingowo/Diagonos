#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int* a,int b)
{
    int m[100];
    memset(m,0,sizeof(m));
    m[0]=b%10;
    m[1]=b/10;
    for(int i=0;i<99;i++){
        a[i]+=m[i];
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }

}
void mul(int* a,int b)
{
    for(int i=0;i<100;i++){a[i]*=b;}
    for(int i=0;i<99;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
}
int main()
{
    int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int bet[25],count=0,num,result[100];
    char c;
    memset(result,0,sizeof(result));
    while(scanf("%d",&num)==1){
        bet[count++]=num;
        c=getchar();
        if(c=='\n')break;
    }
    for(int i=0;i<count;i++){
        mul(result,prime[count-1-i]);
        add(result,bet[i]);
    }
    int end=99;
    while(result[end]==0 && end>0){end--;}
    for(int i=end;i>=0;i--){printf("%d",result[i]);}
    printf("\n");
    return 0;
}
