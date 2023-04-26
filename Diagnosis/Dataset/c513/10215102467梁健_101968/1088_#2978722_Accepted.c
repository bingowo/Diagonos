#include<stdio.h>
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int m,n;scanf("%d %d",&m,&n);
        unsigned long long res=1;
        for(int q=m;q>=(m-n+1);q--){
            res*=q;
            res/=(m-q+1);
        }
        printf("%llu\n",res);
    }
}
