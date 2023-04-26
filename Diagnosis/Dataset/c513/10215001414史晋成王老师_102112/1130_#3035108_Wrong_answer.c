#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int power(int x,int y)
{ int i,j,n,m;
n=1;
for(i=1;i<=y;i++)
 {n*=x;}
 return n;
}
struct cre
{
    int up;
    int down;
};
int cmp(const void*a,const void*b)
{
    struct cre x,y;
    x=*((struct cre*) a);
    y=*((struct cre*) b);
    return x.up-y.up;
}
int main()
{  struct cre b[1000];
     long long int a[1100];
    int k,i,j,n,m,T,f,flag,l,a1;  double x,y;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {scanf("%lld",&a[i]);}
    for(i=0;i<T;i++)
    {f=0;flag=0;
     for(j=2;j<=50;j++)
       { y=j; x=a[i];
       a1=(int)pow(x,1.0/y);
       if(pow(a1,y)==x&&a1>=2) {b[f].down=a1; b[f].up=y;flag=1;f++;}
       else if(pow(a1+1,y)==x&&a1>=1) {b[f].down=a1+1; b[f].up=y;flag=1;f++;}
       }
       
       if(flag==0) printf("%d is powerless.\n",a[i]); 
       else
       {
           qsort(b,f,sizeof(b[0]),cmp);
           printf("%lld",a[i]);
           for(l=0;l<f;l++)
           printf("=%d^%d",b[l].down,b[l].up);
           printf("\n");
       }
    }
}