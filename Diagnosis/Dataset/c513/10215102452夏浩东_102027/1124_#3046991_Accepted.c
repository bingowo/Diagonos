#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b; 
}
int gcd(int a,int b)
{
    if(a%2==0 && b%2==0) return 2;
    if(b%a==0) return a;
    else return gcd(b%a,a);
}
int main()
{
    int num=0; scanf("%d",&num);
    int L[1000],NL[1000];
    for(int mm=0;mm<num;mm++){
        long long int res=0;
        int cnt=0; scanf("%d",&cnt);
        for(int len=0;len<cnt;len++){
            scanf("%d",&L[len]);
        }
        qsort(L,cnt,sizeof(int),cmp);
        NL[0]=L[0]; int k=1;
        for(int i=1;i<cnt;i++){
            if(L[i]!=L[i-1]) NL[k++]=L[i];
        }
        for(int i=0;i<k-1;i++){
            for(int j=i+1;j<k;j++){
                if(gcd(NL[i],NL[j])==1){
                    res++;
                }
            }
        }
        printf("case #%d:\n",mm);
        printf("%lld\n",res);
    }
    return 0;
}