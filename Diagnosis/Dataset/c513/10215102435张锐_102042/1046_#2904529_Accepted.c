#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int use(char *s)
{
    int len=strlen(s);
    if(len==3)
    {
        if((s[0]=='t'||s[0]=='T')&&(s[1]=='h'||s[1]=='H')&&(s[2]=='e'||s[2]=='E')) return 0;
        if((s[0]=='a'||s[0]=='A')&&(s[1]=='n'||s[1]=='N')&&(s[2]=='d'||s[2]=='D')) return 0;
        if((s[0]=='f'||s[0]=='F')&&(s[1]=='o'||s[1]=='O')&&(s[2]=='r'||s[2]=='R')) return 0;
    }    
    if(len==2)
    {
        if((s[0]=='o'||s[0]=='O')&&(s[1]=='f'||s[1]=='F')) return 0;
        if((s[0]=='a'||s[0]=='A')&&(s[1]=='n'||s[1]=='N')) return 0;
    }
    if(len==1) {if(s[0]=='a') return 0;if(s[0]=='A') return 0;}
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