#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        chars[61];
        scanf("%s",s);
        int a[128];for(inti=0;i<128;i++)a[i]=-1;
        int r=0;
        char *p=s;
        a[*p]=1;
        p++;
        while(*p)
        {
            if(a[*p]==-1){
                a[*p]=r;
                r=r?r+1:2;
                p++;
            }
        }
        if(r<2){
            r=2;
        }
        long long int n=0;
        p=s;
        while(*p){
            n=n*r+a[*p++];
        }
        printf("case#%d:\n%lld\n",cas,N);
    }
    return 0;
}