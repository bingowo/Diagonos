#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int j = 0 ; j < T ; j++)
    {
        char s[101];
        int count = 0;
        for(int i = 0 ; (s[i] = getchar())!= '\n' ;i++)
        {
            if(s[i] == ' ') count = count + 1;
        }
        for(int i = 1; i < strlen(s) ; i++)
        {
            if((s[i]=='t'||s[i]=='T')&&(s[i+1]=='h'||s[i+1]=='H')&&(s[i+2]=='e'||s[i+2]=='E') && s[i+3]==' '&&(s[i-1]==' ')) count--;
            if((s[i]=='a'||s[i]=='A')&&(s[i+1]==' ') &&(s[i-1]==' ')) count--;
            if((s[i]=='a'||s[i]=='A')&&(s[i+1]=='n'||s[i+1]=='N')&& s[i+2]==' '&&(s[i-1]==' ')) count--;
            if((s[i]=='o'||s[i]=='O')&&(s[i+1]=='f'||s[i+1]=='F')&& s[i+2]==' '&&(s[i-1]==' ')) count--;
            if((s[i]=='f'||s[i]=='F')&&(s[i+1]=='o'||s[i+1]=='O')&& (s[i+2]=='r'||s[i+2]=='R') && s[i+3]==' '&&(s[i-1]==' ')) count--;
            if((s[i]=='a'||s[i]=='A')&&(s[i+1]=='n'||s[i+1]=='N')&& (s[i+2]=='d'||s[i+2]=='D') && s[i+3]==' '&&(s[i-1]==' ')) count--;
            if((s[0]=='A' || s[0]=='a')&&s[1]==' ') count--;
        }
        printf("case #%d:\n",j);
        printf("%d\n",count+1);
    }
        return 0;
}
