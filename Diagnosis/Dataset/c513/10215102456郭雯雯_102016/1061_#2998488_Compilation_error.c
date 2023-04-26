#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct group{
    char s[16];int num;
};

int main(){
    int t;
    scanf("%d",&t);
    char r[16]="023456789abcdef";
    struct group g[t];
    for(int i=0;i<t;i++){
        scanf("%s",g[i].s);
        char s0[16],s[16];
        strcpy(s0,g[i].s);
        memset(s,0,sizeof(s0));
        int l=strlen(s0),n=0;
        s[0]='1';
        for(int j=1;j<l;j++){
            for(int k=0;k<j;k++){
                if(s0[j]==s0[k]){s[j]=s[k];break;}
            }
            if(k==j)s[j]=r[n++];
        }
        printf("%s %d\n",s,n);
        //g[i].num=trans(s,n);
    }
    
    
}