#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T,i;scanf("%d",&T);char s[17],c;int a[52]={0};
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='A')a[s[i]-65]++;
            else a[s[i]-71]++;
        }
        int k=0;
        for(i=0;i<26;i++)if(a[i]>0)s[k++]='A'+i;
        for(i=26;i<52;i++)if(a[i]>0)s[k++]='a'+1;
        s[k]='\0';
        for(i=0;i<k;i++)
        {
            for(int j=i+1;j<k;j++)
            {
                c=s[j];s[j]='\0';
                printf("%s\n",s+i);
                s[j]=c;
            }
        }
    }
}