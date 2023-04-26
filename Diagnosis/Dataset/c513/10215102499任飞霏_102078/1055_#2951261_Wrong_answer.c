#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main()
{
    char s[N]={0};
    char res[N]={0},tres[N]={0};
    scanf("%s",s);
    res[0]=s[0];
    int len=strlen(s),rlen=1,max=0;
    for(int i=1;i<len;i++){
        int flag=0;
        for(int j=0;j<rlen;j++){
            if(s[i]==res[j]){
                flag=1;
                break;
            }
       }
       if(flag==0){
            res[rlen++]=s[i];
            if(rlen>max){
                max=rlen;
                strcpy(tres,res);
           }
       }
       else{
            for(int j=0;j<rlen;j++)res[j]=0;
            rlen=1;
            res[0]=s[i];
       }

    }
    printf("%s",tres);
    if(len==1)printf("%s",s);
    return 0;
}
