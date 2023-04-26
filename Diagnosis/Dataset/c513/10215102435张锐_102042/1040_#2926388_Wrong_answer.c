#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char fa[5],ma[5],son[5];
    scanf("%s",fa);
    scanf("%s",ma);
    scanf("%s",son);
    if(strcmp(fa,"?")==0)
    {
        if(ma[0]=='A'&&son[0]=='A') printf("{A,AB,B,O} %s %s",ma,son);
        else if(ma[0]=='B'&&son[0]=='B') printf("{A,AB,B,O} %s %s",ma,son);
        else if(ma[0]=='A'&&son[0]=='B') printf("{AB,B} %s %s",ma,son);
        else if(ma[0]=='A'&&strlen(son)==2) printf("{AB,B} %s %s",ma,son);
        else if(ma[0]=='A'&&son[0]=='O') printf("{A,B,O} %s %s",ma,son);
        else if(ma[0]=='B'&&strlen(son)==2) printf("{A,AB} %s %s",ma,son);
        else if((ma[0]=='B'||ma[0]=='O')&&son[0]=='O') printf("{A,B,O} %s %s",ma,son);
        else if(strlen(ma)==2&&strlen(son)==2) printf("{A,AB,B} %s %s",ma,son);
        else if(ma[0]=='B'&&son[0]=='A') printf("{A,AB} %s %s",ma,son);
        else if(ma[0]=='O'&&son[0]=='A') printf("{A,AB} %s %s",ma,son);
        else if(ma[0]=='O'&&son[0]=='B')printf("{AB,B} %s %s",ma,son);
        else if(strlen(ma)==2&&(son[0]=='A'||son[0]=='B')) printf("{A,AB,B,O} %s %s",ma,son);
        else printf("impossible %s %s\n",ma,son);
    }
    if(strcmp(ma,"?")==0)
    {
        if(fa[0]=='A'&&son[0]=='A') printf("%s {A,AB,B,O} %s",fa,son);
        else if(fa[0]=='B'&&son[0]=='B') printf("%s {A,AB,B,O} %s",fa,son);
        else if(fa[0]=='A'&&son[0]=='B') printf("%s {AB,B} %s",fa,son);
        else if(fa[0]=='A'&&strlen(son)==2) printf("%s {AB,B} %s",fa,son);
        else if(fa[0]=='A'&&son[0]=='O') printf("%s {A,B,O} %s",fa,son);
        else if(fa[0]=='B'&&strlen(son)==2) printf("%s {A,AB} %s",fa,son);
        else if((fa[0]=='B'||fa[0]=='O')&&son[0]=='O') printf("%s {A,B,O} %s",fa,son);
        else if(strlen(fa)==2&&strlen(son)==2) printf("%s {A,AB,B} %s",fa,son);
        else if(fa[0]=='B'&&son[0]=='A') printf("%s {A,AB} %s",fa,son);
        else if(fa[0]=='O'&&son[0]=='A') printf("%s {A,AB} %s",fa,son);
        else if(fa[0]=='O'&&son[0]=='B')printf("%s {AB,B} %s",fa,son);
        else if(strlen(fa)==2&&(son[0]=='A'||son[0]=='B')) printf("%s {A,AB,B,O} %s",fa,son);
        else printf("%s impossible %s\n",fa,son);
    }
    if(strcmp(son,"?")==0)
    {
        if((fa[0]=='A'||strlen(fa)==2||fa[0]=='B')&&strlen(ma)==2) printf("%s %s {A,AB,B}",fa,ma);
        else if((ma[0]=='A'||strlen(ma)==2||ma[0]=='B')&&strlen(fa)==2) printf("%s %s {A,AB,B}",fa,ma);
        else if((fa[0]=='A'||fa[0]=='O')&&ma[0]=='A') printf("%s %s {A,O}",fa,ma);
        else if((ma[0]=='A'||ma[0]=='O')&&fa[0]=='A') printf("{A,O}");
        else if((fa[0]=='A'&&ma[0]=='B')||(ma[0]=='A'&&fa[0]=='B')) printf("%s %s {A,AB,B,O}",fa,ma);
        else if(fa[0]=='O'&&ma[0]=='O') printf("%s %s {O}",fa,ma);
        else if(fa[0]=='B'&&(ma[0]=='B'||ma[0]=='O')) printf("%s %s {B,O}",fa,ma);
        else if(ma[0]=='B'&&(fa[0]=='B'||fa[0]=='O')) printf("%s %s {B,O}",fa,ma);
        else if((fa[0]=='O'&&strlen(ma)==2)||(ma[0]=='O'&&strlen(fa)==2)) printf("%s %s {A,B}\n",fa,ma);
        else printf("%s %s impossible\n",fa,ma);
    }
    return 0;
}
