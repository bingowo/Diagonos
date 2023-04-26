#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int hp(char s[61])
{
    int digit=0,i,n=1,k=0;
    long long sum=0;
    int a[128];
    for(i=0;i<128;i++)a[i]=-1;

    char *p=s;
    a[*p]=1;
    while(*++p)
    if(a[*p]==-1){a[*p]=digit;digit=digit?digit+1:2;n++;}
    if(n<2)n=2;
    p=s;
    while(*p)
    {
        sum=sum*n+a[*p];
        p++;
    }
   return sum;
}
int main()
{
    int a,i;
    scanf("%d",&a);
   for(i=0;i<a;i++)
   {
       char s[61];
    scanf("%s",s);
    printf("case #%d:\n",i);
    printf("%lld\n",hp(s));
   }
    return 0;

}
