#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int a,b,n;
        scanf("%d %d %d", &a, &b, &n);
        double num = pow(10, b*log10(a));
        char s[10000]={0};
        gcvt(num, 10000, s);
        char *p=strstr(s, ".");
        int index = (p-s)-1;
        if (index<n-1) for (int i=0; i<n-1-index; i++) printf("0");
        for (int i=0; i<n&&index-i>=0; i++) printf("%c", s[index-i]);
        printf("\n");
    }
    return 0;
}