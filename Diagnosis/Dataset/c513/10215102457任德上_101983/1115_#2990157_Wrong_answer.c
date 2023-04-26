#include<stdio.h>
#include<string.h>
int main(){
    int t,len;
    char *min;
    char s[21];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%s",s);
        len=strlen(s);
        min=s+len-1;
        for(int k=len-1;k>0;k--){
            if(*(s+k)<*min)min=s+k;
            if(*(s+k-1)<*min){
                char c=*(s+k-1);
                *(s+k-1)=*min;
                *min=c;
                break;
            }
        }
        printf("case #%d:\n%s\n",i,s);
    }
}