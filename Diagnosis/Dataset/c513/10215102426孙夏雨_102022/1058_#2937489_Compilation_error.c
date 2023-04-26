#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char c,c1;
    int zifu=0;//是否在字符串内
    int zhushi=0;//是否在注释里
    int fanxie=0;//是否是反斜杠
    while((c=getchar())!=EOF){
        c=getchar();
        if(c=='/'&&zifu==0&&zhushi==0){
            c1=c;
            c=getchar();
            if(c=='/') zhushi=1;
            else if(c=='*') zhushi=2;
            else {
                ungetch(c);
                c=c1;
            }
        }
        if(c=='*'&&zhushi==2&&zifu==0){
            c1=c;
            c=getchar();
            if(c=='/'){
                c=getchar();
                zhushi=0;
            }
            else{
                ungetch(c);
                c=c1;
            }
        }
        if(c=='\\'&&zifu==1&&zhushi==0){
            fanxie=1;
            c1=c;
            c=getchar();
            if(c!='"') fanxie=0;
            ungetch(c);
            c=c1;
        }
        if(c=='"'&&zifu==0&&zhushi==0&&fanxie==0){
            zifu=1;
        }
        else if(c=='"'&&fanxie==0&&zifu==1){
            zifu=0;
        }
        else if(c=='"'&&fanxie==1&&zifu==1){
            fanxie=0;
        }
        if(c=='\n'&&zhushi==1) zhushi=0;
        if(zifu==1) printf("%c",c);
        else if(zhushi==0) printf("%c",c);
    }
    return 0;
}
