#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    int a1=*(char*)a,b1=*(char*)b;
    return a1-b1;
}
int main(){
    int t;
    char *min;
    char s[21];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int len;
        scanf("%s",s);
        len=strlen(s);
        min=s+len-1;
        for(int k=len-1;k>0;k--){
            if(*(s+k)<=*min)min=s+k;
            if(*(s+k-1)<*min){
                char c=*(s+k-1);
                *(s+k-1)=*min;
                *min=c;
                min=s+k-1;
                break;
            }
        }
        len=len-(min-s)-1;
        qsort(min+1,len,sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}