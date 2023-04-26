#include<stdio.h>
#include<math.h>
int main(){
    int table[123];
    table['0'] = 0; table['1'] = 1; table['2'] = -1;
    char tnum[30];
    char c;
    double res = 0;
    int mts = 0, count = 0, pt = 0, fac = 1; 
    while ((c = getchar()) != '\n'){
        if (c == '.') {mts = count; continue;}
        if (mts) {pt = pt * 3 + table[c]; fac *= 3;}
        res = res * 3 + table[c];
        count++;
    }
    if (mts){
        for (int i = 0; i != count - mts; i++)
            res /= 3;
        if (pt * (long long int)res < 0) pt = fac - abs(pt);
        else if (pt * (long long int)res > 0) pt = abs(pt);  
        if ((int)res == 0) printf("%d %d", pt, fac);
        else printf("%lld %d %d\n", (long long int)res, pt, fac);
    }   
    else printf("%lld\n", (long long int)res);
    return 0;
}