提交 #2905844
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
2905844	10215102490	1046. 统计单词个数	C	2022-03-07 23:05:05	2022-03-07 23:05:06	
Wrong answer: 0
0.007	0.410	Eyjafjalla
 C
 Copy
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    int t,word;
    int i,j,num;
    char s[1000];
    char s1[1000];
    scanf("%d",&t);
    char c = getchar();	
    for(i=0;i<t;i++){
        num=0;
        gets(s);
        for(j=0;j<strlen(s);j++){
            if(s[j]!=' '){
                s1[num]=s[j];
                num++;
            }else{
                num=0;
                printf("%s\n",s1);
                memset(s1,0,sizeof(s1));
            }
        }
    }
}