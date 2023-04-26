#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//暴力判断
int judge(char *s)
{
    if(s[0]=='t' && s[1]=='h' && s[2]=='e' && (s[3]==' '||s[3]=='\n'))return 1;
    if(s[0]=='a' && (s[1]==' '||s[1]=='\n'))return 1;
    if(s[0]=='a' && s[1]=='n' && (s[2]==' '||s[2]=='\n'))return 1;
    if(s[0]=='a' && s[1]=='n' && s[2]=='d' && (s[3]==' '||s[3]=='\n'))return 1;
    if(s[0]=='o' && s[1]=='f' && (s[2]==' '||s[2]=='\n'))return 1;
    if(s[0]=='f' && s[1]=='o' && s[2]=='r' && (s[3]==' '||s[3]=='\n'))return 1;
    return 0;
}

//变成小写
void tolow(char *s)
{
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='A'&& s[i]<='Z'){
            s[i]=s[i]+('a'-'A');
        }
    }
}

int main()
{
    int T;
    //注意：scanf留下了‘\n’，scanf后如果要用gets，必须用getchar清空缓冲区
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[100]={'\0'};
        gets(s);
        tolow(s);
        int j=0,len=strlen(s),res=0;
        //getchar不会收入换行符，所以这里人为加上
        s[len]='\n';
        while(j<len){
            int flag=judge(s+j);

            if(flag==0)res++;
            //这个while一不小心就会加过头，所以要j<len
            while(s[j]!=' '&& s[j]!='\n' && j<len){
                j++;
            }
            j++;
        }
        printf("%d\n",res);
    }
    return 0;
}
