#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char n[109];
int pos=-1;

void push(char c)
{
    n[pos]=c;
}

int main()
{
    int t;
    scanf("%d",&t);
    int maxn;
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char s[109];
        scanf("%s",s);
        for(int k=0;s[k]!=0;k++){
        for(int l=0;l<3;l++){
        for(int j=0;s[j]!=0;j++){
            if(j==k){
                char c;
                if(l==0)c='A';
                else if(l==2)c='B';
                else c='C';
                if(pos!=-1&&n[pos]==c){
                    pos--;
                }
                else{
                    pos++;
                    push(c);
                }
            }
            if(pos!=-1&&n[pos]==s[j]){
                pos--;
            }
            else{
                pos++;
                push(s[j]);
            }
        }
        n[pos+1]=0;}
        int ans=strlen(s)+1-strlen(n);
         maxn=maxn>ans?maxn:ans;
    }
    printf("%d\n",maxn);
    }
    return 0;
}
