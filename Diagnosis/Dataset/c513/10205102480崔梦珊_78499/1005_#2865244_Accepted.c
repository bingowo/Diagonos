#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s1[60],s2[155];
    int T,i,len,j,m;
    int k,q;
    scanf("%d\n",&T);
    for(i=0;i<T;i++)
    {
        gets(s1);
        len=strlen(s1);
        memset(s2,0,sizeof s2);
        k=0;
        for(j=len-1;j>=2;j--)
        {
            int a=s1[j]-'0';
            for (m=0;m<k||a;m++)
            {
                q=a*10+(m<k? s2[m]-'0':0);
                s2[m]=q/8+'0';
                a=q%8;
            }
            k=m;
        }
        printf("case #%d:\n0.%s\n",i,s2);
    }
    return 0;
}
