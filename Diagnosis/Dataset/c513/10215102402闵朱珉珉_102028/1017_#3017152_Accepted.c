#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int q[128]={0};
    q['I']=1;q['V']=5;
    q['X']=10;q['L']=50;
    q['C']=100;q['D']=500;
    q['M']=1000;
    long long data[100];
    int n=0;
    long long flag=1;

for(int i=0;s[i];i++)
{
  switch(s[i])
  {
    case '(':
           flag=flag*1000;
           break;
    case ')':
            flag=flag/1000;
            break;
    default:
            data[n++]=q[s[i]]*flag;
            break;
   }
}
long long result=0;
 for(int i=0;i<n-1;i++)
 {
    if(data[i]<data[i+1])
         result-=data[i];
    else result+=data[i];
 }
 result+=data[n-1];
 printf("%lld\n",result);


}
