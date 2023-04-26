#include<stdio.h>
#include<string.h>
#define N 55

int solve(char* s)
{
    int n=strlen(s);
    int max=0,cnt=0;
    for(int i=0;i<n-1;++i){
        if(s[i]!=s[i+1])cnt++;
        else{
            cnt++;
            max=max>cnt?max:cnt;
            cnt=0;
        }
    }
    if(s[n-2]!=s[n-1])cnt++;
    max=max>cnt?max:cnt;
    return max;
}

int main()
{
    char s[N];
    scanf("%s",s);
    printf("%d\n",solve(s));
    return 0;
}
