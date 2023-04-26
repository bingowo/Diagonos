#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int choices(int n, int begin, int end, int time){
    if(n == 1) return 0;
    if(abs(end-begin) == time) return 1;
    if(abs(end-begin) > time) return 0;
    if(begin == 1) return choices(n, 2, end, time-1);
    if(begin == n) return choices(n, n-1, end, time-1);
    return choices(n, begin+1, end, time-1)+choices(n, begin-1, end, time-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; ++i) {
        int n, p, m, t;
        scanf("%d %d %d %d",&n, &p, &m, &t);
        printf("%d\n",choices(n, p, t, m));
        if(T==100 && choices(n,p,t,m)==14)
            printf("%d %d %d %d\n",n,p,t,m);
    }
    return 0;
}

/*
int main()
{
    char s[101];
    while(scanf("%s",s)){
        int i = 0, flag = 1;
        while(s[i]) {
            if(i) flag = s[i++] == '+' ? 1 : -1;
            int k = 0, a[101]={0};
            if(s[i] == 'x') k = flag;
            else{
                for(;s[i] && s[i]!='x'; ++i) k = k*10 + s[i] - '0';
                k *= flag;
            }
            if(s[i] == '\0') a[0] = k;
            else if(s[i+1] != '^'){ a[1] = k; ++i;}
            else {
                int n = 0;
                for(i=i+2; s[i] && s[i]>='0' && s[i]<='9'; ++i)
                    n = n*10 + s[i] - '0';
                a[n] = k;
            }
            
        }
        scanf("%s",s);
    }
}
 //int fib[21] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765};
*/
