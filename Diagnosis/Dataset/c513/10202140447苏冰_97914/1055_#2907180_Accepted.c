#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000010];
char t[1000010];
int a[150]={0};
int main()
{
    scanf("%s",s);
    long long max=0;
    char* p=s,*q=s;
    int flag=0;
    while(*p!='\0')
    {
        int x=*p;
        if(a[x]==0)
        {
            p++;a[x]=1;
        }
        else
        {
            flag=1;
            long long len=p-q;
            if(len>max)
            {
                max=len;
                strncpy(t,q,len);
            }
            q++;p=q;
            memset(a,0,sizeof(a));
        }
    }
    if(flag==0) printf("%s",s);
    else printf("%s",t);
    return 0;
}
