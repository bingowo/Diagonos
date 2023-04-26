#include<stdio.h>
#include<string.h>
#define L 1001
int a,b,k=0;
typedef struct{
  int  re;
  int  im;
  char op;
 }com;

 int main()
 {char s[L];
  int i=0,j=0,k=0,q=0,w=0,p=0;
  ///输入部分
  scanf("%s",&s);
  while(isdigit(s[i])) i++;
  q=i;//q为符号的位置,q前为实部，q后为虚部
  i=q+1;
  while(isdigit(s[i])) i++;
  w=i-1;//w为虚部的最后一位
  com d[L]={0},c[L]={0};//c为不变要乘的值，d为最后的结果
  for(j=0,i=q-1;i>=0;i--,j++)
       {d[j].re=s[i];
        c[j].re=s[i];
       }
  for(j=0,i=w;i>q;i--,j++)
       {d[j].im=s[i];
        c[j].im=s[i];
  int i=0,j=0,t=0,n,m=0,l=0,x=0;
  scanf("%d",&n);

///计算部分
  com temp1[L]={0},temp2[L]={0};
if(d[0].re==0&&d[0].im==0&&n==0) printf("0\n");
else
 {for(i=0;i<n;i++)
     {//先计算虚部
      for(l=0;l<=k;l++)
          {temp1[l]=d[l].im*c[l].re;
      for(l=0;l<=k;l++)
          {if(d[l].re>=10)
               {d[l+1].re+=d[l].re/10;
                d[l].re%=10;
                if(l==k) k++;
               }
           else if(d[l].re<0)
                {x=1;
                 d[l+1].re-=x;
                 d[l].re+=10;
                }

           }
      if(d[k].re==0) k--;

      for(l=0;l<=k;l++)
          {if(d[l].im>=10)
               {d[l+1].im+=d[l].im/10;
                d[l].im%=10;
                if(l==k) k++;
               }
           else if(d[l].im<0)
                {x=1;
                 d[l+1].im-=x;
                 d[l].im+=10;
                }

           }
      if(d[k].im==0) k--;
    ///倒置
    for(j=0;j<=k/2;j++)
        {m=d[j].re;
         d[j].re=d[k-j].re;
         d[k-j].re=m;
        }
    for(j=0;j<=k/2;j++)
        {t=d[j].im;
         d[j].im=d[k-j].im;
         d[k-j].im=t;
         }
    complexoutput(d);
    }


 }
 return 0;

 }
