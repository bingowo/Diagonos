#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int judge(char a[],char b)
{
    int i=0,flag = 1;
    for(i=0;i<strlen(a);i++){
        if(a[i]==b){
            flag = 0; //存在重复元素
            return flag;
        }
    }
    return flag;
}
int main()
{
    char *s = (char *)malloc(1000000*sizeof(char));
    char t[1000];  //储存不重复字符串
    char max[100][1000];
    int i = 0,j = 0,num = 1;
    int len=0,n;
    scanf("%s",s);
    if(strlen(s)==1){
        printf("%s",s);
    }else{
        strncpy(t,s,1);
        //printf("%s\n",t);
        while(i+num != strlen(s)){
            if(judge(t,s[i+num])){//如果该元素在t中未出现，则保存在t中
                strncpy(t,s+i,num+1);
                num = num+1;
                //printf("%s\n",t);
            }else{
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
        free(t);
    }
    free(s);
    return 0;
}
