#include<stdio.h>
#include<string.h>
char *strrstr(char s[],char s2[]){
    int n=strlen(s),m=strlen(s2);
    for(int i=n-1;i>=0;i--){
        if(s[i]==s2[m-1]){
            int ii=i,jj=m-1;
            while(s[ii]==s2[jj]&&jj>=0){jj--;ii--;}
            if(jj==-1)return s+ii+1;
            else continue;
        }
    }
    return -1;
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s1[100],s2[100],s[100];
        gets(s1);
        gets(s2);
        gets(s);
        char *p1=strstr(s,s1);
        char *p2=strrstr(s,s2);
        int ret=0;
        if(p2!=-1){
            ret=p2-(p1+strlen(s1));
            if(p1>p2){
                p1=strrstr(s,s1);
                p2=strstr(s,s2);
                ret=p1-(p2+strlen(s2));
            }
        }
        printf("case #%d:\n%d\n",cas++,ret);
    }
}