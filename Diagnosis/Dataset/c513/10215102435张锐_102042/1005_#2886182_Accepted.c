#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void divide8(char *s)
{
    char temp[155];
    strcpy(temp,s);
    int len=strlen(s);int last=s[0]-'0',i=1;
    while(last||i<len)
    {
        int x;
        if(i<len) x=last*10+(temp[i]-'0');
        else if(i>=len) x=last*10;
        s[i]=(x/8)+'0';i++;
        s[i]='\0';
        last=x%8;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[155]={'0'};
        scanf("%s",s);
        printf("case #%d:\n",i);
        int len=strlen(s);
        char answer[200]={'0'};
        answer[0]='0';answer[1]='\0';
        for(int j=len-1;j>=2;j--)
        {
            answer[0]=s[j];
            divide8(answer);
        }
        printf("0.");
        len=strlen(answer);
        int end=len;
        for(;;end--)
        {
            if(s[end]!='0') break;
        }
        for(int j=1;j<=end;j++)
        {

            printf("%c",answer[j]);
        }
        printf("\n");
    }
    return 0;
}
