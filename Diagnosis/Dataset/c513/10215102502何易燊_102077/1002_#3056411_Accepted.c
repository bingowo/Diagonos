#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int table[128];
        memset(table,-1,sizeof(table));
        char s[61] = {};
        scanf("%s",s);
        int base = 0;
        for (int j=0;s[j];j++)
        {
            if (table[s[j]]==-1) table[s[j]] = base++;
        }
        if (base<2) base = 2;
        long long num = 0;
        for (int j=0;s[j];j++)
        {
            if (table[s[j]]==0) num = num*base+1;
            else if (table[s[j]]==1) num = num*base;
            else num = num*base+table[s[j]];
        }
        printf("case #%d:\n%lld\n",i,num);
    }
    return 0;
}