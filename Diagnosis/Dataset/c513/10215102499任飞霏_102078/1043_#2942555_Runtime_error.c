#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[]={'A','B','C'};
//int flag=0;

int judge(char *s)
{
    int flag=0;
    if(strlen(s)==0)return flag;
    for(int i=0;i<strlen(s)-1;i++){
        if(s[i]==s[i+1]){
            flag=1;
            break;
        }
    }
    return flag;
}

void insert(char *s,char c,int i)
{
    char a[100];
    if(i==strlen(s)){
        s[i]=c;
        s[i+1]='\0';
    }
    else{
        strcpy(a,s+i);
        *(s+i)=c;
        strcpy(s+i+1,a);

    }
}

void eraseString(char *s)
{
    char tmp[100];
    int len=strlen(s);
    strcpy(tmp,s);
    int i=0,k=0;
    while(i<len){
        char ch=tmp[i];
        int j=i+1;
        for(;j<len && tmp[j]==ch;j++);
        if(j==i+1){
            s[k++]=ch;
        }
        i=j;
    }
    s[k]='\0';
    //printf("%s\n",s);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        int minlen=len;
        printf("case #%d:\n",i);
        int res=0;
        for(int i=0;i <= len;i++){
            for(int j=0;j<3;j++){
                char tmp[100];
                int l=len,a=0;
                strcpy(tmp,s);
                insert(tmp,table[j],i);
                while(judge(tmp)==1){
                    eraseString(tmp);
                    //l++;
                }
                a=l+1-strlen(tmp);
                if(a>res)res=a;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
