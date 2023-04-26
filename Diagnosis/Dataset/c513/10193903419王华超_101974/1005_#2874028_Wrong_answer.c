#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    double sum;
}qt;
qt qts[10];
int main()
{
    int t,index=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[50];
        scanf("%s",s);
        double n=-1;
        for(int j=2;j<strlen(s);j++){
            qts[index].sum+=(s[j]-'0')*pow(8,n);
            n--;
        }
        index++;
    }
    for(int i=0;i<t;i++){
        printf("case #%d:\n%.20g\n",i,qts[i].sum);
    }
    return 0;
}