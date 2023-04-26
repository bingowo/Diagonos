#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    return *(int*)p1-*(int*)p2;
}
int main() {
    int T;
    int alb[27]={0};
    int ret[10]={0};
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[21]={0};
        scanf("%s",s);
        for(int j=0;j< strlen(s);j++){
            alb[s[j]-'A']++;
        }
        int p=0;
        for(int m=0;m< alb['Z'-'A'];m++,p++){
            ret[p]=0;
            alb['O'-'A']--;
        }
        for(int m=0;m< alb['W'-'A'];m++,p++){
            ret[p]=2;
            alb['O'-'A']--;
        }
        for(int m=0;m< alb['U'-'A'];m++,p++){
            ret[p]=4;
            alb['O'-'A']--;
            alb['F'-'A']--;
        }
        for(int m=0;m< alb['X'-'A'];m++,p++){
            ret[p]=6;
            alb['S'-'A']--;
        }
        for(int m=0;m< alb['G'-'A'];m++,p++){
            ret[p]=8;
            alb['H'-'A']--;
        }
        for(int m=0;m< alb['O'-'A'];m++,p++){
            ret[p]=1;
            alb['N'-'A']--;
        }
        for(int m=0;m< alb['H'-'A'];m++,p++){
            ret[p]=3;
        }
        for(int m=0;m< alb['F'-'A'];m++,p++){
            ret[p]=5;
        }
        for(int m=0;m< alb['S'-'A'];m++,p++){
            ret[p]=7;
            alb['N'-'A']--;
        }
        for(int m=0;m< alb['I'-'A'];m++,p++){
            ret[p]=9;
        }
        qsort(ret,p,sizeof(int),cmp);
        printf("case #%d:\n",i);
        for(int t=0;t<p;t++){
            printf("%d",ret[t]);
        }
        printf("\n");
    }
    return 0;
}