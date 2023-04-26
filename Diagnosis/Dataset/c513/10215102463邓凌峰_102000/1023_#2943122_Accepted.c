#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char str[31];
    int num;
    int haveNum;
}S;

int toNum(char *s){
    int ans=0,isNum=0;;
    for(int i=0;i<strlen(s);i++){
        if(isalpha(s[i]) && isNum) return ans;
        if(isdigit(s[i])){
            isNum=1;
            ans=ans*10+s[i]-'0';
        }
        if(i==strlen(s)-1 && isNum) return ans;
    }
    return -1;
}

int containNum(char *s){
    for(int i=0;i<strlen(s);i++){
        if(isdigit(s[i])) return 1;
    }
    return 0;
}

int cmp(const void *a,const void *b){
    S pa=*(S*)a,pb=*(S*)b;
    if(pa.haveNum*pb.haveNum==1){
        if(pa.num!=pb.num) return pa.num>pb.num?1:-1;
        else return strcmp(pa.str,pb.str);
    }
    if(pa.haveNum*pb.haveNum==0){
        if(pa.haveNum==0 && pb.haveNum==0)
            return strcmp(pa.str,pb.str);
        else if(pa.haveNum==0) return -1;
        else return 1;

    }
}





int main()
{
    S strs[100]={0};
    int cnt=0;
    while(scanf("%s",strs[cnt++].str)!=EOF);
    for(int i=0;i<cnt;i++){
        strs[i].num=toNum(strs[i].str);
        strs[i].haveNum=containNum(strs[i].str);

    }

    qsort(strs,cnt-1,sizeof(S),cmp);

    for(int i=0;i<cnt-1;i++){
        printf("%s ",strs[i].str);
    }

}







