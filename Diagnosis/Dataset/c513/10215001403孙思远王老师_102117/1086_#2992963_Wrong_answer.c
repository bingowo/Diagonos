#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 void jian(int a1[500],int b1[500],int a2[500],int b2[500],int w,int n,int n1,int n2)
 {
     int a,i,j;
     int a3[1000]={0},b3[1000]={0};
     for(j=0;j<n1/2;j++)
        {
            a=a1[j];
            a1[j]=a1[n1-1-j];
            a1[n1-1-j]=a;
        }
     for(j=0;j<n2/2;j++)
        {
            a=b1[j];
            b1[j]=b1[n2-1-j];
            b1[n2-1-j]=a;
        }
     for(i=w;i>0;i--)
     {
        b3[i]+=a2[i]-b2[i];
        if(b3[i]<0)
        {
            b3[i-1]--;
            b3[i]+=10;
        }
     }
     b3[0]+=a2[0]-b2[0];
     if(b3[n]>=5)
        b3[n-1]++;
     for(i=n-1;i>0;i--)
     {
         if(b3[i]<0)
         {
             b3[i-1]--;
             b3[i]+=10;
         }
         if(b3[i]>9)
         {
             b3[i-1]+=b3[i]/10;
             b3[i]%=10;
         }
     }
     if(b3[0]<0)
         {
             a1[0]--;
             b3[i]+=10;
         }
     for(i=0;i<1000;i++)
     {
         a3[i]+=a1[i]-b1[i];
         if(a3[i]<0)
         {
             a3[i+1]--;
             a3[i]+=10;
         }
     }
     for(i=999;i>=0;i--)
         {
             if(a3[i]!=0)
                 break;
         }
     if(i==-1)
         printf("0");
     for(;i>=0;i--)
         printf("%d",a3[i]);
     printf(".");
     for(i=0;i<n;i++)
         printf("%d",b3[i]);
 }
int main()
{
    int a1[500]={0},a2[500]={0},b1[500]={0},b2[500]={0},n;
    char s1[502],s2[502];
    scanf("%s%s%d",s1,s2,&n);
    int i,j1,j2,n1,n2;
    for(i=0;isdigit(s1[i]);i++)
        a1[i]=s1[i]-'0';
    n1=i;
    for(j1=0;s1[i+j1+1]&&isdigit(s1[i+j1+1]);j1++)
        a2[j1]=s1[i+j1+1]-'0';
    for(i=0;isdigit(s2[i]);i++)
        b1[i]=s2[i]-'0';
    n2=i;
    for(j2=0;s2[i+j2+1]&&isdigit(s2[i+j2+1]);j2++)
        b2[j2]=s2[i+j2+1]-'0';
    int w=j1;
    if(j1<j2)
        w=j2;
    char aa1[502]={'0'},aa2[502]={'0'},bb1[502]={'0'},bb2[502]={'0'};
    for(i=0;i<500;i++)
    {
        aa1[i]=a1[i]+'0';
        aa2[i]=a2[i]+'0';
        bb1[i]=b1[i]+'0';
        bb2[i]=b2[i]+'0';
    }
    aa1[501]='\0';
    aa2[501]='\0';
    bb1[501]='\0';
    bb2[501]='\0';
    if(strcmp(aa1,bb1)>0)
        jian(a1,b1,a2,b2,w,n,n1,n2);
    else if(strcmp(aa1,bb1)<0)
    {
        printf("-");
        jian(b1,a1,b2,a2,w,n,n1,n2);
    }
    else if(strcmp(aa2,bb2)>0)
        jian(a1,b1,a2,b2,w,n,n1,n2);
    else if(strcmp(aa2,bb2)<0)
    {
        printf("-");
        jian(b1,a1,b2,a2,w,n,n1,n2);
    }
    else
    {
        printf("0.");
        for(i=0;i<n;i++)
            printf("0");
    }
    return 0;
}
