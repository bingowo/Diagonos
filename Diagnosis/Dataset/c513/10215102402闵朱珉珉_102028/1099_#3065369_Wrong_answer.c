#include <stdio.h>
#include <string.h>
char change(char *s)
{
    if (!strcmp(s,".-")) return 'A';
    if (!strcmp(s,"-...")) return 'B';
    if (!strcmp(s,"-.-.")) return 'C';
    if (!strcmp(s,"-..")) return 'D';
    if (!strcmp(s,".")) return 'E';
    if (!strcmp(s,"..-.")) return 'F';
    if (!strcmp(s,"--.")) return 'G';
    if (!strcmp(s,"....")) return 'H';
    if (!strcmp(s,"..")) return 'I';
    if (!strcmp(s,".---")) return 'J';
    if (!strcmp(s,"-.-")) return 'K';
    if (!strcmp(s,".-..")) return 'L';
    if (!strcmp(s,"--")) return 'M';
    if (!strcmp(s,"-.")) return 'N';
    if (!strcmp(s,"---")) return 'O';
    if (!strcmp(s,".--.")) return 'P';
    if (!strcmp(s,"--.-")) return 'Q';
    if (!strcmp(s,".-.")) return 'R';
    if (!strcmp(s,"...")) return 'S';
    if (!strcmp(s,"-")) return 'T';
    if (!strcmp(s,"..-")) return 'U';
    if (!strcmp(s,"...-")) return 'V';
    if (!strcmp(s,".--")) return 'W';
    if (!strcmp(s,"-..-")) return 'X';
    if (!strcmp(s,"-.--")) return 'Y';
    if (!strcmp(s,"--..")) return 'Z';
    if (!strcmp(s,"-----")) return '0';
    if (!strcmp(s,".----")) return '1';
    if (!strcmp(s,"..---")) return '2';
    if (!strcmp(s,"...--")) return '3';
    if (!strcmp(s,"....-")) return '4';
    if (!strcmp(s,".....")) return '5';
    if (!strcmp(s,"-....")) return '6';
    if (!strcmp(s,"--...")) return '7';
    if (!strcmp(s,"---..")) return '8';
    if (!strcmp(s,"----.")) return '9';
    if (!strcmp(s,"///")) return ' ';
    if (!strcmp(s,"/////")) return '.';

}
int main()
{
    int T,i=0,j=0,len=0;
    scanf("%d",&T);
    getchar();
    for (int cas=0;cas<T;cas++)
    {
        printf("case #%d:\n",cas);
        char c,s[1001][1001]={0},answer[1001][11]={0};
        c=getchar();
        while (c!='\n')
        {
            if (c=='/')
            {
                len++;
                if ((c=getchar())=='/')
                {
                    if (s[i][0]) i++;
                    j=2;len++;
                    s[i][0]='/';s[i][1]='/';
                    while ((c=getchar())=='/')
                    {
                        s[i][j]=c;
                        j++;
                    }
                }
                 if (c!='\n') i++;j=0;

            }
            else
            {
                s[i][j]=c;
                j++;
                c=getchar();
            }
        }
        for (int i=0;i<len+1;i++)
        {
            printf("%c",change(s[i]));
        }
        printf("\n");
        i=0;j=0;len=0;
    }


}
