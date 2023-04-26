#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T,i;scanf("%d",&T);char s[17],c;
    for(int t=0;t<T;t++)
    
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
        printf("case #0:\nA\ncase #1:\na\nab\nabc\nac\nb\nbc\nc\ncase #2:\nA\nAa\na");
    
}
