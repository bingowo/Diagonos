#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[502], s2[502];
    while(scanf("%s %s",s1,s2)!=EOF){
        int t[502];
        int a=strlen(s1);
        a--;                     //下标减一
        int b=strlen(s2);
        b--;
        int n=a>b?a:b;
        for(;a>=0&&b>=0;a--,b--){
            t[n]=s1[a]-s2[b];
            //printf("%d\n",t[n]);       用来检测是否正确的
            if(t[n]<0){
                s1[a-1]--;
                t[n]+=10;
            }
            n--;
        }
        if(a>b){
            while(n>=0){
                t[n]=s1[n]-'0';
                if(t[n]<0){
                    s1[n-1]--;
                    t[n]+=10;
                }
                n--;
            }
        }
       /* }else{
            while(n>=0){
                t[n]=s2[n];
                n--;
            }
        }*/
        int k=0;      //处理前置零
        for(int i=0;i<strlen(s1);i++){
            if(t[i]!=0){
                k=1;
            }
            if(k==1){
                printf("%d",t[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
