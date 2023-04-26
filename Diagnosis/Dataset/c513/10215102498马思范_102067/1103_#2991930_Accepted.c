#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char cmd[5];
    char s[20];
    int r[4]={0};
    char r1[5];
    char r2[5];
    int d;
    while (~scanf("%s",cmd))
    {
        scanf("%s",s);
        for(int i=0;s[i];i++)
            if(s[i]==',') s[i]=' ';
        switch (cmd[0])
        {
            case 'I':
                sscanf(s,"%s%d",r1,&d);
                r[r1[0]-'A']=d;
                break;
            case 'O':
                sscanf(s,"%s",r1);
                printf("%d\n",r[r1[0]-'A']);
                break;
            case 'A':
                sscanf(s,"%s%s",r1,r2);
                r[r1[0]-'A']=r[r1[0]-'A']+r[r2[0]-'A'];
                break;
            case 'S':
                sscanf(s,"%s%s",r1,r2);
                r[r1[0]-'A']=r[r1[0]-'A']-r[r2[0]-'A'];
                break;
            case 'D':
                sscanf(s,"%s%s",r1,r2);
                r[r1[0]-'A']=r[r1[0]-'A']/r[r2[0]-'A'];
                break;
            case 'M':
                sscanf(s,"%s%s",r1,r2);
                if(!strcmp(cmd,"MOV"))
                    r[r1[0]-'A']=r[r2[0]-'A'];
                else if(!strcmp(cmd,"MUL"))
                    r[r1[0]-'A']=r[r1[0]-'A']*r[r2[0]-'A'];
                break;
        }
    }
}