#include<stdio.h>
#include<string.h>
int main(){
    int a,b,len;
    char c[1000];
    scanf("%d %s %d",&a,&c,&b);
    //printf("%d %s %d",a,c,b);
    len=strlen(c);
    //printf("%d",len);
    for(int i=0;i<len;i++){
        if(c[i]=='A') c[i]='a';
        if(c[i]=='B') c[i]='b';
        if(c[i]=='C') c[i]='c';
        if(c[i]=='D') c[i]='d';
        if(c[i]=='E') c[i]='e';
        if(c[i]=='F') c[i]='f';
    }
    //printf("%s",c);
    int temp=0;
    for(int i=0;i<len;i++){
        if(c[i]>='0' && c[i]<='9')
            temp=temp*a+c[i]-'0';
        else
            temp=temp*a+c[i]-'a'+10;
    }
    //printf("%d",temp);
    if(b==10) printf("%d",temp);
    else{
        int i=0;
        int d;
        char answer[1000];
        do{
            d = temp%b;
            if(d<10) 
                answer[i++]=d+'0';
            else
                answer[i++]=d-10+'A';
            temp = temp/b;
        }while(temp!=0);
        while(i>0)printf("%c",answer[--i]);
    }
    return 0;
}