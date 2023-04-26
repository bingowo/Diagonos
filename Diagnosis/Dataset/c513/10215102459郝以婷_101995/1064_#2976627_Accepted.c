#include <stdio.h>
#include <stdlib.h>

double expr()
{
    char s[101];
    scanf("%s",s);
    //printf("%s",s);
    if(strcmp(s,"-")==0)
        return expr()-expr();
    else if(strcmp(s,"+")==0)
        return expr()+expr();
    else if(strcmp(s,"*")==0)
        return expr()*expr();
    else if(strcmp(s,"/")==0)
        return expr()/expr();
    else
        return atof(s);
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%f",expr());
        printf("\n");
    }
    return 0;
}
