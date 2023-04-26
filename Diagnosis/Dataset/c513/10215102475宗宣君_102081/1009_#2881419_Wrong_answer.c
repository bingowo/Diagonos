#include <stdio.h>
#include <string.h>
int GCD(int a,int b)
{
    int m,n;
    m = (a>b)?a:b;
    n = (a>b)?b:a;
    if(n == 0) return m;
    else return GCD(n,m%n);
}
int main()
{
    int n,a,m ,len,i,j,k,p;
    char s[120];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
     {
         getchar();
         gets(s);
         len = strlen(s);
         printf("%d\n",len);
         m = 0;
         for(j = 0;j<len;j++)
         {
             a = s[j];
             for(k = 0;k<8;k++)
             if(a&1<<k) m++;
         }
         p = GCD(m,8*len);
         printf("%d/%d",m/p,8*len/p);
     }
    return 0;
}
