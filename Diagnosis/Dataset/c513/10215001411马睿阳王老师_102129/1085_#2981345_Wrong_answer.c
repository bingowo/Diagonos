#include<stdio.h>
#include<string.h>

int main()
{char a[1000]={'\0'},b[1000]={'\0'},e[1000]={'\0'},f[1000]={'\0'};
 int c[1000]={0},d[1000]={0},x=0,i=0,j=0,c1,c2,r=0,q=0,p=0,t=0,w=0,u=0,g=0,l=0,p1=0,p2=0,h=0,y,z;
 while(scanf("%s",a)!=EOF&&scanf("%s",b)!=EOF)
  {c1=strlen(a);
   c2=strlen(b);
   p1=c1;
   p2=c2;
    //先判断负号
    if(c1<c2)
    {strcpy(e,b);
     strcpy(f,a);
     strcpy(a,e);
     b[0]='\0';
     strcpy(b,f);
     u=c1;c1=c2;c2=u;
     y=-1;
    }
    else if(c1==c2)
            { y=strcmp(a,b);
              if(y>0) i=0;
              else if(y<0)
                 {strcpy(e,b);
                  strcpy(f,a);
                  strcpy(a,e);
                  b[0]='\0';
                  strcpy(b,f);
                  u=c1;c1=c2;c2=u;
                 }
              else i=0;
            }
     else y=1;
     //再从字符串长度角度分类计算
     if(y==0) printf("0\n");
     else if(c1==1)
     {if(p1>p2||(p1==p2&&y>0))
      {g=a[0]-b[0];
        printf("%d\n",g);
      }
      if(p1<p2||(p1==p2&&y<0))
       {g=a[0]-b[0];
        printf("-"); printf("%d\n",g);
       }
     }
     else {
    for(i=0;i<c1/2;i++)
               {t=a[i];a[i]=a[c1-i-1];a[c1-i-1]=t;}
    for(j=0;j<c2/2;j++)
               {h=b[j];b[j]=b[c2-j-1];b[c2-j-1]=h;}

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
    while(c[l]==0&&l>=0)
        {l--;}
    q=l;
    for(p=0,l;l>=0;l--,p++)
            {u=c[l];c[l]=d[p];d[p]=u;}

    if(y==0)  printf("0\n");
    else if(p1>p2||(p1==p2&&y>0))
            {
                for(p=0;p<=q;p++)
                printf("%d",d[p]);
                printf("\n");

            }
    else if(p1<p2||(p1==p2&&y<0))
            {
                    printf("-");
                    for(p=0;p<=q;p++)
                    printf("%d",d[p]);
                    printf("\n");
             }
     }
  a[0]='\0';b[0]='\0';c[0]='\0';d[0]='\0';e[0]='0';f[0]='\0';
 }
 return 0;
}
