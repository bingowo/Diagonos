#include<stdio.h>
#include<string.h>

int re(int n)
{
    char *s;
    int a,i=0,j;
    a=n;
    while(a)
    {
        a/=10;
        i++;
    }
    s=(char*)malloc(i*sizeof(char));
    j=i-1;
    while(n&&j>=0)
    {
        s[j]=n%10+'0';
        n/=10;
        j--;
    }
    for(j=0;j<=(i-1)/2;j++)
    {
        if(s[j]!=s[i-1-j])break;
    }
    if(j!=(i-1)/2+1) return 1 ;
    else return 0;
}

int main()
{
   int n,i,j,a,l,n1;
   char *s;
   l=0;
   scanf("%d",&n);
   while(re(n))
   {
       a=n;
       i=0;
       while(a)
       {
           a/=10;
           i++;
       }
       s=(char*)malloc(i*sizeof(char));
       j=i-1;
       a=n;
       while(a&&j>=0)
       {
           s[j]=a%10+'0';
           a/=10;
           j--;
       }
       n1=0;
       for(j=i-1;j>=0;j--)
           n1=n1*10+s[j]-'0';
       n+=n1;
       l++;
   }
   printf("%d %d\n",l,n);
   return 0;
}
