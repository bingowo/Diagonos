#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int T;
char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
scanf("%d",&T);
for(int i=0;i<T;i++)
{
    int n,r;
    int a[32]={0};
    int cnt=0;
    scanf("%d%d",&n,&r);
    if(n<0){printf("-");n=-n;}
   while(n!=0)
   {
       a[cnt++]=n%r;
       n=n/r;
   }

    for(int j=cnt-1;j>=0;j--)
        printf("%c",s[a[j]]);
    printf("\n");


}



}
