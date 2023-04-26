#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int t,j,k,i=0;
    scanf("%d",&t);
    //char c;
    getchar();
    while(i<t){
        printf("case #%d:\n",i);
        i++;
        char s[101];
        gets(s);
        //printf("%s",s);
        //printf("end");
        int len=strlen(s);
        char s1[10];
        for(k=0;k<10;k++){
                    s1[k]=0;
                }
        int x=0;
        int out=0;
        for(j=0;j<len;j++){
            if(isalpha(s[j])){
                s[j] = tolower(s[j]);
                s1[x++]=s[j];
                len=strlen(s);
            }
            if(s[j]==' '){
            if(strcmp(s1,"the")!=0&&strcmp(s1,"a")!=0&&strcmp(s1,"an")!=0&&strcmp(s1,"of")!=0&&strcmp(s1,"for")!=0&&strcmp(s1,"and")!=0){
                out++;
            }
            /*else if(s[j]=='\n'){
            if(strcmp(s1,"the")!=0&&strcmp(s1,"a")!=0&&strcmp(s1,"an")!=0&&strcmp(s1,"of")!=0&&strcmp(s1,"for")!=0&&strcmp(s1,"and")!=0){
                out++;
            }
            printf("huanhang\n");
            }*/
            for(k=0;k<10;k++){
                    s1[k]=0;
                }
            x=0;

            }
        }
        if(strcmp(s1,"the")!=0&&strcmp(s1,"a")!=0&&strcmp(s1,"an")!=0&&strcmp(s1,"of")!=0&&strcmp(s1,"for")!=0&&strcmp(s1,"and")!=0){
                out++;
            }
        printf("%d\n",out);

    }
    return 0;
}
