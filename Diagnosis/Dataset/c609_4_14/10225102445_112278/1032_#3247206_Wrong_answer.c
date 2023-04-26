#include<stdio.h>
#include<string.h>
int main()
{char c[50];
int i,t=1,m=1,p;
scanf("%s",c);
for(i=0;i<49;i++)
{
    if(c[i]=='\0'){p=i;break;}
}
for(i=0;i<p;i++)
    {if(c[i]!=c[i+1]){t++;}
    else if(c[i]==c[i+1]&&m<t){m=t;t=1;}
    else if(c[i]==c[i+1]&&m>t){t=1;}
    }
   printf("%d",m);
}
