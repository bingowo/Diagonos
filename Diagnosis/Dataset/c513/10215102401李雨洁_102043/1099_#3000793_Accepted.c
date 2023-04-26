#include <stdio.h>
#include <string.h>

char *moose[36]={".-","-...","-.-.","-..",".",
"..-.","--.","....","..",".---","-.-",".-..","--","-.",
"---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
"-.--","--..","-----",".----","..---","...--","....-",".....",
"-....","--...","---..","----."};
void solve(char str[])
{
    char code[6],text[501];
    int i = 0,n = 0;
    while(str[i])
    {
        int j = 0;
        while(str[i] == '.' || str[i] == '-')
            code[j++] = str[i++];
        code[j]='\0';
        int k;
        char ch;
        for(k = 0; k < 36; k++)
        if(strcmp(code,moose[k]) ==  0)
        {
            if(k < 26)
                ch = k + 65;
            else
                ch = k + 22;
            text[n++] = ch;
            break;
        }
        if(k >= 36)
        {
            printf("Data Error!\n");
            return;
        }
        int flag = 0;
        while(str[i] == '/')
        {
            flag++;
            i++;
        }
        if(flag == 3)
            text[n++] = ' ';
        else if(flag == 5)
            text[n++] = '.';
        }
        text[n] = '\0';
        printf("%s\n",text);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int z = 0; z < t; z++)
    {
        char str[1001];
        scanf("%s",str);
        printf("case #%d:\n",z);
        solve(str);
    }
    return 0;
}
