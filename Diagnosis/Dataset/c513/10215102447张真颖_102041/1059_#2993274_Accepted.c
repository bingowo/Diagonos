#include <stdio.h>
#include <stdlib.h>

int cmp(const void* pa,const void* pb)
{
    int a=*(int*)pa,b=*(int*)pb;
    return a-b;
}
int gcd(int m,int n)
{
    return n==0?m:gcd(n,m%n);
}

int main()
{
    int n=0,s=0;
    scanf("%d%d",&n,&s);
    int a[1000]={0};
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);//按从低到高排
    int ls=s,ih=a[0],fzh=0,fmh=1,w=0;
    while(ls>0)
    {
        for(;w<n;w++)
        {
            if(a[w]>a[0])
            {
                if(ls>=w*(a[w]-a[w-1]))
                {
                    ls-=w*(a[w]-a[w-1]),ih=a[w];
                    for(int j=0;j<w;j++)
                        a[j]=a[w];
                }
                else
                {
                    ih+=ls/w;
                    ls%=w;
                    if(ls)
                    {
                        fzh=ls/gcd(w,ls);
                        fmh=w/gcd(w,ls);
                        ls=0;
                    }
                }
                break;
            }
        }
        if(w==n&&ls)
        {
            ih+=ls/w;
            ls%=w;
            fzh=ls/gcd(w,ls);
            fmh=w/gcd(w,ls);
            ls=0;
        }
    }
    if(ih==0)
    {
        if(fzh)
            printf("%d/%d",fzh,fmh);
        else printf("0");
    }
    else
    {
        printf("%d",ih);
        if(fzh)
            printf("+%d/%d",fzh,fmh);
    }
    return 0;
}