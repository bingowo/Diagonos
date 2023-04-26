#include <stdio.h>

int gcd(int a, int b){
    if (!(a % b)) return b;
    return gcd(b, a % b);
}
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
            int mss = s / gcd(m, s), msm = m / gcd(m, s);
            if(table[mss][0]){
                flag = mss;
                table[mss][2] = rlen;
                break;
            }
            else{
                table[mss][0] = 1;
                table[mss][1] = rlen;
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