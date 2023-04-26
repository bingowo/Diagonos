#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x<=y?-1:1;
}
int gcd(int a,int b)
{
    int divi=0;
    while(a%b)
    {
        divi=a%b;
        a=b;
        b=divi;
    }
    divi=b;
    return divi;
}
int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int a[1000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int i,z,ans=0;
    for(i=0;i<n-1;i++)
    {
        z=(a[i+1]-a[i])*(i+1);
       ans+=z;
       if(ans>=s)break;
    }
    if(ans==s)
    {
        printf("%d",a[i+1]);
    }
    else if(ans>s)
    {
        int x=z-ans+s;
        if(x%(i+1)==0)
            printf("%d",a[i]+x/(i+1));
        else
        {
            if((a[i]+x/(i+1))!=0)
            printf("%d+",a[i]+x/(i+1));
            int r=x%(i+1),k=gcd(r,i+1);
            printf("%d/%d",r/k,(i+1)/k);

        }

    }
    else
    {
        if((s-ans)%n==0)
            printf("%d",a[n-1]+(s-ans)/n);
        else
        {
            if((a[n-1]+(s-ans)/n)!=0)
            printf("%d+",a[n-1]+(s-ans)/n);
            int m=(s-ans)%n,p=gcd(m,n);
            printf("%d/%d",m/p,n/p);
        }
    }
    return 0;

}
