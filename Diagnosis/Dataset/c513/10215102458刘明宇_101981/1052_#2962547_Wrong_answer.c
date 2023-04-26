#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T-->0){
        char s[21];
        scanf("%s",s);
        int num[30] = {0},res[100] = {0},len=0;
        char *p = s;
        while(*p){
            num[*p-'A']++;
            p++;
        }
        //for(int i = 0;i<26;i++){
        //    printf("%d ",num[i]);
        //}
        //printf("\n");
        //printf("%d\n",num['Z'-'A']);
        while(num['Z'-'A']>=1 &&num['E'-'A']>=1 && num['R'-'A']>=1 &&num['O'-'A']>=1){
            res[len] = 0;
            len++;
            num['O'-'A']--;
            num['R'-'A']--;
            num['E'-'A']--;
            num['Z'-'A']--;
        }
        while(num['O'-'A']>=1 && num['N'-'A']>=1 && num['E'-'A']>=1){
            res[len] = 1;
            len++;
            num['O'-'A']--;
            num['N'-'A']--;
            num['E'-'A']--;
        }
        while(num['W'-'A']>=1 && num['T'-'A']>=1 && num['O'-'A']>=1){
            res[len] = 2;
            len++;
            num['W'-'A']--;
            num['T'-'A']--;
            num['O'-'A']--;
        }
        while(num['T'-'A']>=1 && num['H'-'A']>=1 && num['R'-'A']>=1 && num['E'-'A']>=2){
            res[len]=3;
            len++;
            num['T'-'A']--;
            num['H'-'A']--;
            num['R'-'A']--;
            num['E'-'A']-=2;
        }
        while(num['F'-'A']>=1 && num['O'-'A']>=1 && num['U'-'A']>=1 && num['R'-'A']>=1){
            res[len]=4;
            len++;
            num['F'-'A']--;
            num['O'-'A']--;
            num['U'-'A']--;
            num['R'-'A']--;
        }
        while(num['F'-'A']>=1 && num['I'-'A']>=1 && num['V'-'A']>=1 && num['E'-'A']>=1){
            res[len]=5;
            len++;
            num['F'-'A']--;
            num['I'-'A']--;
            num['V'-'A']--;
            num['E'-'A']--;
        }
        while(num['S'-'A']>=1 && num['I'-'A']>=1 && num['X'-'A']>=1){
            res[len]=6;
            len++;
            num['X'-'A']--;
            num['I'-'A']--;
            num['S'-'A']--;
        }
        while(num['S'-'A']>=1 && num['N'-'A']>=1 && num['V'-'A']>=1 && num['E'-'A']>=2){
            res[len]=7;
            len++;
            num['S'-'A']--;
            num['N'-'A']--;
            num['V'-'A']--;
            num['E'-'A']-=2;
        }
        while(num['G'-'A']>=1 && num['I'-'A']>=1 && num['H'-'A']>=1 && num['E'-'A']>=1 && num['T'-'A']>=1){
            res[len]=8;
            len++;
            num['G'-'A']--;
            num['I'-'A']--;
            num['H'-'A']--;
            num['E'-'A']--;
            num['T'-'A']--;
        }
        while(num['I'-'A']>=1 && num['N'-'A']>=2 && num['E'-'A']>=1){
            res[len]=9;
            len++;
            num['I'-'A']--;
            num['N'-'A']-=2;
            num['E'-'A']--;
        }
        printf("case #%d:\n",cnt);
        for(int i = 0;i<len;i++){
            printf("%d",res[i]);
        }
        printf("\n");
        cnt++;
    }
}
