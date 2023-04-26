#include <stdio.h>
#include <stdlib.h>

int f1(int zhanshu)
{
    if(zhanshu==1) return 1;
    else if(zhanshu==2) return 0;
    return f1(zhanshu-1)+f1(zhanshu-2);
}

int f2(int zhanshu)
{
    if(zhanshu==1) return 0;
    else if(zhanshu==2) return 1;
    return f2(zhanshu-1)+f2(zhanshu-2);
}

int main()
{
    int a=0,n=0,m=0,x=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x<=2) printf("%d\n",a);
    else{
        int an=0,wn=0,w=0,an1=0,wn1=0,ans=0;
        for(int i=1;i<n;i++){
        an+=f1(i);
        wn+=f2(i);}
        for(int j=1;j<n-1;j++){
        an1+=f1(j);
        wn1+=f2(j);}
        an1--;
        wn1++;
        w=(m-(an-an1)*a)/(wn-wn1);
        an=0,wn=0,an1=0,wn1=0;
        for(int e=1;e<=x;e++){
        an+=f1(e);
        wn+=f2(e);}
        for(int k=1;k<=x-1;k++){
        an1+=f1(k);
        wn1+=f2(k);}
        an1--;
        wn1++;
        ans=a*(an-an1)+w*(wn-wn1);
        printf("%d\n",ans);
    }
    return 0;
}
