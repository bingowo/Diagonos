#include<stdio.h>
#include<string.h>
int main()
{
    int T,j = 0,res = 0 ;
    char ipt[111];
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%s",ipt);
        if('-' == ipt[0])  res = -1;
        else res = ipt[0] - '0';
        if (strlen(ipt) == 1) res *= 3;
        for(j;j < strlen(ipt) - 1;j++){
            res = res*3 + ('-' == ipt[j + 1]?-1:(ipt[j + 1] - '0'));
        }
        printf("case #%d:\n%d\n",i,res);
        j = 0;
    }
    return 0;
}
