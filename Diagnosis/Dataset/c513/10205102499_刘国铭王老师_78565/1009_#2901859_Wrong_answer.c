#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a,int b)
{
    return a?GCD(b%a,a):b;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char s[121];
    for(int i=0;i<n;i++)
    {
        char c;
        int k=0;
        while((c=getchar())!=EOF && c!='\n')
            s[k++]=c;
        s[k]='\0';
        int num=0;
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            unsigned char a=s[j];
            for(int m=0;m<8;m++)
            {
                num+=c%2;
                c>>=1;
            }
        }
        int g=GCD(num,len*8);
        printf("%d/%d\n",num/g,len*8/g);
    }
    return 0;
}
