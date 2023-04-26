#include<stdio.h>
#define L 1001
int a,b,k=0;
typedef struct {
  int  re;
  int  im;
  char op;
 }com;

 void complexinput(com complex)
 {
  char c;
  scanf("%d%c%d",&a,&b,&c);
  complex.re=a;
  complex.im=b;
  complex.op=c;
 }

 void complexoutput(com complex[L])
 {int j=0,i=0;
  complex.re=a;
  complex.im=b;
  complex.op=c;
  for(i=0;i<=k;i++)
      printf("%d",complex.re[i]);
  printf("%c",op);
  for(j=0;j<=k;j++)
      printf("%d",complex.im[j]);
 }

 int main()
 {com c;
  complexinput(c);
  int i=0,j=0,t=0,n,m=0,l=0,x=0;
  scanf("%d",&n);
  com d[L];
if(c.re==0&&c.im==0&&n==0) printf("0");
else
 {for(i=0;i<n;i++)
     {for(l=0;l<=k;l++)
          {d[l].re=d[i-1].re*a-d[i-1].im*b;
           d[i].im=d[i-1].re*b+d[i-1].im*a;
          }
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
