#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T,i;scanf("%d",&T);char s[17],c;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%s",s);int a[52]={0};
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&&s[i]<='Z')a[s[i]-65]++;
            else a[s[i]-71]++;
        }
        int k=0;
        for(i=0;i<26;i++)if(a[i]>0)s[k++]='A'+i;
        for(i=26;i<52;i++)if(a[i]>0)s[k++]='a'+i-26;
        s[k]='\0';
        if(k==1)printf("%c\n",s[0]);
        else for(i=0;i<k;i++)
        {
            printf("%c\n",s[i]);
            for(int e=0;e<k-1;e++)
            {
              
            for(int j=i+2;j<=k-e;j++)
            {
                c=s[j];s[j]='\0';
                printf("%c",s[i]);
                printf("%s\n",s+i+e+1);
                s[j]=c;
            }}
        }
    }
}
