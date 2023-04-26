#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

ll x,y;

int Find(char* s,char c){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c)
            return i;
    return -1;
}

void I2C(char* s){
    int i=0,c=1;

    if(s[i]=='-'){
        c=-1;
        i++;
    }
    while(s[i]!='-'&&s[i]!='+'){//实数
        if(s[i]=='i'){//虚数
            if(x==0) x=1;
            y=c*x;
            x=0;
            return;
        }
        if(s[i]=='\0'){//没虚数
            x*=c;
            y=0;
            return;
        }

        x=x*10+s[i]-'0';
        i++;
    }
    x*=c;
    c=1;
    if(s[i]=='-') c=-1;
    i++;
    while(s[i]!='i'){//虚数
        y=y*10+s[i]-'0';
        i++;
    }
    if(y==0) y=1;
    y*=c;
}

void Change(){
    static ll x0,y0;
    x0=x,y0=y;
    y=-(x0+y0)/2;
    x=(y0-x0)/2;
}

void Fun(){
    if(x==0&&y==0) return;

    if((x+y)%2){
        x-=1;
        Change();
        Fun();
        printf("1");
    }
    else{
        Change();
        Fun();
        printf("0");
    }
}

int main(){
    char s[50];
    scanf("%s",s);
    I2C(s);
    //printf("%lld %lld\n",x,y);
    if(x==0&&y==0){
        printf("0\n");
    }
    else{
        Fun();
        printf("\n");
    }


    return 0;
}
