#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoarever(int n)
{
    char* a=(char*)malloc(sizeof(char)*20);
    int i=0;
    while(n!=0)
    {
        a[i++]=(n%10)+'0';
        n/=10;
    }
    //int re=atoi(a);
    return a;
}

int jud(int n)
{
    char *s=(char*)malloc(sizeof(char)*20);
    s=itoarever(n);
    int len=strlen(s),i;
    int len2=len/2;
    for(i=0;i<len2;i++)
    {
        if(s[i]!=s[len-i-1]) return -1;
    }
    return 1;
}

/*int rever(int n)
{
    char s[20],mid;
    s=itoa(n);
    int len=strlen(s),i;
    int len2=len/2,re;
    for(i=0;i<len2;i++)
    {
        mid=s[i];
        int zh=len-1-i;
        s[i]=s[zh];
        s[zh]=mid;
    }
    re=atoi(s);
    return re;

}*/

int main()
{
    int n,i,co=0;
    scanf("%d",&n);
    while(jud(n)==-1)
    {
        //printf("jud=%d",jud(n));
        int s=atoi(itoarever(n));
        n=n+s;
        co++;
        //printf("test: co=%d n=%d\n",co,n);
    }
    printf("%d %d\n",co,n);
    return 0;

}
