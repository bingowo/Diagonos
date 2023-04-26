#include <stdio.h>
#include <stdlib.h>
int a,n;
int add(int x,int m)      //通过m 求第二站上下车人数d
{
    int s1,s2,T,d,c,j,z2;


    for(d=1;;d++){
        c=n-3;
        s2=d;
        z2=a;
        s1=a;
        while(c--){
            T=z2+s1;
            j=s2;
            s2=j+s1;
            s1=j;
            z2=T;
        }
        if(T==m) break;

    }
    return d;
}

int count(int x,int m)       //第x站的
{
    int d,c,T,z2,s1,s2,j;
    d=add(x,m);
    c=x-2;
    s2=d;
    z2=a;
    s1=a;
    while(c--){
            T=z2+s1;
            j=s2;
            s2=j+s1;
            s1=j;
            z2=T;
        }
    return T;




}






int main()
{
    int m,x,r;
    scanf("%d%d%d%d",&a,&n,&m,&x);

    if(x==1) r=a;
    else if(x==2) r=a;
    else if(x==n) r=0;
    else if(x==(n-1)) r=m;
    else r=count(x,m);
    printf("%d",r);

}

