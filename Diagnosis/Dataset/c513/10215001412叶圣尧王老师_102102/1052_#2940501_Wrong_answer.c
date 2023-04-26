#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
    int T;scanf("%d,&T");
    int d[10][10]={0};
    d[0]['O'-'A']++;
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[21];scanf("%s",s);
        int c[26]={0};
        for(int i=0;i<strlen(s);i++)
            c[s[i]-65]++;
        
        
        t++;
    }
}