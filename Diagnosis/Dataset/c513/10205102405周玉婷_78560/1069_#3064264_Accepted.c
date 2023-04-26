#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toarr(int n, char s[])
{
    int index=10;
    while(n != 0)
    {
       s[index--] = n%10 + '0';
       n/=10;
    }
    memmove(s,s+index+1,10-index);
    s[10-index]='\0';
    return;
}

int reverse(int n)
{
    char p[11]; char s[12];
    toarr(n,p);
    int len = strlen(p), index = len - 1;
    for(int i=0; i<len; i++)
    {
    s[index--] = p[i];
    }
    s[len]='\0';
    return atoi(s);
}

int issymmetric(int num)
{
    char p[11];
    toarr(num, p);
    int len=strlen(p);
    char* p1=p;
    char* p2=p+len-1;
    int flag = 1;
    while(p1 <= p2)
    {
    if(*p1 != *p2) {flag=0;break;}
    else {p1++;p2--;} 
    }
    return flag;
}

int main()
{
    int n, m, sum;
    int index=0;
    scanf("%d", &n);
    while(1)
    {
    m = reverse(n);
    sum = n+m;
    index++;
    if(issymmetric(sum))  {printf("%d %d\n",index,sum);break;}
    else n=sum;
    }
    return 0;
}