#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c='\0';
    char s[1001];
    scanf("%s",s);
    strupr(s);
    c=s[0];
    int len=strlen(s);
    for(int i=1;i<len;i++){
        if(s[i]>c){
            s[0]=s[i];
            s[i]=c;
        }
        else if(s[i]==c){
            for(int j=i;j>1;j--) s[j]=s[j-1];
            s[1]=c;
        }
        c=s[0];
    }
    printf("%s",s);
    return 0;
}
