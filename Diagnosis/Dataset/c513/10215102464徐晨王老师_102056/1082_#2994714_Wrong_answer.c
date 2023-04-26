#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int findpos(char s[500]){
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.')return i;
    }
}

int main(){
    char s1[500];
    char s2[500];
    int N;
    scanf("%s%s%d",s1,s2,&N);
    int p1[1000]={0};
    int pos1=findpos(s1);
    int x1=500;
    for(int i=pos1-1;i>=0;i--){
        p1[x1]=s1[i]-48;
        x1--;
    }
    int y1=501;
    for(int i=pos1+1;i<strlen(s1);i++){
        p1[y1]=s1[i]-48;
        y1++;
    }

    int p2[1000]={0};
    int pos2=findpos(s2);
    int x2=500;
    for(int i=pos2-1;i>=0;i--){
        p2[x2]=s2[i]-48;
        x2--;
    }
    int y2=501;
    for(int i=pos2+1;i<strlen(s2);i++){
        p2[y2]=s2[i]-48;
        y2++;
    }

    int p[1000]={0};
    for(int i=0;i<1000;i++){
        p[i]=p1[i]+p2[i];
    }
    if(p[N+501]%10>=5)p[N+500]++;
    int x,y;
    if(x1<x2)x=x1;
    else x=x2;
    if(y1>y2)y=y1;
    else y=y2;
    for(int i=N+500;i>x+1;i--){
        p[i-1]=p[i-1]+p[i]/10;
        p[i]=p[i]%10;
    }
    if(x==499&&p[x+1]==0)printf("0");
    if(p[x+1]!=0)printf("%d",p[x+1]);
    for(int i=x+2;i<=500;i++){
        printf("%d",p[i]);
    }
    printf(".");
    for(int i=501;i<=(N+500);i++){
        printf("%d",p[i]);
    }
    //printf(" %d %d",pos1,pos2);
    return 0;
}
