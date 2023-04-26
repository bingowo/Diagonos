#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        char eightnum[51], tennum[155];
        scanf("%s", eightnum);

        int cnt = 0, len = strlen(eightnum) -1;
        int digit, temp, j;
        for(; len != 1; --len)
        {
            digit = eightnum[len] - '0';
            j = 0;
            do{
                if(j < cnt)
                    temp = digit * 10 + tennum[j] - '0';
                else
                    temp = digit * 10;
                tennum[j++] = temp / 8 + '0';
                digit = temp % 8;
            }while(digit != 0 || j < cnt);
            cnt = j;
        }
        tennum[cnt] = '\0';


        printf("case #%d:\n", i);
        printf("0.");
        for(int j = 0; j < cnt; j++)
            printf("%c", tennum[j]);
        printf("\n");
    }
    return 0;
}
