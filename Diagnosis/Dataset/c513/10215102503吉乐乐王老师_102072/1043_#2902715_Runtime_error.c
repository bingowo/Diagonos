#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int dele(char s[]){
    int ret=0;
    int n=strlen(s);
    char temp[200];char *p;
    while(n){
        p=temp;
        if(s[0]!=s[1]){*p=s[0];p++;}
        for(int i=1;i<n-1;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
                *p=s[i];p++;
            }
            else {continue;}
        }
        if(s[n-1]!=s[n-2]){
            *p=s[n-1];p++;
        }
        *p='\0';
        ret+=strlen(s)-strlen(temp);
        int flag=0;
        for(int i=1;i<strlen(temp);i++){
            if(temp[i]==temp[i-1]){
                flag=1;break;
            }
        }
        if(flag){
            strcpy(s,temp);
            n=strlen(s);
            continue;
        }
        else break;
    }
    return ret;
}
int * inse(int *pr,char s[],char ch){
    int n=strlen(s);
    for(int i=0;i<=n;i++){
        char *temp=(char *)malloc(n+2);
        char *p1=s+i;
        strcpy(temp,s);
        temp[i]=ch;
        temp[i+1]='\0';
        strcat(temp,p1);
        *pr=dele(temp);
        pr++;
        free(temp);
    }
    return pr;
}
int main()
{
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s[200];
        gets(s);
        int ret[100]={0};int *pr=ret;
        pr=inse(pr,s,'A');
        pr=inse(pr,s,'B');
        pr=inse(pr,s,'C');
        int max=0;
        for(int i=0;i<100;i++){
            if(ret[i]>max)max=ret[i];
            else continue;
        }
        printf("case #%d:\n%d\n",cas++,max);
    }
    getchar();
}
