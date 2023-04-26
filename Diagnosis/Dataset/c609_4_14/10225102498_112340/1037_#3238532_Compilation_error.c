#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s = (char*)malloc(1000001*sizeof(char));
    char *z = (char*)malloc(1000001*sizeof(char));
    char *max = (char*)malloc(1000001*sizeof(char));
    memset(s, 0, 1000001*sizeof(char));
    memset(z, 0, 1000001*sizeof(char));
    memset(max, 0, 1000001*sizeof(char));
    char* flag;

    scanf("%s", s);
    long long lens = strlen(s);
    long long strlenx, strlenz;
    long long i, k=0;
    for(i=0; i<lens; i++)
    {
        if(strchr(z,s[i]) == NULL)
        {
            z[k] = s[i];
            k++;
        }
        else
        {
            flag = strchr(z,s[i]);
            int t = k - flag;
            i -= t;
            printf("%p\n",flag-z);
            printf("%p\n",&s[0]);
            printf("%d\n",t);
            strlenx = strlen(max);
            strlenz = strlen(z);

            if(strlenx < strlenz)
                strcpy(max,z);

            k = 0;
            memset(z,0,1000001*sizeof(char));
        }
    }
    strlenx = strlen(max);
    if(strlenx != 0)
        printf("%s", max);
    else
        printf("%s", z);

    return 0;
}
