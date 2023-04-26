#include <stdio.h>
#include <stdlib.h>
#define N 100

int main()
{
    char s[N],a[N];
    int point=0,k=0,ans=0,flag=1,pans=0;
    scanf("%s",s);
    for(int i=0;s[i];i++)
    {
        point++;
        if(s[i]=='.')break;
    }
    for(int i=point;s[i];i++)
    {
        a[k]=s[i];
        s[i]=3;
        k++;
    }
    char *p,*q;
    p=s;
    q=&a[k-1];
    while(*p!=3)
    {
        switch(*p)
        {
            case'0':ans=ans*3;break;
            case'1':ans=ans*3+1;break;
            case'2':ans=ans*3-1;break;
        }
        p++;
    }
    printf("%d ",ans);
    while(*q)
    {
        switch(*q)
        {
            case'0':pans=pans;flag=flag*3;break;
            case'1':pans=pans+1;flag=flag*3;break;
            case'2':pans=pans-1;flag=flag*3;break;
        }
        q--;
    }
    if(pans<0)pans=-pans;
    while(pans%3==0)
    {
        pans=pans/3;
        flag=flag*3;
    }
    printf("%d %d",pans,flag);
    return 0;
}