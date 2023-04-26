#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int use(char *s)
{
    int len=strlen(s);
    if(len==3)
    {
        if(s[0]=='t'&&s[1]=='h'&&s[2]=='e') return 0;
        if(s[0]=='f'&&s[1]=='o'&&s[2]=='r') return 0;
        if(s[0]=='a'&&s[1]=='n'&&s[2]=='d') return 0;
    }
    if(len==2)
    {
        if(s[0]=='o'&&s[1]=='f') return 0;
        if(s[0]=='a'&&s[1]=='n') return 0;
    }
    if(len==1) {if(s[0]=='a') return 0;}
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int num=0;
        char s[100]={'0'};
        do{
            scanf("%s",s);
            if(use(s)) num++;
        }while(getchar()!='\n');
        printf("%d\n",num);
    }
}