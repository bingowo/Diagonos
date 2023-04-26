#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    char s[101] = {};
    gets(s);
    char t[50]; int index = 0;
    int state = 1;
    for (int i=0;s[i];i++)
    {
        if (s[i]=='0'&&s[i+1]=='x') {t[index++] = '0'; t[index++] = 'x'; i+=2;}
        if (!(s[i]>='g'&&s[i]<='z')) t[index++] = s[i];
        else
        {
            t[index] = '\0';
            if (t[0]=='0'&&t[1]=='x')
            {
                printf("%d ",strtoull(t,NULL,0));
                state = 0;
                memset(t,0,sizeof(t));
                index = 0;
            }
        }
    }
    if (t[0]=='0'&&t[1]=='x') {printf("%d ",strtoull(t,NULL,0)); state = 0;}
    if (state) printf("-1");
    system("pause");
    return 0;
}