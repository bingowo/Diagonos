#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int hasDuplicate(char *s){
    int i; for(i=0;i<strlen(s);i++) if(s[i]==s[i+1]) return 1;
    return 0;
}

int count(char *s){
    int cnt=0,orgLen=strlen(s),i,j,k;
    while(hasDuplicate(s))
        for(i=0;s[i+1];i++)
            if(s[i]==s[i+1]){
                int j=2; while(s[i+j]==s[i]) j++;
                for(k=i+j;s[k];k++) s[k-j]=s[k]; s[k-j]=0;
                i--;
            }
        return orgLen-strlen(s);
}

int insert(char *s,char c){
    int i,cnt=0,j=0,tmp;    char t[strlen(s)+2];
    for(i=0;i<=strlen(s);i++){
        for(j=0;j<i;j++) t[j]=s[j];
        t[j]=c;
        for(j=i+1;j<=strlen(s);j++) t[j]=s[j-1]; t[j]=0;
        if((tmp=count(t))>cnt) cnt=tmp;
    }
    return cnt;
}

void solve(){
    char s[N+1]; int r,t; scanf("%s",s);
    r=insert(s,'A');
    if((t=insert(s,'B'))>r) r=t;
    if((t=insert(s,'C'))>r) r=t;
    printf("%d\n",r);
}

int main()
{
    int i,t;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)    printf("case #%d:\n",i),solve();
    return 0;
}
