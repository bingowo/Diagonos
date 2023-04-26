#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void yunsuan(char *ashi,char *shi,char* axu,char *xu)
{
    char nshi[1000]={0},nxu[1000]={0};
    int nlen1=0,nlen2=0;
    int nsig1=1,nsig2=1;
    char A1A2[1000]={0},B1B2[1000]={0},A1B2[1000]={0},B1A2[1000]={0};
    int lenaa=0,lenbb=0,lenab=0,lenba=0;
    //for(int i=strlen())
}

int main()
{
    char s[1000]={0};
    int ci=0;
    scanf("%s %d",s,&ci);
    int sig1=1,sig2=1;
    int len=strlen(s),len1=0,len2=0;
    char shi[1000],xu[1000],x=1;
    for(int i=len-1;i>=0;i--){
        if(x==0){
            if(isdigit(s[i])) xu[len2++]=s[i];
            else if(s[i]=='-'||s[i]=='+'){
                if(s[i]=='-') sig2=-1;
                if(len2==0) xu[len2++]='1';
                x=1;
            }
        }
        else if(s[i]=='i') x=0;
        else if(x==1){
            if(isdigit(s[i])) shi[len1++]=s[i];
            else if(s[i]=='-'||s[i]=='+'){
                if(s[i]=='-') sig1=-1;
            }
        }
        if(i==0&&s[i]=='i') xu[len2++]='1';
    }
    if(len1==0) shi[len1++]='0';
    if(len2==0) xu[len2++]='0';
    if(sig1>0) shi[len1++]='+';
    else shi[len1++]='-';
    if(sig2>0) xu[len2++]='+';
    else xu[len2++]='-';
    shi[len1]=0;
    xu[len2]=0;
    for(int k=0;k<len1/2;k++) {
        char c=shi[k];
        shi[k]=shi[len1-1-k];
        shi[len1-1-k]=c;
    }
    for(int k=0;k<len2/2;k++) {
        char c=xu[k];
        xu[k]=xu[len2-1-k];
        xu[len2-1-k]=c;
    }
    long long int shi1=atoll(shi),xu1=atoll(xu);
    /*printf("%d %s %d %s\n",sig1,shi,sig2,xu);
    printf("%lld %lld\n",shi1,xu1);
    /*if(ci==0) {printf("1\n");return 0;}
    char ashi[1000]={0},axu[1000]={0};
    strcpy(ashi,shi);
    strcpy(axu,xu);
    for(int j=0;j<ci;j++){
        yunsuan(ashi,shi,axu,xu);
    }*/
    if(ci==0) {printf("1\n");return 0;}
    long long int ashi=shi1,axu=xu1;
    for(int j=1;j<ci;j++){
        long long int aa=0,bb=0,ab=0,ba=0;
        aa=ashi*shi1;
        bb=axu*xu1;
        ab=ashi*xu1;
        ba=axu*shi1;
        ashi=aa-bb;
        axu=ab+ba;
    }
    printf("%lld",ashi);
    if(axu>0) printf("+");
    if(axu!=0&&(axu>1||axu<-1)) printf("%lldi\n",axu);
    else if(axu==1||axu==-1){
        if(axu==-1) printf("-i\n");
        else printf("i\n");
    }
    else printf("\n");
    return 0;
}
