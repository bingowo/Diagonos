#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[101];
    int i,n,m,l;
    scanf("%s",s);
    l=strlen(s);
    i=0;
    m=0;
    while(i<l){
        if(isalpha(s[i])||s[i]=='0')
            i++;
        else{
            n=1;
            while(i+1<l&&isdigit(s[i+1])){
                i++;
                n++;
            }
            if(n>m)
                m=n;
            i++;
        }
    }
    printf("%d\n",m);
    return 0;
}
