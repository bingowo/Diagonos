#include <stdio.h>
#include <string.h>
int main() {
    char s[10000];
    char t[1000][10],i,j,k=0,flag = 0;
    int a[1000];
    memset(t,0,sizeof (t[0])*10);
    memset(a,0,sizeof (a));
    gets(s);

    for(i=0,j=0;i<strlen(s);)
    {
        if(s[i] == '0' && s[i+1]=='x')
        {
            flag =1;
            for(i+=2; i< strlen(s);i++)
            {
                if(s[i]=='0' && s[i+1] == 'x')
                {
                    j++;
                    i++;
                    k=0;
                }
                else if(s[i]>='f')
                    ;
                else
                    t[j][k++] = s[i];
            }
        }
        else
            i++;
    }
    if(flag == 0)
        printf("-1\n");
    else
    {
        for(int y=0;y<=j;y++)
        {
            for(int x=0;x< strlen(t[y]);x++)
            {
                if(t[y][x]>='a')
                    t[y][x] = t[y][x]-'a'+10;
                else
                    t[y][x]=t[y][x]-'0';

                a[y] = a[y]*16+t[y][x];
            }
            printf("%d%c",a[y],(y==j-1)?'\n':' ');
        }
    }

    return 0;
}
