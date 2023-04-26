#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
 int T;
 scanf("%d",&T);
 char b[55];
 char s[155];
 for(int i=0;i<T;i++)
 {

     scanf("%s",b);
     int l=strlen(b);
//printf("%s\n",b);
int cnt=0;int k;
int tmp;
for(int j=l-1;j>1;j--)
{
    int d=b[j]-'0';
    k=0;
    do
    {
      if(k<cnt) tmp=d*10+s[k]-'0';
      else tmp=d*10;
      s[k++]=tmp/8+'0';
    //  printf(":%d:\n",tmp);
      d=tmp%8;
    }while(d||k<cnt);
    cnt=k;
}
s[cnt]='\0';
     printf("case #%d:\n0.%s\n",i,s);
 }
}
