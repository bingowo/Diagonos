#include<stdio.h>
#include<string.h>
#define L 500
int l=0,q1=0,q2=0,sign=1;

void input(int a[],int b[])///输入
{
int i1=0,i2=0,j1=0,j2=0,k1=0,k2=0,c1=0,c2=0,x=0,i=0,j=0,d1=0,d2=0;
 char s1[2*L+1];char s2[2*L+1];
 scanf("%s",s1);
 scanf("%s",s2);

 while(s1[i1]&&s1[i1]!='.') i1++;
 for(j1=i1-1,k1=L;j1>=0;j1--,k1--)
 a[k1]=s1[j1]-'0';
 for(j1=i1+1,k1=L+1;j1<strlen(s1);j1++,k1++)
 a[k1]=s1[j1]-'0';
 q1=k1;

 while(s2[i2]&&s2[i2]!='.') i2++;
 for(j2=i2-1,k2=L;j2>=0;j2--,k2--)
 b[k2]=s2[j2]-'0';
 for(j2=i2+1,k2=L+1;j2<strlen(s2);j2++,k2++)
 b[k2]=s2[j2]-'0' ;
 q2=k2;
 ////符号问题
 c1=strlen(s1);
 c2=strlen(s2);
 d1=c1-q1+L+1;
 d2=c2-q2+L+1;
 if(d1>d2) sign=1;
 else if(d1<d2) sign=-1;
 else {for(i=0;i<2*L+1&&a[i]==b[i];i++);
 if(i<2*L+1)
 {if(a[i]>b[i]) sign=1;
 else sign=-1;
 }
if(i==2*L+1) sign=1;

                }
}

void sub(int a[],int b[],int N)///计算
{int n=0;
 if(sign==1)
 {if(q1-1<L+N)//////////0的问题
   {for(n=q1;n<=L+N;n++)
     a[n]=0;
   }
 else n=0;
 int k=0,t,x=0,i=0;
 for(t=2*L;t>L+N;t--)
   {a[t]=a[t]-b[t]-x;
    if(a[t]<0)
       {a[t]+=10;
        x=1;
       }
    else x=0;
   }

 if(a[t+1]>=5)  a[t]++;///四舍五入
 else t=L+N;

 for(t=L+N;t>0;t--) //有没有=
    {a[t]=a[t]-b[t]-x;
      if(a[t]<0)
       {a[t]+=10;
        x=1;
       }
      else x=0;
    }
  t=0;
  while(a[t]==0) t++;///如果减完，高数位为0，则把0去掉
  l=t;
 }

 else if(sign==-1)
 {if(q2-1<L+N)//////////0的问题
   {for(n=q2;n<=L+N;n++)
     b[n]=0;
   }
 else n=0;
 int k=0,t,x=0,i=0;
 for(t=2*L;t>L+N;t--)
   {b[t]=b[t]-a[t]-x;
    if(b[t]<0)
       {b[t]+=10;
        x=1;
       }
    else x=0;
   }

 if(b[t+1]>=5)  b[t]++;///四舍五入
 else t=L+N;

 for(t=L+N;t>0;t--) //有没有=
    {b[t]=b[t]-a[t]-x;
      if(b[t]<0)
       {b[t]+=10;
        x=1;
       }
      else x=0;
    }
  t=0;
  while(b[t]==0) t++;///如果减完，高数位为0，则把0去掉
  l=t;
 }

 else sign=0;

}

void output(int a[],int N)///输出
{int t=0,k=0;
 while(t<=L&&a[t]==0) t++;///整数位
 if(t>L) printf("0");
 else {for(t=l;t<=L;t++)
        printf("%d",a[t]);
       }
 printf(".");
 t=L+1;

     for(t=L+1;t<=L+N;t++)///小数位
     printf("%d",a[t]);
     printf("\n");

}

int main()
{int a[2*L+1]={0},b[2*L+1]={0},N,t=L,c=0,d=0,y=1;
 input(a,b);
 scanf("%d",&N);
 sub(a,b,N);
 if(sign==1) output(a,N);
 else if(sign==-1)
   {printf("-");
    output(b,N);
   }

 else
     {printf("0.");
      for(t=L+1;t<=L+N;t++)
      printf("0");
      printf("\n");
     }
 return 0;
}
