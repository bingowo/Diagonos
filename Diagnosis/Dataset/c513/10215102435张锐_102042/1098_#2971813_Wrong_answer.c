#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++)
    {
        char s[106];
        scanf("%s",s);
        int len=strlen(s);
        int R=0,B=0,Y=0,G=0;
        int aa=0,bb=0,cc=0,dd=0;
        char a,b,c,d;
        for(int i=0;i<len;i++)
        {
            if(i%4==0&&s[i]!='!') a=s[i];
            else if(i%4==1&&s[i]!='!') b=s[i];
            else if(i%4==2&&s[i]!='!') c=s[i];
            else if(i%4==3&&s[i]!='!') d=s[i];
        }
        for(int i=0;i<len;i++)
        {
            if(i%4==0&&s[i]=='!') aa++;
            if(i%4==1&&s[i]=='!') bb++;
            if(i%4==2&&s[i]=='!') cc++;
            if(i%4==3&&s[i]=='!') dd++;
        }
        if(a=='R') R=aa;
        if(a=='B') B=aa;
        if(a=='Y') Y=aa;
        if(a=='G') G=aa;//A
        if(b=='R') R=bb;
        if(b=='B') B=bb;
        if(b=='Y') Y=bb;
        if(b=='G') G=bb;
        if(c=='R') R=cc;
        if(c=='B') B=cc;
        if(c=='Y') Y=cc;
        if(c=='G') G=cc;
        if(d=='R') R=dd;
        if(d=='B') B=dd;
        if(d=='Y') Y=dd;
        if(d=='G') G=dd;
        printf("case #%d:\n",j);
        printf("%d %d %d %d\n",R,B,Y,G);
    }
    return 0;
}
