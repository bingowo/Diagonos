#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
    {
        char s[200];
        getchar();
        gets(s);
        int len=strlen(s);
        char temp;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len-i;j++)
            {
                if(s[j]>s[j+1] && s[j]>='A' && s[j]<='Z' && s[j+1]>='A' && s[j+1]<='Z')
                {
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
        printf("case #%d:\n",t);
        printf("%s\n",s);
    }
	return 0;
}
