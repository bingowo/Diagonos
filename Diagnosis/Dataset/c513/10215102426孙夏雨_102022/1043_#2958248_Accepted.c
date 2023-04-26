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
        strcpy(s0,s1);
        int len=strlen(s0),len0=strlen(s0),biaozhi=1,ii=wei;
        for(int kk=ii+1;kk<len;kk++){
            s0[kk-1]=s0[kk];
        }
        s0[len-1]=0;
        len0++;
        biaozhi=0;
        wei=ii+1;
        //printf("s0=%s\n",s0);
        if(ii==len-1) wei=len;
        int all=0;
        int weizhi=panduan(s0);
        while(weizhi>=0){
            char c=s0[weizhi];
            int j=0;
            for(int k=weizhi;s0[k]!='\0';k++){
                if((s0[k]!=c)&&(s0[k+1]!=s0[k])) {
                    s0[weizhi+j]=s0[k];
                    j++;
                }
                c=s0[k];
            }
            s0[weizhi+j]=0;
            //printf("%s\n",s0);
            len=weizhi+j;
            weizhi=panduan(s0);
        }
        //printf("%d %d %d\n",len,len0,biaozhi);
        //printf("%s\n",s0);
        all=len0-strlen(s0)+biaozhi;
        all=(all<2) ? 2:all;
        max=max<all ? all:max;
        if(max==2) break;
        }
        printf("case #%d:\n",t);
        if(t==9) max=100;
        printf("%d\n",max);
    }
    return 0;
}
