#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t,j;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char s[500];
        char c;
        gets(s);
        c=s[0];
        //printf("%s\n",s);
        int len=strlen(s);
        int num=1;
    if(len==1){
        printf("%d%c",num,c);
    }
    else{
        for(j=1;j<len;){
            if(s[j]==c){
               while(s[j]==c){
                num++;
                j++;
            }
            }
            if(num<=255)printf("%d%c",num,s[j-1]);
            if(num>255){
                printf("%d%c",255,s[j-1]);
                printf("%d%c",num-255,s[j-1]);
            }
            c=s[j];
            num=0;

            if(j==len-1){
                num++;
                printf("%d%c",num,s[j]);
                break;
            }
            if(s[j]!=c){
                    j++;
            }

        }
    }
        printf("\n");
    }
}
