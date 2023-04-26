#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum (char c,char *s)
{
    int len=strlen(s),sum=0;
    for (int i=0;i<len;i++)
    {
        if (s[i]==c) sum++;
    }
    return sum;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int q=0;q<T;q++)
    {
        char s[21]={};
        int num[27]={},result[20]={},i=0;
        scanf("%s",s);
        for (char c='A';c<='Z';c++)
        {
            num[c-'A']=sum(c,s);
        }
        while (num['Z'-'A']&&num['E'-'A']&&num['R'-'A']&&num['O'-'A'])
        {
            result[i++]=0;
            num['Z'-'A']--;num['E'-'A']--;num['R'-'A']--;num['O'-'A']--;
        }
        while (num['O'-'A']&&num['N'-'A']&&num['E'-'A'])
        {
            result[i++]=1;
            num['O'-'A']--;num['N'-'A']--;num['E'-'A']--;
        }
        while (num['T'-'A']&&num['W'-'A']&&num['O'-'A'])
        {
            result[i++]=2;
            num['T'-'A']--;num['W'-'A']--;num['O'-'A']--;
        }
        while (num['T'-'A']&&num['H'-'A']&&num['R'-'A']&&(num['E'-'A']-1)&&(num['F'-'A'!=0]))
        {
            result[i++]=3;
            num['T'-'A']--;num['H'-'A']--;num['R'-'A']--;num['E'-'A']-=2;
        }
        while (num['F'-'A']&&num['O'-'A']&&num['U'-'A']&&num['R'-'A'])
        {
            result[i++]=4;
            num['F'-'A']--;num['O'-'A']--;num['U'-'A']--;num['R'-'A']--;
        }
        while (num['F'-'A']&&num['I'-'A']&&num['V'-'A']&&num['E'-'A'])
        {
            result[i++]=5;
            num['F'-'A']--;num['I'-'A']--;num['V'-'A']--;num['E'-'A']--;
        }
        while (num['S'-'A']&&num['I'-'A']&&num['X'-'A'])
        {
            result[i++]=6;
            num['S'-'A']--;num['I'-'A']--;num['X'-'A']--;
        }
        while (num['S'-'A']&&(num['E'-'A']-1)&&num['V'-'A']&&num['N'-'A'])
        {
            result[i++]=7;
            num['S'-'A']--;num['E'-'A']-=2;num['V'-'A']--;num['N'-'A']--;
        }
        while (num['E'-'A']&&num['I'-'A']&&num['G'-'A']&&num['H'-'A']&&num['T'-'A'])
        {
            result[i++]=8;
            num['E'-'A']--;num['I'-'A']--;num['G'-'A']--;num['H'-'A']--;num['T'-'A']--;
        }
        while ((num['N'-'A']-1)&&num['I'-'A']&&num['E'-'A'])
        {
            result[i++]=9;
            num['N'-'A']-=2;num['I'-'A']--;num['E'-'A']--;
        }
        printf("case #%d:\n",q);
        for (int j=0;j<i;j++)
        {
            printf("%d",result[j]);
        }
        printf("\n");
    }

    return 0;

}
