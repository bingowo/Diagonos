#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
int n,r;
scanf("%d%d",&n,&r);
int a[100]={0};
int cnt=0;
char s[]="0123456789ABCDEFGHIJK";
while(n!=0)
{
    if(n>0)
       {
          a[cnt++]=n%r;
          n=n/r;
       }
    else {a[cnt++]=n%r-r;if((n%r)!=0)n=n/r+1;
    else n=n/r;}
}
for(int i=cnt-1;i>=0;i--)
    printf("%c",s[a[i]]);


}
