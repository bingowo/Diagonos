#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a,b,t,h,m=0;
    scanf("%lld%lld",&a,&b);
    int i=0,k,j,temp;
    for(;b!=1;i++)
    {
        b/=3;
    }
    int p[100]={0};
    if(a<0){a=-a;m++;}
    for(k=0;a!=0;k++)
    {
        p[k]=a%3;
        a/=3;
    }
    for(j=0;j<k;j++)
    {
        temp=p[j]+1;
        p[j]=temp%3;
        p[j+1]+=temp/3;
        p[j]--;
        if(p[j]<0) p[j]=2;
    }
    if(p[j]){k++;}
    if(m){
            for(j=0;j<k;j++)
            {
                if(p[j]==1) p[j]=2;
                    else{if(p[j]==2)p[j]=1;}


            }}
    for(t=0;p[t]==0;t++);
    if(k>i){h=k-1;}
    else {h=i-1;printf("0");}
    if(t>i){t=i;}
    for(;h>=t;h--)
    {
        if(h==(i-1))printf(".");
        printf("%d",p[h]);

}


}
