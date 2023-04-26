#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*pa, const void*pb)
{
    char a=*(char*)pa,b=*(char*)pb;
    return a-b;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        char s[22]={'0'};
        scanf("%s",s+1);
        int pos=strlen(s)-2;
        for(;s[pos]>=s[pos+1];pos--);

        char t[22]={0};
        for(int i=0;i+pos+1<strlen(s);i++)//剩下的数按从小到大排列
            t[i]=s[i+pos+1];
        qsort(t,strlen(t),sizeof(t[0]),cmp);

        for(int i=0;i<strlen(t);i++)
            if(t[i]>s[pos])
            {
                char c=s[pos];
                s[pos]=t[i];
                t[i]=c;
                break;
            }
        for(int i=0;i<strlen(t);i++)
            s[pos+i+1]=t[i];
        printf("case #%d:\n",cas);
        printf("%s\n",s[0]=='0'?s+1:s);
    }
    return 0;
}