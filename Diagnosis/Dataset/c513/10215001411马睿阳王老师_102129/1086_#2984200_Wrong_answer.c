#include<stdio.h>
#include<string.h>
#define L 500
int l=0,q=0;

void input(int a[])///输入
{int i=0,j,k,n=0;
 char s[2*L+1];
 scanf("%s",s);
 while(s[i]&&s[i]!='.') i++;
 for(j=i-1,k=L;j>=0;j--,k--)
 a[k]=s[j]-'0';
 for(j=i+1,k=L+1;k<strlen(s);j++,k++)
 a[k]=s[k]-'0';
 q=k;
}

void sub(int a[],int b[],int N)///计算
{int n=0;
 if(q-1<L+N)
   {for(n=q;n<=L+N;n++)
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

void output(int a[],int N)///输出
{int t=0,k=0;
 while(t<=L&&a[t]==0) t++;///整数位
 if(t>L) printf("0");
 else {for(t=l;t<=L;t++)
        printf("%d",a[t]);
       }
 printf(".");
 t=L+1;

     for(t=L+1;t<=L+N;t++);///小数位
     printf("%d",a[t]);
     printf("\n");
}

int main()
{int a[2*L+1]={0},b[2*L+1]={0},N,t=L,c=0,d=0,y=1;
 input(a);
 input(b);
 scanf("%d",&N);
 ///比较大小，得出符号
 while(t>=0)
   {c+=a[t]*y;
    t--;
    y*=10;
   }
 t=L+1,
 y=1/10;
 while(t<=L+N)
   {c+=a[t]*y;
    t++;
    y/=10;
    }


 while(t>=0)
   {d+=b[t]*y;
    t--;
    y*=10;
   }
 t=L+1;
 y=1/10;
 while(t<=L+N)
   {d+=b[t]*y;
    t++;
    y/=10;
    }


 if(c<d)
    {printf("-");
     sub(b,a,N);
     output(b,N);
    }
 else if(c==d)
    {printf("0.");
     for(t=L+1;t<=L+N;t++)
      {printf("0");}
      printf("\n");
    }

 else
    {sub(a,b,N);
     output(a,N);
     }
 return 0;
}