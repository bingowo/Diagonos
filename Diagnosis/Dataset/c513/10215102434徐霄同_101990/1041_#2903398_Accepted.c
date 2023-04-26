#include <stdio.h>
#include <string.h>

int main()
{
    char s[51];
    int x,m,l,i,j;
    scanf("%s",s);
    l=strlen(s);
    m=0;
    for(i=0;i<l;i++){
        x=1;
        j=i+1;
        while(s[j]!=s[j-1] && j<l){
            x++;
            j++;
        }
        if(x>m)
            m=x;
    }
    printf("%d\n",m);
    return 0;
}