#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
//快排有风险，使用需谨慎
char table[256];
int main()
{
    long long n;scanf("%lld",&n);
    getchar();
    for(int m=0;m<n;m++){
        for(int i=0;i<256;i++)table[i]=0;
        char str[205];
        fgets(str,205,stdin);
        int len=strlen(str)-1;
        for(int i=0;i<len;i++){
            if(str[i]>='A' && str[i]<='Z'){
                table[str[i]]++;
            }
        }
        int p='A';
        for(int i=0;i<len;i++){
            if(str[i]>='A' &&str[i]<='Z'){
                while(table[p]==0)p++;
                str[i]=p;
                table[p]--;
            }
        }
        printf("case #%d:\n",m);
        printf("%s",str);
    }
}
