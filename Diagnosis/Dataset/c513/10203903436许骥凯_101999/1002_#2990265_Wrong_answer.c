#include<stdio.h>
#include<string.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int table[128]; memset(table, -1, 128 * sizeof(int));
        char s[60]; scanf("%s", s); int slen = strlen(s);
        int res[60] = {0}, r = 0, nvalue = 0;
        for (int i = 0; i != slen; i++){
            if (table[s[i]] == -1){
                switch (r){
                    case 0: nvalue = 1; break;
                    case 1: nvalue = 0; break;
                    case 2: nvalue = 2; break;
                    default: nvalue++;
                }
                res[i] = table[s[i]] = nvalue; r++;
            }
            else res[i] = table[s[i]];
        }
        if (r < 2) r = 2;
        int resi = 0;
        for (int i = 0; i != slen; i++)
            resi = resi * r + res[i];
        printf("%d\n", resi);
    }
    return 0;
}