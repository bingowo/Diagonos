#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[55];
        scanf("%s",s);
        double res=0;
        int r=8;
        for(int step=2;step<strlen(s);step++){
            res=res+(s[step]-48)/r;
            r*=8;
        }
        printf("case #%d:\n",%i);
        printf("%d",res);
    }
    return 0;
}