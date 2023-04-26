#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++)
    {
        int res[10000], rlen = 1, table[101][3] = {0};
        printf("case #%d:\n", i);
        int s, m;
        scanf("%d%d", &s, &m);
        int flag = -1;
        while(s != 0){
            if(table[s][0]){
                flag = s;
                table[s][2] = rlen;
                break;
            }
            else{
                table[s][0] = 1;
                table[s][1] = rlen;
            }
            res[rlen++] = (s * 10) / m;
            s = (s * 10) % m;
        }
        printf("0.");
        for (int j = 1; j != rlen; j++)
            printf("%d", res[j]);
        printf("\n");
        if (flag != -1) printf("%d-%d\n", table[flag][1], table[flag][2] - 1);
    }
}