#include<stdio.h>
#include<stdlib.h>

//one, once read one char, remember to judge whether it is EOF or not!
//two, three special occasions
    // "" or ''(special for '\'')
    // //
    // /**/

void echo_quote(char c) // ' or "
{
    char d;putchar(c);
    while((d=getchar())!=c){
        if(d==EOF) return;
        putchar(d);
        if(d=='\\') putchar(getchar()); //for '\''
    }
    putchar(d);
}

void in_comment()   // /*
{
    char c,d;
    c=getchar();
    if(c==EOF)return;
    d=getchar();
    if(d==EOF)return;
    while(!(c=='*'&&d=='/')){
        c=d;d=getchar();
        if(d==EOF)return;
    }
}

void start_comment()    // //
{
    char c;
    while(c!='\n'){
        c=getchar();
        if(c==EOF)return;
    }
    putchar(c);
}

void recomment(char c)
{
    if(c=='/'){
        char d;
        if((d=getchar())=='*')  // /*
            in_comment();
        else if(d=='/')        // //
            start_comment();
        else{
            putchar(c);putchar(d);
        }
    }
    else if(c=='\''||c=='"')   // ' or "
        echo_quote(c);
    else
        putchar(c);
}

int main()
{
    char c;
    while((c=getchar())!=EOF)
        recomment(c);
}