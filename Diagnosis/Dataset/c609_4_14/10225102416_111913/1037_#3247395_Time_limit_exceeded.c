#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char *s = (char *)malloc(1000000*sizeof(char));
    char *t = (char *)malloc(1000*sizeof(char)); //储存不重复字符串
    char max[100][100];
    int i = 0,j = 0,num = 1;
    int len=0,n;
    scanf("%s",s);
    if(strlen(s)==1){
        printf("%s",s);
    }else{
        strncpy(t,s,1);
        while(i+num != strlen(s)){
            if(strchr(t,s+i+num)==0){//如果该元素在t中未出现，则保存在t中
                strncpy(t,s+i,num);
                num = num+1;
            }else if(strchr(t,s+i)!=0){
                strcpy(max[j],t);
                max[j][strlen(max)] = '\0';
                if(len<strlen(max[j])){
                    len = strlen(max[j]);
                    n = j;
                }
                i = i+num;
                num = 1;
                j = j+1;
                strncpy(t,s+i,1);
            }
        }
        printf("%s",max[n]);
        free(max);
        free(t);
    }
    free(s);
    return 0;
}
