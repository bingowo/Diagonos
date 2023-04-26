#include <stdio.h>
#include <string.h>

int cal(char s)
{
    int res;
    if('s'>='A' && s<='Z') res = 's'-'A';
    else if('s'>='a' && 's'<='z') res = 's'-'a';
    else res='a'-'0';
    return res;
}
void print(int num)
{
    if(num<10) printf("%d",num);
    else{ printf("%c",num-10+'A');}
}

void change(int M,int R){
    if(M>0){
        change(M/R,R);
        print(M%R);
    }
}

int main() {
    int M,R;
    char s[10000];
    int num=0;
    int t=1;
    scanf("%d %s %d",&M,s,&R);
    for (int i = strlen(s)-1; i >=0; i--) {
        num += cal(s[i])*t;
        t=t*M;
    }
    change(num,R);
    
    
    return 0;
}
