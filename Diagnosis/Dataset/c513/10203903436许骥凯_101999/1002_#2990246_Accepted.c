#include<stdio.h>
#include<string.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int table[128]; memset(table, -1, 128 * sizeof(int));
        char s[60]; scanf("%s", s); int slen = strlen(s);
        int res[60] = {0}, r = 0, nv = 2;
        for (int i = 0; i != slen; i++){
            if (table[s[i]] == -1){
                if (i == 0){
                    res[i] = 1; table[s[i]] = 1; r++;
                }
                else if (r == 1){
                    res[i] = 0; table[s[i]] = 0; r++;
                }
                else if (r == 2){
                    res[i] = 2; table[s[i]] = 2; r++;
                }
                else{
                    res[i] = ++nv; table[s[i]] = res[i]; r++;
                }
            }
            else res[i] = table[s[i]];
        }
        if (r < 2) r = 2;
        long long  resi = 0;
        for (int i = 0; i != slen; i++)
            resi = resi * r + res[i];
        printf("%lld\n", resi);
    }
    return 0;
}