#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int findpos(char s[1000]){
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.'&&s[i+1]=='.'){
            for(int j=i+1;j<strlen(s)-1;j++){
                s[j]=s[j+1];
            }
            s[strlen(s)-1]='0';
        }
    }
    int pos=-1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.')pos=i;
    }
    if(pos==0){
        for(int i=strlen(s);i>=0;i--){
            s[i]=s[i-1];
        }
        s[0]='0';
    }
    if(pos==-1){
        s[strlen(s)]='.';
    }
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='.')return i;
    }
}

int main(){
    char s1[1000]={'\0'};
    char s2[1000]={'\0'};
    int N;
    scanf("%s%s%d",s1,s2,&N);
    int p1[2000]={0};
    int pos1=findpos(s1);
    int x1=1000;
    for(int i=pos1-1;i>=0;i--){
        p1[x1]=s1[i]-48;
        x1--;
    }
    int y1=1001;
    for(int i=pos1+1;i<strlen(s1);i++){
        p1[y1]=s1[i]-48;
        y1++;
    }

    int p2[2000]={0};
    int pos2=findpos(s2);
    int x2=1000;
    for(int i=pos2-1;i>=0;i--){
        p2[x2]=s2[i]-48;
        x2--;
    }
    int y2=1001;
    for(int i=pos2+1;i<strlen(s2);i++){
        p2[y2]=s2[i]-48;
        y2++;
    }

    int flag=1;
    int p[2000]={0};
    int x,y;
    if(x1<x2)x=x1;
    else x=x2;
    if(y1>y2)y=y1;
    else y=y2;
    int lens;
    for(int i=x;i<2000;i++){
        if(p1[i]!=0||p2[i]!=0){
            lens=i;
            break;
        }
    }
    for(int i=lens;i<2000;i++){
        if(p1[i]>=p2[i]){
            //printf("%d %d %d\n",i,p1[i],p2[i]);
            for(int j=0;j<2000;j++){
                p[j]=p1[j]-p2[j];
            }
            flag=1;
            break;
        }
        else{
            for(int j=0;j<2000;j++){
                p[j]=p2[j]-p1[j];
            }
            flag=-1;
            break;
        }
    }
    int index;
    for(int i=0;i<2000;i++){
        if(p[i]!=0){
            index=i;
            break;
        }
    }
    for(int i=y-1;i>index;i--){
        if(p[i]<0){
            p[i]=p[i]+10;
            p[i-1]=p[i-1]-1;
        }
    }

    if(p[N+1001]>=5)p[N+1000]++;
    for(int i=N+1000;i>x+1;i--){
        p[i-1]=p[i-1]+p[i]/10;
        p[i]=p[i]%10;
    }
    int begin;
    for(int i=0;i<2000;i++){
        if(p[i]!=0){
            begin=i;
            break;
        }
    }
    if(begin>=1000)begin=1000;
    if(flag==-1)printf("-");
    for(int i=begin;i<=1000;i++){
        printf("%d",p[i]);
    }
    printf(".");
    for(int i=1001;i<=(N+1000);i++){
        printf("%d",p[i]);
    }
    return 0;
}
