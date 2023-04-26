#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    int i = 0;
    for(i = 0; i<T; i++)
    {
        char s[21] = {0};
        int key[10] = {0};
        int alphabet[26] = {0};
        scanf("%s", s);
        int len = strlen(s);
        for(int j = 0; j<len; j++)
        {
            alphabet[s[j]-'A']++;
        }

        key[0] = alphabet['Z'-'A'];
        key[6] = alphabet['X'-'A'];
        key[4] = alphabet['U'-'A'];
        key[2] = alphabet['W'-'A'];
        key[8] = alphabet['G'-'A'];
        key[5] = alphabet['F'-'A']-key[4];
        key[3] = alphabet['R'-'A']-key[4]-key[0];
        key[1] = alphabet['O'-'A']-key[0]-key[2]-key[4];
        key[7] = alphabet['V'-'A']-key[5];
        key[9] = alphabet['I'-'A']-key[5]-key[6]-key[8];

        for(int j = 0; j<10; j++)
        {
            for(int p = 0; p<key[j]; p++)
            {
                printf("%d", j);
            }
        }
        memset(key, 0, 40);
        memset(alphabet, 0, sizeof(alphabet));
        printf("\n");
    }
    return 0;
}
