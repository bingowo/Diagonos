#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int a,int b)
{
    if(a<b)
    {
        int c=a;
        a=b;
        b=c;
    }
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int pop_one(char x)
{
    int n=x;

    int answer=0;
    for(int i=0;i<8;i++)
    {
        answer+=(n&1);
        n>>=1;
    }
    return answer;
}
int main()
{
    //printf("%d",pop_one('F'));
    int n;
    scanf("%d",&n);
    getchar();
    int answer=0;
    char s[130];
    for(int i=0;i<n;i++){
            answer=0;
            gets(s);
    int lens=strlen(s);
    for(int j=0;j<lens;j++)
        answer+=pop_one(s[j]);
    printf("%d/%d\n",answer/f(8*lens,answer),8*lens/f(8*lens,answer));
    }
    return 0;
}