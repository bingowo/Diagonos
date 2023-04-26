#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)//最小公约数

{  int t,r;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }


    r=m%n;
    if(r==0)
        {return n;}
    else
    {
        GCD(n,r);          //递归 看高代
    }

}
int main ()
{
    int n,i,j;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
    char s[120];
    gets(s);
    int a,a1=0,a0=0,t;
    a=(int)s;
    while(a>0){       //求0和1个数
        t=a%2;
        if(t==1){a1++;}
        if(t==0){a0++;}
        a=a/2;
    }

    int x,r,zong;
    zong=a1+a0;
    if(zong==a1) printf("1\n");
    else{
    x=GCD(a1,zong);
    a1=a1/x;
    zong=zong/x;
    printf("%d/%d\n",a1,zong);

    }


    }
}