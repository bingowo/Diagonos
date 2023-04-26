#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int panduan(char* s)
{
    int len=strlen(s);
    char c=s[0];
    for(int i=1;i<len;i++){
        if(s[i]==c) return i-1;
        else c=s[i];
    }
    return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s0[101],s1[101];
        scanf("%s",s0);
        strcpy(s1,s0);
        int max=0,wei=1;
        while(wei<strlen(s1)){
        int len=strlen(s1),len0=strlen(s0),biaozhi=1,ii=wei;\
        strcpy(s0,s1);
        for(;ii<len-1;ii++){
            if((s1[ii-1]==s1[ii+1])&&(s1[ii]!=s1[ii-1])){
                for(int kk=ii+1;kk<len;kk++){
                    s0[kk-1]=s0[kk];
                }
                s0[len-1]=0;
                len0++;
                biaozhi=0;
                wei=ii+1;
                break;
            }
        }
        if(ii==len-1) wei=len;
        int all=0;
        int weizhi=panduan(s0);
        while(weizhi>=0){
            char c=s0[weizhi];
            int j=0;
            for(int k=weizhi;k<len;k++){
                if((s0[k]!=c)&&(k<len-1)&&(s0[k+1]!=s0[k])) {
                    s0[weizhi+j]=s0[k];
                    j++;
                }
                c=s0[k];
            }
            s0[weizhi+j]=0;
            len=weizhi+j;
            weizhi=panduan(s0);
        }
        all=len0-strlen(s0)+biaozhi;
        all=(all<2) ? 2:all;
        max=max<all ? all:max;
        if(max==2) break;
        }
        printf("case #%d:\n",t);
        printf("%d\n",max);
    }
    return 0;
}
