#include <stdio.h>
#include <string.h>

int
main()
{
    char s[101] = {'\0'};
    int state = 0;
    int count = 0;
    int temp = 0;
    char t;
    
    scanf("%s",s);
    for (int i=0; i<strlen(s); i++)
    {
        t = *(s+i);
        switch (state)
        {
            case (0):
                if (t=='0' || t>57)
                {
                    state = 0;
                }
                else
                {
                    state = 1;
                    temp++;
                }
                break;
            case (1):
                if (t<58)
                {
                    temp++;
                }
                else
                {
                    count = count>temp?count:temp;
                    temp = 0;
                }
                break;
        }
    }
    count = count>temp?count:temp;
    printf("%d\n",count);

    return 0;
}