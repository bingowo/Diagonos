#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

main()
{
    int n; scanf("%d ",&n);
    for (int k=0;k<n;k++)
    {
        char s[21] = {}; int num[128] = {};
        gets(s);
        for (int i=0;s[i];i++) num[s[i]]++;
        char ans[10] = {}; int index = 0;
        while (num['Z']) {num['Z']--; num['E']--; num['R']--; num['O']--; ans[index++]='0';}
        while (num['W']) {num['W']--; num['T']--; num['O']--; ans[index++]='2';}
        while (num['X']) {num['X']--; num['S']--; num['I']--; ans[index++]='6';}
        while (num['G']) {num['G']--; num['E']--; num['I']--; num['H']--; num['T']--; ans[index++]='8';}
        while (num['H']) {num['T']--; num['H']--; num['R']--; num['E']-=2; ans[index++]='3';}
        while (num['R']) {num['R']--; num['F']--; num['U']--; num['O']--; ans[index++]='4';}
        while (num['V']) {num['V']--; num['F']--; num['I']--; num['E']--; ans[index++]='5';}
        while (num['S']) {num['S']--; num['V']--; num['N']--; num['E']-=2; ans[index++]='7';}
        while (num['O']) {num['O']--; num['N']--; num['E']--; ans[index++]='1';}
        while (num['F']) {num['F']--; num['I']--; num['V']--; num['E']--; ans[index++]='9';}
        
        qsort(ans,index,sizeof(ans[0]),cmp);
        for (int i=0;i<128;i++) if (!num[i]) {strcpy(ans,"-1"); break;}
        printf("case #%d:\n%s\n",k,ans);
    }
    return 0;
}