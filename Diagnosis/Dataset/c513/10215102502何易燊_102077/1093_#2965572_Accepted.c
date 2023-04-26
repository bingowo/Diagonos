#include <stdio.h>
#include <string.h>

int ans[105];
int num[105];

int search(int pos,int len,int sum,int limit)
{
    if (pos>len) return 1;
    int scope = limit?num[pos]:0;
    if (pos==len&&limit) scope++;
    for (int i=scope;i<=9;i++)
    {
        if (pos<len&&i!=9) ans[pos] = i;
        else if (pos==len&&i!=9&&(sum+i)%9!=0) ans[pos] = i;
        else continue;
        if (search(pos+1,len,sum+i,limit&&i==num[pos])==1) return 1;
    }
    return 0;
}

int main()
{
    char s[102] = {}; scanf("%s",s);
    int len = strlen(s);
    for (int i=1;i<=len;i++) num[i] = s[i-1]-'0';
    if (search(1,len,0,1))
        for (int i=1;i<=len;i++) printf("%d",ans[i]);
    else
        for (int i=1;i<=len+1;i++) printf("%d",i==1);
    printf("\n");
    return 0;
}