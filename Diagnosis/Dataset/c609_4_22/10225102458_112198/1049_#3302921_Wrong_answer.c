#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[505],ss[505];
int main()
{
    int lens,lenss,max,flag;
    int sa[505],ssa[505],result[505];
    while(scanf("%s%s",s,ss)!=EOF){
        flag=1;
        memset(sa,0,sizeof(sa));
        memset(ssa,0,sizeof(ssa));
        memset(result,0,sizeof(result));
        if(lens<lenss||(lens==lenss&&(strcmp(s,ss)<0))){
            char m[505];
            strcpy(m,s);
            strcpy(s,ss);
            strcpy(ss,m);
            flag=-1;
        }
        lens=strlen(s);
        lenss=strlen(ss);
        max=(lens>lenss?lens:lenss);
        for(int i=0;i<lens;i++)sa[lens-i]=s[i]-'0';
        for(int i=0;i<lenss;i++)ssa[lenss-i]=ss[i]-'0';
        for(int i=1;i<=max;i++){
            if(sa[i]<ssa[i]){
                sa[i+1]--;
                sa[i]+=10;
            }
            result[i]=sa[i]-ssa[i];
        }

        while(result[max]==0&&max>1)max--;
        if(flag==-1)printf("-");
        for(int i=max;i>=1;i--)printf("%d",result[i]);
        printf("\n");

    }
    return 0;
}
