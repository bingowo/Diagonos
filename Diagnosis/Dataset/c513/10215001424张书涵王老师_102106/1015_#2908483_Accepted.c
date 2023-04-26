#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int sushu(int n)
 {
     int l=1,i;
     if(n==2)
        return 2;
     else
     {
         if(n==3)
            return 3;
         else
         {
             for(;l!=0;n++)
             {
                 l=0;
                 for(i=2;i<=n/2;i++)
                 {
                     if(n%i==0)
                        l=l+1;
                 }
             }
             return (n-1);
         }
     }
 }

void reverse(int* s,int l)
{
    int i,j,k;
    for(i=0,j=l-1;i<j;i++,j--)
    {
        k=s[i];
        s[i]=s[j];
        s[j]=k;
    }
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        char s[1000]={'\0'};
        gets(s);
        int j,k1=0,k2=0,k;
        int c1[100]={0};int c2[100]={0};
        for(j=0;s[j]!=' ';j++)//
        {
            if(s[j]==',');
            else
            {
                c1[k1]=s[j]-'0';
                for(;s[j+1]!=','&&s[j+1]!=' ';)
                {
                    c1[k1]=10*c1[k1]+s[++j]-'0';
                }
                k1++;//c1长度是k1
            }
        }
        reverse(c1,k1);
        for(j=j+1;s[j];j++)
        {
            if(s[j]==',');
            else
            {
                c2[k2]=s[j]-'0';
                for(;s[j+1]!=','&&s[j+1];)
                {
                    c2[k2]=10*c2[k2]+s[++j]-'0';
                }
                k2++;//c2长度是k2
            }
        }
        reverse(c2,k2);
        k=(k1>k2)?k1:k2;
        int n=2;
        int s1[1000]={0};
        for(j=0;j<(k-1);j++,n++)
        {
            n=sushu(n);
            s1[j]=c1[j]+c2[j];
            if(s1[j]>=n)
            {
                s1[j]=s1[j]-n;
                c1[j+1]=c1[j+1]+1;
            }
        }
        n=sushu(n);
        s1[k-1]=c1[k-1]+c2[k-1];
        if(s1[k-1]>=n)
        {
            s1[k-1]=s1[k-1]-n;
            s1[k++]=1;
        }
        printf("case #%d:\n",i);
        for(j=k-1;j>0;j--)
            printf("%d,",s1[j]);
        printf("%d",s1[0]);
        printf("\n");
    }
}
