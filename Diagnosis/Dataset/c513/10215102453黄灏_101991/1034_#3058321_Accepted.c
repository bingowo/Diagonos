#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float flag[58];

int cmp(const void *a,const void *b){
    char* a1=(char*)a;
    char* b1=(char*)b;
    if(flag[*a1-'A'] != flag[*b1-'A'])
        return (flag[*a1-'A']>flag[*b1-'A'])?-1:1;
    else {
        if((abs(*a1-*b1))==32) return (*a1>*b1)?-1:1;
        else return (*a1>*b1)?1:-1;
    }

}

int main(){
    int t;
    scanf("%d",&t);
    char s[101];
    for(int i=0;i<t;i++){
        for(int j=0;j<26;j++){
            scanf("%f",&flag[j]);
            flag[j+32]=flag[j];
        }
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",s);
    }
    return 0;
}
