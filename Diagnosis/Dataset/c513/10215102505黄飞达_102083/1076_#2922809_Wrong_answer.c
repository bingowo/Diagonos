#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[105] = {0};
        gets(s);
        int table[128] = {0};
        char shun[4][2] = {0};
        shun[0][0] = s[0], shun[1][0] = s[1];
        table[s[0]]++;
        table[s[1]]++;
        table[s[2]]++;
        
        if (table['{']==0) shun[2][0] = '{';
        else if (table['[']==0) shun[2][0] = '[';
        else if (table['(']==0) shun[2][0] = '(';
        else shun[2][0] = s[2];
        for (int i = 0; i < 3; i++){
            if (shun[i][0]=='{') shun[i][1] = '}';
            else if (shun[i][0]=='[') shun[i][1] = ']';
            else if (shun[i][0]=='(') shun[i][1] = ')';
        }

        int slen = strlen(s), flag = 0;
        for (int i = 3; i < slen; i++) {
            table[s[i]]++;
            if (!(table[shun[0][0]]-table[shun[0][1]]>=table[shun[1][0]]-table[shun[1][1]]&&table[shun[1][0]]-table[shun[1][1]]>=table[shun[2][0]]-table[shun[2][1]])){
                flag = 1;
                printf("No\n");
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}
// {[(())]}