#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char* s)
{
    int len=strlen(s);
    int sta[100],n=0;
    sta[n]=0;
    for(int i=0;i<len;i++){
        int state=sta[n];
        char dq=s[i];
        if(state==0){
            if(dq=='{') sta[++n]=3;
            else if(dq=='[') sta[++n]=2;
            else if(dq=='(') sta[++n]=1;
            else return 0;
        }
        else if(state==1){
            if(dq=='{') sta[++n]=3;
            else if(dq==')') n--;
            else return 0;
        }
        else if(state==2){
            if(dq=='(') sta[++n]=1;
            else if(dq==']') n--;
            else return 0;
        }
        else if(state==3){
            if(dq=='[') sta[++n]=2;
            else if(dq=='}') n--;
            else return 0;
        }
    }
    if(sta[n]==0) return 1;
    else return 0;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[101]={0};
        scanf("%s",s);
        int y=judge(s);
        if(y) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
