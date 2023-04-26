#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
    char s[60],*c,*c1;
    int n[128];
    for(int i=0;i<128;i++)n[i]=0;
    n['I']=1;
    n['V']=5;
    n['X']=10;
    n['L']=50;
    n['C']=100;
    n['D']=500;
    n['M']=1000;
    long long int num=0,inside=0;
    int mul=0;
    scanf("%s",s);
    c=s;
    while(*c){
        if(!isalpha(*c)){
            while(!isalpha(*c)&&*c=='('){mul++;c++;}
            while(isalpha(*c)){
                if(n[*c]<n[*(c+1)])inside-=n[*c];
                else if(n[*c]>=n[*(c+1)])inside+=n[*c];
                c++;
            }
            while(!isalpha(*c))c++;
        }
        if(!*c)break;
        if(n[*c]<n[*(c+1)])num-=n[*c];
        else if(n[*c]>=n[*(c+1)])num+=n[*c];
        c++;
    }
    while(mul-->0)inside*=1000;
    num+=inside;
    printf("%lld\n",num);
    return 0;
}