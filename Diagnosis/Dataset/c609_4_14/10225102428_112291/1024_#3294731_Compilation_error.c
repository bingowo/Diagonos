#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char getname(char line[100]){
    char s[64];
    char c;
    while((c=getchar())!=EOF){
        
    }
}
char gettime(char line[100]){
    char s[20];
    char c;
    int i=0;
    while((c=getchar())!=' '){
        s[i++]=c
    }
    return s,i;
}
char getsize(char line[100]){
    char s[20];
    char c;
    int i=0;
    while((c=getchar())!=' '){
        s[i++]=c
    }
}
int cmpname(const void* a,const void* b){
    char* aa=(char*)a;
    char* bb=(char*)b;
    char s1[64];
    char s2[64];
    strcpy(s1,aa);
    strcpy(s2,bb);
    return s1<s2;
}
int main(){
    int n;//球队数量，比赛场数
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char line[100];
        scanf("%",&c,&d,&e);
        match[i].hao=i+1;
        //printf("%d",match[i].hao);
        if(e==0)match[c-1].score++,match[d-1].score++,match[c-1].ping++,match[d-1].ping++;//printf("%d",match[c-1].score);
        else if(e==1)match[c-1].score=match[c-1].score+3,match[d-1].score--,match[d-1].fail++,match[c-1].tru++;
        else if(e==-1)match[d-1].score=match[d-1].score+3,match[c-1].score--,match[c-1].fail++,match[d-1].tru++;;
    }
    qsort(match,n,sizeof(match[0]),cmp);
    for(int i=0;i<n;i++)printf("%d ",match[i].hao);
    return 0;
}
