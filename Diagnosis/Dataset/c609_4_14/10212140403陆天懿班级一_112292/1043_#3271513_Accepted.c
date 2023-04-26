#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
typedef long long ll;
typedef unsigned long long ull;
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

#define N 105
char stack[N],str[N];
int tp=0;

int Match(char l, char r){
    return l=='('&&r==')'
            ||l=='['&&r==']'
            ||l=='{'&&r=='}';
}

int Ele(char out,char in){
    return out=='{'&&in=='['
            ||out=='['&&in=='('
            ||out=='('&&in=='{'
            ||out=='\0';
}

void Push(char c){
    stack[tp++]=c;
}

char Pop(){
    tp--;
    return stack[tp];
}

char Top(){
    return stack[tp-1];
}

char Clear(){tp=0;}
int Size(){return tp;}
int IsEmpty(){return tp;}

int IsLeft(char c){return c=='('||c=='['||c=='{';}

int Check(){
    Clear();
    Push('\0');
    for(int i=0;str[i]!='\0';i++){
        if(IsLeft(str[i])){
            if(!Ele(Top(),str[i])) return 0;
            Push(str[i]);
        }
        else{
            if(!Match(Top(),str[i])) return 0;
            Pop();
        }
    }
    return Size()==1;
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        scanf("%s",str);
        printf("%s\n",(Check()?"Yes":"No"));
    }

    return 0;
}
