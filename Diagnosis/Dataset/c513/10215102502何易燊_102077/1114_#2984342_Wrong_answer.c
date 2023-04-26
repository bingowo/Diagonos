#include <stdio.h>
#include <string.h>
#include <ctype.h>

void divide(int n,int a1[],int a2[])
{
    for (int i=1,p=0;i<=abs(n);i++)
    {
        if (n%i==0) {a1[p] = i; a2[p++] = n/i;}
    }
}

int main()
{
    char* s = (char*)malloc(20); scanf("%s",s);
    int num[3] = {};
    char buf[10] = {};
    if (strstr(s,"x^2"))
    {
        char *t = strstr(s,"x^2");
        for (int i=0;i<t-s;i++) buf[i] = s[i];
        if (buf[0]=='\0') num[2] = 1;
        else if (buf[0]=='-'&&!buf[1]) num[2] = -1;
        else num[2] = atoi(buf);
        s = strstr(s,"x^2")+3;
        memset(buf,0,sizeof(buf));
    }
    if (strstr(s,"x"))
    {
        char *t = strstr(s,"x");
        for (int i=0;i<t-s;i++) buf[i] = s[i];
        if (buf[0]=='\0') num[1] = 1;
        else if (buf[0]=='-'&&!buf[1]) num[1] = -1;
        else num[1] = atoi(buf);
        s = strstr(s,"x")+1;
        memset(buf,0,sizeof(buf));
    }
    num[0] = atoi(s);
    
    if (num[0]==0)
    {
        printf("%d %d 1 0\n",num[2],num[1]);
        return 0;
    }
    int i,j;
    int m1,m2,n1,n2;
    int flag = 0;
    int a1[200]={},a2[200]={},c1[200]={},c2[200]={};
    divide(num[2],a1,a2); divide(num[0],c1,c2);
    for (i=0;a1[i];i++)
    {
        for (j=0;c1[j];j++)
        {
            if (a1[i]*c2[j]+a2[i]*c1[j]==num[1])
            {
                flag = 1;
                m1 = a1[i]; n1 = c1[j]; m2 = a2[i]; n2 = c2[j];
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) printf("No Answer!\n");
    else 
    {
        if (c1>c2) {n1^=n2; n2^=n1; n1^=n2;}
        printf("%d %d %d %d\n",m1,n1,m2,n2);
    }
    return 0;
}