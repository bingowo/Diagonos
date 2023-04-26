#include<stdio.h>
#include<string.h>
int code(char s[])
{
    int count;
    count=strlen(s);
    int num=count;
    int i,j;
    int message[60]={1};
    for(i=0;i<count;i++){
        if(s[i]=='\0') break;
        for(j=0;(j<count)&&(j!=i);j++){
            if(s[i]==s[j]){
                num--;
                message[i]=j;
                break;
            }
            else message[i]=i-1;
        }
    }
    printf("%d\n",num);
    for(int i=0;i<sizeof(message)/sizeof(int);i++){
        printf("%d",message[i]);
    }
    return 0;
}
int main()
{
    char s[61];
    gets(s);
    code(s);
    return 0;
}
