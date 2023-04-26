#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long A,B;
    scanf("%lld%lld",&A,&B);
    long long N=A/B;
    long long t=A%B;
    long long b=B;
    int rn1[10000]={0};
    int rn2[10000]={0};
    int t1[10000]={0};
    int t2[10000]={0};
    int k=0,l=0,flag=0;
    if(t!=0)
    {
        do
        {
            int r2=t%3;
            rn2[l++]=r2;
            t=t/3;
            b=b/3;
        }while(b!=1);
        for(int i=0;i<l;i++)
        {
            if(flag==0)
            {
                if(rn2[i]!=2) t2[i]=rn2[i]+1;
                else {
                    t2[i]=0;
                    flag=1;
                }
            }
            else if(flag==1)
            {
                if(rn2[i]!=0) t2[i]=rn2[i]-1;
                else{
                    t2[i]=2;
                    flag=0;
                }
            }
        }
    }
    if(N!=0){
    do{
        int r1=N%3;
        rn1[k++]=r1;
        N=N/3;
    }while(N);
    for(int i=0;i<k;i++)
        {
            if(flag==0)
            {
                if(rn1[i]!=2) t1[i]=rn1[i]+1;
                else {
                    t1[i]=0;
                    flag=1;
                }
            }
            else if(flag==1)
            {
                if(rn1[i]!=0) t1[i]=rn1[i]-1;
                else{
                    t1[i]=2;
                    flag=0;
                }
            }
        }
        if(flag==1) t1[k]=1;
    }
    for(int i=0;i<k;i++)
    {
        t1[i]=t1[i]-1;
        if(t1[i]==-1) t1[i]=2;
    }
     for(int i=0;i<l;i++)
    {
        t2[i]=t2[i]-1;
        if(t2[i]==-1) t2[i]=2;
    }
    int c=0,d=0;
    int *p=&t1[k];
    for(int m=k;m>=0;m--)
    {
        if(*p!=0)
        {
            c=m;
            break;
        }
        p--;
    }
    int *q=t2;
     for(int m=0;m<l;m++)
    {
        if(*q!=0)
        {
            d=m-1;
            break;
        }
        q++;
    }
    if((A/B)!=0){
    for(int j=c;j>=0;j--) printf("%d",t1[j]);}
    else if(flag==1) printf("1");
    else printf("0");
    if((A%B)!=0){
            printf(".");
    for(int j=d;j>=0;j--) printf("%d",t2[j]);}
    return 0;
}
