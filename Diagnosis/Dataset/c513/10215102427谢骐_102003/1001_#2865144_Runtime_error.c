#include <stdio.h>
char num[36];

void cjz(int a,int jz)
{
    char s[128];
    int n=0;
    while (a) {
        s[n]=num[a%jz];
        a/=jz;
        n++;
    }
    do {
        printf("%c",s[n]);
    } while (n--);
    
}

int main(void)
{
    for (int i=0;i<10;i++)
        num[i]=i+'0';
        
    for (int i=0;i<26;i++)
        num[10+i]=i+'A';
        
    int n;
    scanf("%d",&n);
    
    while (n--) {
        int a,jz;
        scanf("%d%d",a,jz);
        if (a<0) {
            printf("-");
            a=-a;
        }
        cjz(a,jz);
        putchar('\n');
    }
    return 0;
}