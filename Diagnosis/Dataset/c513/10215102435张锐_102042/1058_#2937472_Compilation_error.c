#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char temp[1000]={'0'};
    char c;
    int a=0,b=0,s=0;int i=0;
    while((c=getchar())!=EOF)
    {
        if(c=='"'&&b==0&&a==0) a++;
        else if(c=='"'&&b==0&&a>0) a--;
        else if(b>0) b--;
        else if(c=='\\') b++;
        else if(c=='/'&&a==0&&s==0) s=1;
        else if(c=='*'&&s==1) s=2;
        else if(c=='*'&&s==2) s=4;
        else if(c=='\n'&&s==4) s=2;
        else if(c=='/'&&s==4) {s=0;temp[1000]={'0'};continue;}
        else if(c=='/'&&s==1) s=3;
        else if(c=='\n'&&s==3) {s=0;temp[1000]={'0'};i=0;}
        else if(s==1) {s=0;printf("/");}
        if(s==0) {printf("%c",c);}
        else {temp[i]=c;i++;}
    }
    return 0;
}
