#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int sanjinzhi(char s[100])
{
 int j,i,k,n,l;

  j=strlen(s);
  k=0;
    for(i=0;i<j;i++)
    {
    if(s[i]=='1')n=1;
    if(s[i]=='0')n=0;
    if(s[i]=='-')n=-1;
        l=pow(3,j-i-1);
        k=k+n*l;
    }


    return k;

}
int main()
{
    int t,i,k;
    char s[100];
scanf("%d\n",&t);
for(i=0;i<t;i++)
{
      scanf("%s",s);
      printf("case #""%d\n",i);
       printf("%d",sanjinzhi(s));
}
    return 0;
}
