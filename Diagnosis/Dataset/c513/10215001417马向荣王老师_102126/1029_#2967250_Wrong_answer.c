#include<stdio.h>
#include<string.h>
int main()
{
    char s[201];
    int t,count=0;
    scanf("%d\n",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(s[i]<='Z' && s[i]>='A' && s[i]>s[j] && s[j]<='Z' && s[j]>='A')
                {
                    char temp=s[i];
                    s[i]=s[j];
                    s[j]=s[temp];
                }
            }
        }
        printf("case #%d\n",count++);
        printf("%s\n",s);
    }
    return 0;
}