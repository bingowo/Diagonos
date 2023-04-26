#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void itob(char s[],int N,int R)
{
    char arr[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ss[32]={0};
    int a=N,i=0,j=0;
    if(N<0) N=-N;
    do
    {
        ss[i++]=arr[N%R];
        N/=R;
    }
    while(N);
    if(a<0) s[i]='-';
    else i-=1;
    while(i>=0)
    {
        s[j++]=ss[i--];
    }
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int i=0;i<T;i++)
   {
       int N,R;
       char s[32];
       scanf("%d %d",&N,&R);
       itob(s,N,R);
       printf("%s\n",s);
   }
   return 0;

}
