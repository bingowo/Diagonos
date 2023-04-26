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
        int res[10000], rlen = 1;
        printf("case #%d:\n", i);
        int s, m;
        scanf("%d%d", &s, &m);
        int flag = 0, scnt = 0, ocnt = 0;
        while(s != 0){
            int mss = s / gcd(m, s), msm = m / gcd(m, s);
            if (mss == 1 && msm == 3 || mss == 2 && msm == 3 || msm == 9){
                ocnt++;
                if (ocnt == 2) {flag = 1; break;}
            }
            else if (msm == 7){
                scnt++;
                if (scnt == 7) {flag = 6; break;}
            }
            res[rlen++] = (s * 10) / m;
            s = (s * 10) % m;
        }
        printf("0.");
        for (int j = 1; j != rlen; j++)
            printf("%d", res[j]);
        printf("\n");
        if (flag) printf("%d-%d\n", rlen - 1, rlen + flag - 2);
    }
}