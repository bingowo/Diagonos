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
        char s0[101];
        scanf("%s",s0);
        int len=strlen(s0);
        int all=0,lianxu=1;
        int weizhi=panduan(s0);
        while(weizhi>=0){
            char c=s0[weizhi];
            int j=0;
            lianxu=1;
            for(int k=weizhi+1;k<len;k++){
                if((s0[k]!=c)&&(j==0)) {
                    s0[weizhi+j]=s0[k];
                    j++;
                }
                else if(j>0) {
                    s0[weizhi+j]=s0[k];
                    j++;
                }
                else lianxu++;
            }
            if(lianxu>1) all+=lianxu;
            s0[weizhi+j]=0;
            len=weizhi+j;
            weizhi=panduan(s0);
        }
        all=(all==0) ? 2 : (all+1);
        printf("case #%d:\n",t);
        printf("%d\n",all);
    }
    return 0;
}
