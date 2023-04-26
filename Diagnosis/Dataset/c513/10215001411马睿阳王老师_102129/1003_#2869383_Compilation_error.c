#include<stdio.h>
struct data
{ long long int a;//整数
  int n;//1的位数
}

int main()
{ int i,n,T;struct data p[1000];//输入
  scanf("%d",&T);
  for(i=0;i<T;i++)
  {scanf("%d",&p[i].a);
  int sign;
  if(a<0) {a=-a;sign='-';}//进制转换
  int c,s[1000],j,x,m;
  while(a) 
  {c=a%2;c=c/2;
   s[j]=c+'0';
   j++;
  }
  if(sign=='-1') {s[j]='-';}
  else j--;
  for(x=0;x<j/2;x++)
  {m=a[x];a[x]=a[j-x];a[j-x]=m;}
  s[j+1]=0;
   int d=1,t;p[i].n=0;
   for(t=0;t<64;t++)
   {if(p[i].s[t]&d)} {p[i].n++;d=d<<1;}
    } 
    //qsort
    //输出


}


int cmp(const void*a,const void*b)//比较函数
{ struct data d1,d2;
  d1=*((struct data*)a);
  d2=*((struct data*)b);
  if(d2.number!=d1.number)
  return d2.number-d1.number;
  else {if(d1.a>d2.a) return 1;
         else return -1; }
}
