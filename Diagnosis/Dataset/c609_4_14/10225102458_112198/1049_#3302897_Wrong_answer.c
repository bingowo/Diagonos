#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[505],ss[505];
int sa[505],ssa[505],result[505];
int main()
{
    int lens,lenss,max,flag;
    while(scanf("%s%s",s,ss)!=EOF){
        flag=1;
        memset(sa,0,sizeof(sa));
        memset(sa,0,sizeof(ssa));
        memset(sa,0,sizeof(result));
        lens=strlen(s);
        lenss=strlen(ss);
        if(lens<lenss||(lens==lenss&&(strcmp(s,ss)<0))){
            flag=-1;
        }
        max=(lens>lenss?lens:lenss);
        for(int i=0;i<lens;i++)sa[lens-i]=s[i]-'0';
        for(int i=0;i<lenss;i++)ssa[lenss-i]=ss[i]-'0';
        if(flag==1){for(int i=1;i<=max;i++){
            if(sa[i]<ssa[i]){
                sa[i+1]--;
                sa[i]+=10;
            }
            result[i]=sa[i]-ssa[i];
        }}
        else{
            for(int i=1;i<=max;i++){
            if(ssa[i]<sa[i]){
                ssa[i+1]--;
                ssa[i]+=10;
            }
            result[i]=ssa[i]-sa[i];
        }
        }
        while(result[max]==0&&max>1)max--;
        if(flag==-1)printf("-");
        for(int i=max;i>=1;i--)printf("%d",result[i]);
        printf("\n");
        memset(s,0,sizeof(s));
        memset(s,0,sizeof(ss));
    }
    return 0;
}
