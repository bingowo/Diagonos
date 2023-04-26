#include <stdio.h>

int main()
{
    int n,m,cnt,cp=0;
    char s[10000];
    scanf("%d%d",&n,&m);
    do{
        cnt=n%m;
        n/=m;
        if(cnt<0){
            cnt-=m;
            n++;
        }
        if(cnt>=10)s[cp++]=cnt-10+'A';
        else s[cp++]=cnt+'0';
    }while(n!=0);
    while(cp--){
        printf("%c",s[cp]);
    }
    printf("\n");
    return 0;
}
