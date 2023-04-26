#include<stdio.h>
#include<string.h>
int main()
{char a[100]={'\0'},b[100]={'\0'},e[100]={'\0'},f[100]={'\0'};
 int c[100]={0},d[100]={0},x=0,i,j,k,c1,c2,r,q,p=0,t,w,u,g=0,l,p1,p2;
 while(scanf("%s",a)!=EOF&&scanf("%s",b)!=EOF)
  {c1=strlen(a);
   c2=strlen(b);
   p1=c1;
   p2=c2;
    if(c1<c2)
    {strcpy(e,b);
     strcpy(f,a);
     strcpy(a,e);
     b[0]='\0';
     strcpy(b,f);
     u=c1;c1=c2;c2=u;
    }
    else if(c1=c2)
          {for(i=0;i<c1;i++)
              {if(a[i]>=b[i]) continue;
               else break;
              }
           i--;
           w=i;;
           if(i!=c1-1)
             {strcpy(e,b);
              strcpy(f,a);
              strcpy(a,e);
              b[0]='\0';
              strcpy(b,f);
              u=c1;c1=c2;c2=u;
              }

          }
    else ;


    if(c1==1) {g=a[0]-b[0];printf("%d",g);}
    else {
    for(i=0;i<c1/2;i++)
               {t=a[i];a[i]=a[c1-i-1];a[c1-i-1]=t;}
    for(j=0;j<c2/2;j++)
               {w=b[j];b[j]=b[c2-j-1];b[c2-j-1]=w;}

    for(j=c2;j<c1;j++)
            b[j]='0';
    for(l=0;l<c1;l++)
       {c[l]=a[l]-b[l]-x;
        if(c[l]<0)
            {x=1;
             c[l]+=10;
            }
        else x=0;
       }
    while(c[l]!='0'&&l>=0)
        {l--;}
    l++;
    l=q;
    for(p=0,l=c1-1;l>=q;l--,p++)
            {u=c[l];c[l]=d[p];d[p]=u;}
    if(p1>p2||(p1==p2&&w==p1-1))
            {for(p=0;p<c1-1-q;p++)
            printf("%d",d[p]);
            printf("\n");
            }
    if(p1<p2||(p1==p2&&w!=p1-1))
            {printf("-");
            for(p=0;p<c1-1-q;p++)
            printf("%d",d[p]);
            printf("\n");
            }

    }
  }
 return 0;
}
