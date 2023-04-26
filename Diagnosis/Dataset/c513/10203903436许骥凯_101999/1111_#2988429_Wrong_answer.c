#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    char *func[20], s[100]; int len = 0;
    while(~scanf("%s", s)){
        int slen = strlen(s);
        func[len] = (char*)malloc(slen*sizeof(char));
        strcpy(func[len++], s);
    }
    for (int i = 0; i != len; i++){
        char graph[41][41];
        for (int j = 0; j != 41; j++)
            for (int k = 0; k != 41; k++)
                graph[j][k] = '.';
        for (int j = 0; j != 41; j++) graph[20][j] = '-';
        for (int j = 0; j != 41; j++) graph[j][20] = '|';
        graph[20][40] = '>';
        graph[40][20] = '^';
        graph[20][20] = '+';
        int coef[4] = {0}, temp = 0, flag = 0, idx = 0;
        for (int j = 5; j < strlen(func[i]); j++){
            if (isdigit(func[i][j])){
                temp = temp * 10 + func[i][j] - '0';
                if (j == strlen(func[i]) - 1) coef[0] = flag? -temp: temp;
            }
            else if (func[i][j] == '-') flag = 1;
            else if (func[i][j] == '+') flag = 0;
            else if (func[i][j] == 'x'){
                if (j == strlen(func[i]) - 1 || func[i][j+1] != '^'){
                    if (temp) coef[1] = flag? -temp: temp;
                    else coef[1] = flag? -1: 1;               
                }
                else{
                    j += 2;
                    idx = func[i][j] - '0';
                    if (temp) coef[idx] = flag? -temp: temp;
                    else coef[idx] = flag? -1: 1;
                    temp = 0;
                }
            }  
        }   
        for (int j = 0; j != 4; j++) printf("%d ", coef[j]);
        printf("\n");
        for (int j = 0; j != 41; j++){
            int y = 0;
            int x = j - 20;
            y = coef[3] * x * x * x + coef[2] * x * x + coef[1] * x + coef[0];
            if (y <= 20 && y >= -20)
                graph[y+20][j] = '*';
        }
        for (int j = 40; j >= 0; j--){
            for (int k = 0; k <= 40; k++)
                printf("%c", graph[j][k]);
            printf("\n");
        }
        if (i != len - 1) printf("\n");
    }
    for (int i = 0; i != len; i++) free(func[i]);
    return 0;
}