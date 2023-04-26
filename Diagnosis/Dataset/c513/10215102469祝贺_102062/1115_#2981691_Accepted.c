#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int cmp(const void*a,const void* b){
    char s1=*(char*)a,s2=*(char*)b;
    return s1-s2;
}
int main(){
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        printf("case #%d:\n",index);
        char s[30]={'0'};scanf("%s",s+1);
        int i=strlen(s)-1;
        for(;i>=0;i--){
            int minlarger=i;
            for(int j=i+1;j<strlen(s);j++){
                if(s[j]>s[i] && (s[j]<s[minlarger] || minlarger==i)) minlarger=j;
            }
            if(minlarger!=i){
                char c=s[minlarger];s[minlarger]=s[i];s[i]=c;
                break;
            }
        }
        qsort(s+i+1,strlen(s)-i-1,sizeof(char),cmp);
        int t=(s[0]=='0'?1:0);
        printf("%s\n",s+t);
    }
    return 0;
}
