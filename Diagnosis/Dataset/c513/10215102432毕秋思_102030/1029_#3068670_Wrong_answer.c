#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int T;
	scanf("%d\n",&T);
	for(int t=0;t<T;t++)
    {
        char s[200];
        gets(s);
        int len=strlen(s);
        char temp;
        for(int i=0;i<len-1;i++)
        {
            for(int j=0,k=1;j<len-i;j++,k++)
            {
                while(s[j]<'A' || s[j]>'Z')
                {
                    j++;
                    k=j+1;
                }
                while(s[k]<'A' || s[k]>'Z')
                {
                    k++;
                }
                if(s[j]>s[k])
                {
                    temp=s[j];
                    s[j]=s[k];
                    s[k]=temp;
                }
            }
        }
        printf("case #%d:\n",t);
        printf("%s\n",s);
    }
	return 0;
}
