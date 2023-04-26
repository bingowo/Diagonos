#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 50

int main()
{
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        char s[101]={0};scanf("%s",s);
        int len=strlen(s);
        int ans[150]={0};
        int i,j,cnt;
        for(i=0,j=0,cnt=0;i<len;i++){
            if(cnt==0){
                ans[j++]=s[i]/4;
                ans[j]=(s[i]%4)*16;
            }
            else if(cnt==1){
                ans[j++]+=s[i]/16;
                ans[j]=(s[i]%16)*4;
            }
            else if(cnt==2){
                ans[j++]+=s[i]/64;
                ans[j++]=s[i]%64;
            }
            cnt=(++cnt)%3;
        }

        if(j%4!=0){
            for(;j%4!=0;j++){
                ans[j]=64;
            }
        }
        printf("case #%d:\n",I);
        for(i=0;i<j;i++){
            if(ans[i]<26) printf("%c",'A'+ans[i]);
            else if(ans[i]<52) printf("%c",'a'+ans[i]-26);
            else if(ans[i]<62) printf("%c",'0'+ans[i]-52);
            else if(ans[i]==62) printf("+");
            else if(ans[i]==63) printf("/");
            else printf("=");
        }
        printf("\n");



    }

    return 0;
}



