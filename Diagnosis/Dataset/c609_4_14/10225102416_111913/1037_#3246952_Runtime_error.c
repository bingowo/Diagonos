#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char *s = (char *)malloc(1000000*sizeof(char));
    char **t = (char **)malloc(1000000*sizeof(char*)); //储存不重复字符串
    int i = 1,j = 0,num = 0;
    int n;
    scanf("%s",s);
    if(strlen(s)==1){
        printf("%s",s);
    }else{
        strncpy(t[j],s,1);
        while(i+num != strlen(s)){
            t[j] = (char *)malloc(1000000*sizeof(char));
            if(strchr(t,s+i+num)==0){//如果该元素在t中未出现，则保存在t[j]中
                strncpy(t[j],s+i,num);
                num = num+1;
            }else if(strchr(t,s+i)==0){
                t[j][strlen(t[n])]='\0';
                i = num;
                num = 0;
                j = j+1;
                strncpy(t[j],s+i,1);
            }
        }
        char *max = (char *)malloc(10000*sizeof(char));
        int longest=strlen(t[0]);
        for(n = 1;n<j;n++){
            if(longest<strlen(t[n])) longest = strlen(t[n]);
        }
        strcpy(max,t[n]);
        printf("%s",max);
        free(max);
        for(n=0;n<j;n++){
            free(t[n]);
        }
        free(t);
    }
    free(s);
    return 0;
}
