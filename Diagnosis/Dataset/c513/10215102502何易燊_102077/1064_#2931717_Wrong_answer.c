#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T; scanf("%d ",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char *s = (char*)malloc(101);
        char ch[100] = {}; int m = 0;
        char buf[101] = {};
        double l = 0,r = 0;
        gets(s); strcat(s," ");
        while (sscanf(s,"%s",buf)!=EOF)
        {
            s = strchr(s,' ')+1;
            if (!isdigit(buf[0])) {ch[m++] = buf[0]; continue;}
            else
            {
                if (l==0) l = atof(buf);
                else if (r==0) r = atof(buf);
            }
            if (l&&r)
            {
                switch (ch[--m])
                {
                case '+':
                    l = l+r; r = 0; break;
                case '-':
                    l = l-r; r = 0; break;
                case '*':
                    l = l*r; r = 0; break;
                case '/':
                    l = l/r; r = 0; break;
                default:
                    break;
                }
            }
        }
        printf("%lf\n",l);
    }
    return 0;
}