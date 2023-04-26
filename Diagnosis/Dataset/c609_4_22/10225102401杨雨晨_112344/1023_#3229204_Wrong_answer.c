#include <stdio.h>
#include <string.h>

#define N 10

char *Haab[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax"
         , "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char *Tzolkin[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk"
         , "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
char month[N];

int main(void)
{
    int n, day, year, i;
    scanf("%d", &n);
    printf("%d\n", n);
    while(n--) {
        scanf("%d. %s %d", &day, month, &year);     /* 读入Haab历的年月日 */
        for(i = 0; i < 19; i++)
            if(!strcmp(month, Haab[i]))
                break;
        int days = year * 365 + i * 20 + day;
        printf("%d %s %d\n", 1 + days % 13, Tzolkin[days % 20], days / 260);
    }

    return 0;
}
