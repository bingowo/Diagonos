#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{ char s1[1000],s2[1000];
int i,j,a[1000]={0},b[1000]={0},c[1000],k,t1,t2,f,len;
while(scanf("%s %s\n",s1,s2)!=EOF)
   { i=strlen(s1); j=strlen(s2);
       for(k=0;k<i;k++)
       a[k]=s1[i-1-k]-'0';
       for(k=0;k<j;k++)
       b[k]=s2[j-1-k]-'0';
       f=0;
       if(i>j) len=i;
       else len=j;
       if(i>j)
       {
      for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] - b[i];     
        if (a[i] < 0)          
        {
            a[i+1]-=1;         
            a[i]+=10;          
        }
    }
     while(a[len-1]==0) len--;
     while(len>0) {printf("%d",a[len-1]);len--;}
     printf("\n");
       }
    else
    { for (int i = 0 ; i < len ; i++)
    {
        b[i] = b[i] - a[i];     
        if (b[i] < 0)          
        {
            b[i+1]-=1;         
            b[i]+=10;          
        }
    }
    while(b[len-1]==0) len--;
     while(len>0) {printf("%d",b[len-1]);len--;}
     printf("\n");
        
    }
     
     memset(b,0,sizeof)
   }
}