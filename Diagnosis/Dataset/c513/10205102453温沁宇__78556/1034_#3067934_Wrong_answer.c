#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int p[25];
int cmp(const void *a,const void *b){
    char ch1,ch2;
    int p1,p2;//在字母表中的序号
    ch1=*((char*)a);
    ch2=*((char*)b);
    if(ch1>='a'&&ch1<='z') {p1=ch1-'a';}
    else {p1=ch1-'A';}
    if(ch2>='a'&&ch1<='z') {p2=ch2-'a';}
    else {p2=ch2-'A';}
    if(p[p2]>p[p1]) return 1;
    else if(fabs(p[p2]-p[p1])<1e-8){//浮点数绝对值 字母使用频率相同的情况
        if(p1==p2) return ch2-ch1;
        else return p1-p2;
    }
    else return -1;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        double p[26];
        for(int i=0;i<26;i++) scanf("%lf",&p[i]);
        char str[100];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",t);
        printf("%s\n",str);
    }
    return 0;
}
