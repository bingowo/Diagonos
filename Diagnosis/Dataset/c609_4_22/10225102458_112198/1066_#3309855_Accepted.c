#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int bingo(int i,int* a,int n)
{
    if(!i)return 1;
    if(!n)return 0;//相加，相减，相同
    return bingo(i-*a,a+1,n-1)||bingo(i+*a,a+1,n-1)||bingo(i,a+1,n-1);
}
int main()
{
    int n,t=0;
    scanf("%d",&n);
    int wei[n];
    for(int i=0;i<n;i++){scanf("%d",wei+i);t+=wei[i];}
    //qsort(wei,n,sizeof(wei[0]),cmp);
    for(int i=1;i<=t;i++){
        printf("%d",bingo(i,wei,n));
    }
    return 0;

}
