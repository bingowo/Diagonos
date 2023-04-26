#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    return *(int*)a>*(int*)b?1:-1;
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[21];
        gets(s);
        char albet[128];
        memset(albet,0,128);
        int ret[21];int ri=0;
        for(int i=0;i<strlen(s);i++){
            albet[s[i]]++;
        }
        while(albet['Z']>0){
            ret[ri++]=0;
            albet['Z']--;
            albet['E']--;
            albet['R']--;
            albet['O']--;
        }
        while(albet['G']>0){
            ret[ri++]=8;
            albet['E']--;
            albet['I']--;
            albet['G']--;
            albet['H']--;
            albet['T']--;
        }
        while(albet['X']>0){
            ret[ri++]=6;
            albet['S']--;
            albet['I']--;
            albet['X']--;
        }
        while(albet['H']>0){
            ret[ri++]=3;
            albet['T']--;
            albet['H']--;
            albet['R']--;
            albet['E']--;
            albet['E']--;
        }
        while(albet['S']>0){
            ret[ri++]=7;
            albet['S']--;
            albet['E']--;
            albet['V']--;
            albet['E']--;
            albet['N']--;
        }
        while(albet['V']>0){
            ret[ri++]=5;
            albet['F']--;
            albet['I']--;
            albet['V']--;
            albet['E']--;
        }
        while(albet['F']>0){
            ret[ri++]=4;
            albet['F']--;
            albet['O']--;
            albet['U']--;
            albet['R']--;
        }
        while(albet['W']>0){
            ret[ri++]=2;
            albet['T']--;
            albet['W']--;
            albet['O']--;
        }
        while(albet['I']>0){
            ret[ri++]=9;
            albet['N']--;
            albet['I']--;
            albet['N']--;
            albet['E']--;
        }
        while(albet['O']>0){
            ret[ri++]=1;
            albet['O']--;
            albet['N']--;
            albet['E']--;
        }
        qsort(ret,ri,sizeof(int),cmp);
        printf("case #%d:\n",cas++);
        for(int i=0;i<ri;i++){
            printf("%d",ret[i]);
        }
        printf("\n");
    }
}