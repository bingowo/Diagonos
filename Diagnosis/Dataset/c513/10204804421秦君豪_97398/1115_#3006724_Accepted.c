#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    int t;scanf("%d",&t);
    char s[21];
    for(int i=0;i<t;i++)
    {
        memset(s,'0',sizeof(s));
        scanf("%s",s+1);
        int j;
        for(j=strlen(s)-1;s[j]<=s[j-1];j--);
        int maxn='9'+1;char temp; char min= s[j-1];

        for(int t = j;t<strlen(s);t++)
        {
            if(maxn>s[t]&&s[t]>min)
            {
                temp = s[t];
                s[t]=s[j-1];
                s[j-1]=temp;
                maxn = s[j-1];
            }

        }
        qsort(s+j,strlen(s)-j,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s[0]=='0'?s+1:s);
    }
}
