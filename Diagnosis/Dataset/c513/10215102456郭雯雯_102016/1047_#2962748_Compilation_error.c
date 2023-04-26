#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int t,a=0;
    scanf("%d",&t);
    while(a<t){
        char s[510],ans[510];
        printf("case #%d:\n",a);
        gets(s);gets(s);
        int l=strlen(s),n=0;
        for(int i=0;i<l-1;i++){
            if(s[i]==s[i+1])n++;
            else{
                char an[4];
                itoa(n+1,an,10);
                printf("%s%c",an,s[i]);
                n=0;
            }
        }
        printf("\n");
        a++;
    }
}