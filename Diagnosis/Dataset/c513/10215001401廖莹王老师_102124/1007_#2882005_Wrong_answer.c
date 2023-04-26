#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void reverse(char s[])
{  int c,i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
    c=s[i],s[i]=s[j],s[j]=c;}
void feichongfu(int d)
{    int i,j,l,k;
    char s[10000];
   for(i=0;d>0;i++)
    {   if(i==0 && d==1){s[0]='1';i++;break;}
        s[i]=d%2+48;d=d/2;}
     reverse(s);
     s[i]=0;
    j=strlen(s);


     l=1; k=0;
    for(i=0;i<j-1;i++)
        { if(s[i]!=s[i+1])l=l+1;
          else {if(l>k)k=l;l=1;}
        }
        if(l>k)k=l;
    printf("%d\n",k);
    }
       int main()
       {
           int d,n,i;
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("case #%d:\n",i);
                scanf("%d",&d);
                feichongfu(d);
            }


           return 0;
        }