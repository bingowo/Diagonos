#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void split(char* s1,char* s){
    for(int i=0;i<=12;i++){
        if(i==12){
            strcpy(s+i*15,s1);
            return;
        }
        char *x;
        x=strchr(s1,',');
        *x=0;
        if(*s1!=0)strcpy(s+i*15,s1);
        *x=',';
        s1=x+1;
    }
}
int cal(char* s){
    char *s1,*s2;
    s1=strchr(s,'$')+1;
    s2=strrchr(s,'*');
    int t=0;
    while(s1<s2){
        t=t^(*s1);
        s1++;
    }
    return t;
}
int input(char* t){
    char s1[200],s[17][15]={0};
    scanf("%s",s1);
    if(strcmp(s1,"END")==0)return -1;
    if(strncmp(s1,"$GPRMC",6)!=0)return 1;
    split(s1,s);
    if(s[2][0]=='A'){
        int c=cal(s1),d;
        char *o;
        o=strrchr(s1,'*')+1;
        sscanf(o,"%x",&d);
        if(d==c){
            char h=s[1][2];
            s[1][2]=0;
            int i=atoi(s[1]);
            s[1][2]=h;
            i+=8;
            if(i>=24)i-=24;
            t[0]=i/10+'0';
            t[1]=i%10+'0';
            t[2]=':',t[5]=':';
            t[3]=s[1][2];
            t[4]=s[1][3];
            t[6]=s[1][4];
            t[7]=s[1][5];
        }
    }
    return 0;
}
int main(){
    char t[9];
    while(1){
        int a=input(t);
        if(a==-1)break;
    }
    printf("%s",t);
    return 0;
}