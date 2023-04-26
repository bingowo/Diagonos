#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a,b,t,h;
    scanf("%d%d",&a,&b);
    int i=0,k,j,temp;
    for(;b!=1;i++)
    {
        b/=3;
    }
    int p[100]={0};
    for(k=0;a!=0;k++)
    {
        p[k]=a%3;
        a/=3;
    }
    for(j=0;j<k;j++)
    {
        temp=p[i]+1;
        p[i]=temp%3;
        p[i+1]+=temp/3;
        p[i]--;
        if(p[i]<0) p[i]=2;
    }
    if(p[j]){k++;}
    if(a<0){
            for(j=0;j<k;j++)
            {
                if(p[j]==1) p[j]=2;
                    else{if(p[j]==2)p[j]=1;}


            }}
    for(t=0;p[t]==0;t++);
    if(k>i){h=k-1;}
    else {h=i-1;printf("0");}
    for(;h>=t;h++)
    {
        if(h==(i-1))printf(".");
        printf("%d",p[h]);

}


}
