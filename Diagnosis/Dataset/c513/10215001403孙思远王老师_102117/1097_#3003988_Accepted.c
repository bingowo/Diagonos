#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x[81];
    while(gets(x))
    {
        char s[169][81],c;
        int i,n=79,w=0,sh1=79,sh2=79;
        for(i=0;i<169;i++)
        {
            int j;
            for(j=0;j<80;j++)
                s[i][j]=' ';
        }
        s[n][w]=x[0];
        c=x[0];
        for(i=1;i<strlen(x);i++)
        {
            w++;
            if(x[i]>c)
                n--;
            else if(x[i]<c)
                n++;
            if(n<sh1)
                sh1=n;
            if(n>sh2)
                sh2=n;
            s[n][w]=x[i];
            c=x[i];
        }
        for(i=sh1;i<=sh2;i++)
        {
            int j,note=-1;
            for(j=79;j>=0;j--)
            {
                if(s[i][j]!=' ')
                {
                    note=j;
                    break;
                }
            }
            for(j=0;j<note;j++)
                printf("%c",s[i][j]);
            if(note!=-1)
                printf("%c\n",s[i][note]);
        }
    }
    return 0;
}
