#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int done(int *a, int *b, int res){
    if (a[0] * b[1] + a[1] * b[0] == res) return 1;
    return 0;
}

int main(){
    char s[20]; scanf("%s", s);
    int slen = strlen(s);
    int coef[3] = {0}, flag = 1, digit = 0;
    for (int i = 0; i < slen; i++){
        if (s[i] == 'x'){ 
            if (digit == 0) digit = 1 * flag;
            else digit *= flag;
            if (s[i+1] == '^') coef[2] = digit, i += 2;
            else coef[1] = digit, i++;
            digit = 0;
        }
        else if (s[i] == '+') flag = 1;
        else if (s[i] == '-') flag = -1;
        else if (isdigit(s[i])) digit = digit * 10 + s[i] - '0';
    }
    coef[0] = digit * flag;

    int coefdis[400][2] = {0}, nordis[400][2] = {0}, ccnt = 0, ncnt = 0;

    for (int i = 1; i <= abs(coef[2]); i++)
        if (!(coef[2] % i)) coefdis[ccnt][0] = i, coefdis[ccnt++][1] = coef[2] / i;
    for (int i = 1; i <= abs(coef[0]); i++)
        if (!(coef[0] % i)) nordis[ncnt][0] = i, nordis[ncnt++][1] = coef[0] / i;
    
    if (ncnt == 0){
        if (coef[0] == 0){
            int a1 = 1, a2 = coef[2], c1 = 0, c2 = coef[1];
            if (c1 > c2){
                int t = c1; c1 = c2; c2 = t;
            }
            printf("%d %d %d %d\n", a1, c1, a2, c2);
        }
        else printf("No Answer!\n");
    }
    else{
        int a1, a2, c1, c2, sign = 0;
        for (int i = 0; i != ccnt; i++)
            for (int j = 0; j != ncnt; j++)
                if (done(coefdis[i], nordis[j], coef[1])){
                   a1 = coefdis[i][0]; a2 = nordis[j][0];
                   c1 = coefdis[i][1]; c2 = nordis[j][1];
                   sign = 1; break;
                }
        if (sign){
            if (a1 > a2){
                int t1 = a1, t2 = c1; a1 = a2; a2 = t1; c1 = c2; c2 = t2; 
            }
            else if (a1 == a2){
                if (c1 > c2){
                    int t = c1; c1 = c2; c2 = t;
                }
            }
            printf("%d %d %d %d\n", a1, c1, a2 ,c2);
        }
        else printf("No Answer!\n");
    }
    return 0;
}