#include <stdio.h>
#include <string.h>
int main()
{
    int n,r,i,x;
    char s[30];
    scanf("%d%d",&n,&r);
    memset(s,0,sizeof(s));
    i=0;
    while(n!=0){
        if(n%r>=0){
            x=n%r;
            if(x<10)
                s[i]=x+'0';
            else
                s[i]=x-10+'A';
            i++;
            n=n/r;
        }
        else{
            x=n-(n/r+1)*r;
            if(x<10)
                s[i]=x+'0';
            else
                s[i]=x-10+'A';
            i++;
            n=n/r+1;
        }
    }
    for(i=strlen(s)-1;i>=0;i--)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}
