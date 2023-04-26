#include<stdio.h>
#include<string.h>
typedef struct{
    char c;
    int line;
}ch;
int main(){
    char s[81];
    while(scanf("%s",s)!=EOF){
        ch n[80];
        int len=strlen(s),min,max;
        n[0].c=*s;
        n[0].line=80;
        for(int i=1;i<len;i++){
            n[i].c=*(s+i);
            if(*(s+i)>*(s+i-1))n[i].line=n[i-1].line-1;
            else if(*(s+i)<*(s+i-1))n[i].line=n[i-1].line+1;
            else n[i].line=n[i-1].line;
        }
        min=n[0].line;
        max=n[0].line;
        for(int i=1;i<len;i++){min=min>n[i].line?n[i].line:min;max=max>n[i].line?max:n[i].line;}
        for(int i=0;i<len;i++)n[i].line-=min;
        max-=min;
        for(int i=0;i<=max;i++){
            int width;
            for(int k=len-1;k>=0;k--){
                if(n[k].line==i){width=k;break;}
            }
            for(int k=0;k<=width;k++){
                if(n[k].line==i)printf("%c",n[k].c);
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}