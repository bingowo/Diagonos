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
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int len,flag=0;
        char s[22]={0};
        s[0]='0';
        scanf("%s",s+1);
        len=strlen(s);
        for(int k=len-1;k>0;k--){
            qsort(s+k,len-k,sizeof(char),cmp);
            for(int i=k;i<len;i++){
                if(*(s+k-1)<*(s+i)){
                    char c;
                    c=*(s+i);
                    *(s+i)=*(s+k-1);
                    *(s+k-1)=c;
                    flag=1;
                    break;
                }
            }
            if(flag==1)break;
        }
        if(s[0]=='0')printf("case #%d:\n%s\n",i,s+1);
        else printf("case #%d:\n%s\n",i,s);
    }
    return 0;
}