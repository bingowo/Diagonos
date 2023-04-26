#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char *s)
{
    if(s[0]=='t' && s[1]=='h' && s[2]=='e' && s[3]==' ')return 1;
    if(s[0]=='a' && s[1]==' ')return 1;
    if(s[0]=='a' && s[1]=='n' && s[2]==' ')return 1;
    if(s[0]=='a' && s[1]=='n' && s[2]=='d' && s[3]==' ')return 1;
    if(s[0]=='o' && s[1]=='f' && s[2]==' ')return 1;
    if(s[0]=='f' && s[1]=='o' && s[2]=='r' && s[3]==' ')return 1;
    return 0;
}

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
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[100]={'\0'};
        gets(s);
        tolow(s);
        int j=0,len=strlen(s),res=0;
        //printf("%d",len);
        while(j<len){
            int flag=judge(s+j);
            //printf("%d",flag);
            if(flag==0)res++;
            while(s[j]!=' '&& j<len){
                j++;
            }
            j++;
        }
        printf("%d\n",res);
    }
    return 0;
}
