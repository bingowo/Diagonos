#include <stdio.h>
struct p{
  int up;
  int down;
  int num;
};
int L[]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181};
int main()
{
    int a=0,b=0,n=0,m=0,x=0;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x==1) printf("%d",a);
    else if(x==2) printf("%d",a);
    else if(x==3) printf("%d",2*a);
    else {
        int num1=L[n-5];
        int num2=L[n-4];
        b=(m-(num1+1)*a)/(num2-1);
        struct p L[20];
        L[0].up=a;
        L[0].down=0;
        L[0].num=a;
        L[1].up=b;
        L[1].down=b;
        L[1].num=a;
        for(int i=2; i<x ;i++)
        {
            L[i].up=L[i-1].up+L[i-2].up;
            L[i].down = L[i-1].up;
            L[i].num=L[i-1].num+L[i].up-L[i].down;
        }
        printf("%d",L[x-1].num);
    }
    return 0;
}