#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    int a1=*(int*)a,b1=*(int*)b;
    if (a1>b1) return 1;
    else return -1;
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a[1002];
    int min=1;
    memset(a,0,sizeof(a));

    for (int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if (a[min]>a[i]) min=i;
    }
    int z=0;
    qsort(a,n,sizeof(a[1]),cmp);
    a[n]=1000009;
    int d;
    for (int i=0;i<=n&&s>0;i++){
        while (a[i]==a[i+1]) i++;
        int sum=(a[i+1]-a[i])*(i+1);

        if (s>sum) {s=s-sum;}
        else {z=a[i]+s/(i+1);d=i+1;s=s%(i+1);break;}
    }
    if (s==0) printf("%d",z);
    else {
        if (z!=0)
        printf("%d",z);
        int gcdans=gcd(s,d);
        s=s/gcdans;
        d=d/gcdans;
        printf("+%d/%d",s,d);
    }

    return 0;
}