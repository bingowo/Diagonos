#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char s[21];
    int number;
};

int cmp(const void* a,const void* b){
    struct data a1=*(struct data*)a;
    struct data b1=*(struct data*)b;
    if(a1.number==b1.number){
        return strcmp(b1.s,a1.s);
    }
    else return a1.number<b1.number;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        struct data p[n];
        for(int j=0;j<n;j++){
            scanf("%s",p[j].s);
            p[j].number=0;
            int len=strlen(p[j].s);
            int q[26];
            for(int k=0;k<len;k++){

                    q[p[j].s[k]-65]=1;
                }
            for(int k=0;k<26;k++){
                if(q[k]==1)p[j].number++;
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++){
            printf("%s\n",p[j].s);
    }
    }
    return 0;
}
