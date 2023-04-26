#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[5];
    int digit;
} VEC;

char findd(char* s)
{
    if (strchr(s,'R')==0 && strchr(s,'B') && strchr(s,'Y') && strchr(s,'G'))
        return 'R';
    if (strchr(s,'R') && strchr(s,'B')==0 && strchr(s,'Y') && strchr(s,'G'))
        return 'B';
    if (strchr(s,'R') && strchr(s,'B') && strchr(s,'Y')==0 && strchr(s,'G'))
        return 'Y';
    if (strchr(s,'R') && strchr(s,'B') && strchr(s,'Y') && strchr(s,'G')==0)
        return 'G';
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[120]={0};
        int RBYG[150]={0};
        scanf("%s",s);
        int len=strlen(s);
        int abc[150]={0};
        while (strchr(s,'!'))
        {
            int j;
             VEC* arr=(VEC*)malloc((len-3)*sizeof(VEC));
            for (j=0;j<len-3;j++)
            {
                arr[j].digit=j;
                if (abc[j]==0)
                    for (int k=0;k<4;k++)
                        arr[j].s[k]=s[j+k];
            }
            for (j=0;j<len-3;j++)
            {
                int cnt=0;
                if (abc[j]==0)
                    for (int k=0;k<4;k++)
                        if (arr[j].s[k]=='!')
                            cnt++;
                if (cnt==1)
                {
                    s[arr[j].digit+strchr(arr[j].s,'!')-arr[j].s]=findd(arr[j].s);
                    RBYG[findd(arr[j].s)]++;
                    abc[j]=1;
                    break;
                }
            }
            free(arr);
        }
        printf("%d %d %d %d\n",RBYG['R'],RBYG['B'],RBYG['Y'],RBYG['G']);


    }
    return 0;
}
