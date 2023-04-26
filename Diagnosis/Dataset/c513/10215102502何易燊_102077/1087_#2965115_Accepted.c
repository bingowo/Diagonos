#include <stdio.h>
#include <string.h>

int ans[105];
int num[105];

int search(int pos,int len,int last,int limit)
{
    if (pos>len) return 1;
    int i = limit?num[pos]:0;
    if (pos==len&&limit) i++;
    for (;i<=9;i++) 
    {
        if (i!=last) ans[pos] = i;
        else continue;
        if (search(pos+1,len,i,limit&&(i==num[pos]))==1) return 1;
    }
    return 0;
}

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        char s[102] = {}; scanf("%s",s);
        int len = strlen(s);
        for (int j=1;j<=strlen(s);j++) num[j] = s[j-1]-'0';
        printf("case #%d:\n",i);
        if (search(1,len,-1,1))
            for (int j=1;j<=len;j++) printf("%d",ans[j]);
        else
            for (int j=0;j<=len;j++) printf("%d",!(j&1));
        printf("\n");
    }
    return 0;
}