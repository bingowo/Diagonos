#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int T;
	scanf("%d",&T);
	char c;
	gets(res);
	int i;
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		char s1[81],s2[81],s[81];
		gets(s1);
		gets(s2);
		gets(s);
		int ans,res;
		int l1=strlen(s1);
		int l2=strlem(s2);
		int l=strlen(s);
		int i;
		for(i=0;i<l;i++)
        {
            if(s1[0]==s[i])
            {
                int j;
                for(j=0;j<l1;j++)
                {
                    if(s1[j]!=s[i+j])
                        break;
                }
                if(j==l1)
                {
                    ans=i+l1-1;
                    break;
                }
            }
        }
        if(i==l)
        {
            printf("0\n");
            return 0;
        }
        int k;
		for(k=l1;i<l;i++)
        {
            if(s1[0]==s[i])
            {
                int j;
                for(j=0;j<l1;j++)
                {
                    if(s1[j]!=s[i+j])
                        break;
                }
                if(j==l1)
                {
                    ans=i+l1-1;
                    break;
                }
            }
        }
	}
	return 0;
}