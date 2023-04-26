#include<stdio.h>
#include<string.h>

#define max(a, b) ((a) > (b)? (a): (b))

int isDuplicated(char *s){
    if (s[0] == 0 || s[1] == 0) return 0;
    for (int i = 1; s[i]; ++i)
        if (s[i] == s[i - 1]) return 1;
    return 0;
}

int dimish(char *s){
    if (!isDuplicated(s)) return 0;
    char next_s[101]; int nslen = 0;
    int slen = strlen(s);
    for (int i = 0; i < slen; ++i){
        if (i == 0 && s[i + 1] != s[i]) next_s[nslen++] = s[i];
        else if (i == slen - 1 && s[i - 1] != s[i]) next_s[nslen++] = s[i];
        else if (s[i] == s[i - 1] || s[i] == s[i + 1]) continue;
        else next_s[nslen++] = s[i];
    }
    next_s[nslen] = '\0';

    //test
    // for (int i = 0; i != slen; ++i)
    //     printf("%c ", s[i]);
    // printf("\n");
    // for (int i = 0; i != nslen; ++i)
    //     printf("%c ", next_s[i]);
    // printf("\n");

    //end
    return dimish(next_s) + slen - nslen;
}

int produce_insert_value(char *s, char *value){
    int cnt = 0;
    int table[128]; for (int i = 0; i != 128; ++i) table[i] = 0;
    for (int i = 1; s[i]; ++i){
        if(table[s[i]]) continue;
        else{
            value[cnt++] = s[i];
            ++table[s[i]];
        }
    }
    return cnt;
}



int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; ++i){
        printf("case #%d:\n", i);
        char s[101]; scanf("%s", s);
        char value[101];
        int vlen = produce_insert_value(s, value);
        
        // test
        // for (int i = 0; i != vlen; ++i)
        //     printf("%c ", value[i]);
        // printf("\n");
        //end


        int max_dimish_cnt = 0;
        for (int j = 0; j != vlen; ++j){
            char new_s[102];
            for (int k = 0; s[k]; ++k){
                int m = 0;
                int nslen = 0;
                for (; s[m]; ++m)
                    if (m == k) new_s[nslen++] = value[j];
                    else if (m > k) new_s[nslen++] = s[m - 1];
                    else new_s[nslen++] = s[m];
                if (k == m) new_s[nslen++] = value[j];
                else new_s[nslen++] = s[m - 1];
                new_s[nslen] = '\0';
                int res = dimish(new_s); 
                // test
                // printf("%c %d %d\n", value[j], k, res);
                // //end
                max_dimish_cnt = max(max_dimish_cnt, res);
            }
        }
        printf("%d\n", max_dimish_cnt);
    }
    return 0;
}