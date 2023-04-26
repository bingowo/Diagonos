#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int alpha[91]={0};
    int T;
    char s[201],c;
    int len=0;
    scanf("%d",&T);getchar();
    for(int i=0;i<T;i++)
    {
        gets(s);
        len=strlen(s);
        for(int j=0;j<len;j++)
        {
            if(s[j]>='A'&&s[j]<='Z')
            {
                alpha[s[j]]++;
            }
        }
        for(int j=0;j<len;j++)
        {
            if(s[j]>='A'&&s[j]<='Z')
            {
                for(int k=65;k<91;k++)
                {
                    if(alpha[k]>0)
                    {
                        s[j]=(char)k;
                        alpha[k]--;
                    }
                }
            }
        }
        printf("case #%d:\n%s\n",i,s);
    }
    system("pause");
    return 0;
}