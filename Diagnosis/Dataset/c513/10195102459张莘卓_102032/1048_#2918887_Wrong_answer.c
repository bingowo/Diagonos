#include <stdio.h>
#include <string.h>

void setK(char *s, int a[]) {
    int i = 0;
    while(s[i]) {
        int flag = 1, k = 0;
        if(i) flag = s[i++] == '+' ? 1 : -1;
        else{
            if(i == '-') flag = -1;
            if(i=='+' || i=='-') ++i;
        }
        if(s[i] == 'x') k = flag;
        else{
            for(;s[i] && s[i]!='x'; ++i)
                k = k*10 + s[i] - '0';
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
}

int main()
{
    char s1[101], s2[101];
    while(scanf("%s%s",s1,s2) != EOF){
        int a[50] = {0}, b[50] = {0}, c[99] = {0};
        setK(s1, a);
        setK(s2, b);
        for(int i=0; i<50; ++i){
            if(a[i] == 0) continue;
            for(int j=0; j<50; ++j) {
                if(b[j] == 0) continue;
                c[i+j] += a[i] * b[j];
            }
        }
        int k = 0;
        for(int i=0; i<99; ++i)
            if(c[i]) c[k++] = c[i];
        for(int i=k-1; i>=0; --i)
            printf("%d%s",c[i],i?" ":"\n");
    }
    return 0;
}
