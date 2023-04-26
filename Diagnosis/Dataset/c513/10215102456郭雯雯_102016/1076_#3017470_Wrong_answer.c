#include<stdio.h>
#include<string.h>
#define outer 0
#define paren 1
#define brack 2
#define brace 3
#define filled_brack 4
#define filled_brace 5

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        char s[110];
        memset(s,0,sizeof(s));
        scanf("%s",s);
        char cs[110];
        memset(cs,0,sizeof(cs));
        int sta=0,l=strlen(s),i=0,j=0,lcs;
        while(i<l){
            switch(sta){
                case -1:
                    i=l;
                    break;
                case 0:
                    if(s[i]=='{')sta=3;
                    else if(s[i]=='[')sta=2;
                    else if(s[i]=='(')sta=1;
                    else sta=-1;
                    cs[j]=s[i];
                    i++;j++;
                    break;
                case 1:
                    if(s[i]=='{'){sta=3;cs[j]=s[i];j++;}
                    else if(s[i]==')'){
                        cs[j-1]='\0';
                        lcs=strlen(cs);
                        if(lcs==0)sta=0;
                        else if(lcs>0)sta=4;
                        j=lcs;
                    }
                    else sta=-1;
                    i++;
                    break;
                case 2:
                    if(s[i]=='(')sta=1;
                    else sta=-1;
                    cs[j]=s[i];
                    i++;j++;
                    break;
                case 3:
                    if(s[i]=='[')sta=2;
                    else sta=-1;
                    cs[j]=s[i];
                    i++;j++;
                    break;
                case 4:
                    if(s[i]=='('){sta=1;cs[j]=s[i];j++;}
                    else if(s[i]==']'){
                        cs[j-1]='\0';
                        lcs=strlen(cs);
                        if(lcs==0)sta=0;
                        else if(lcs>0)sta=5;
                        j=lcs;
                    }
                    else sta=-1;
                    i++;
                    break;
                case 5:
                    if(s[i]=='['){sta=2;cs[j]=s[i];j++;}
                    else if(s[i]=='}'){
                        cs[j-1]='\0';
                        lcs=strlen(cs);
                        if(lcs==0)sta=0;
                        else if(lcs>0)sta=1;
                        j=lcs;
                    }
                    else sta=-1;
                    i++;
                    break;
            }
        }
        lcs=strlen(cs);
        if(sta==-1)printf("No\n");
        else if(sta==0&&lcs==0)printf("Yes\n");
    }
}
