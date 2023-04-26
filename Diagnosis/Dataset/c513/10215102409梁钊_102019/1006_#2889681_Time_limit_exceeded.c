#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i!=T;i++){
        char s[20] = {'0'};
        scanf("%s",&s);
        int sum = 0 , r = 1;
        for(int j=strlen(s)-1;j!=-1;j++){
            int a;
            if(s[j]=='1') a=1;
            else if(s[j]=='0') a=0;
            else a=-1;
            sum += r * a ;
            r *= 3 ;
        }
        printf("case #%d:\n%d\n",i,sum);
    }
}