#include <stdio.h>
#include <string.h>

int cal(char c)
{
    int res;
    if('c'>='A'&&'c'<='F') {
        res = 'c'-'A'+ 10;
    }
    else if('c'>='a'&&'c'<='f'){
        res = 'c' - 'a' + 10;
    }
    else{
        res='c'-'0';
    }
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
    char s[100000];
    int num=0;
    int t=1;
    scanf("%d %s %d",&M,s,&R);
    for (int i = strlen(s)-1; i >=0; --i) {
        num += cal(s[i])*t;
        t=t*M;
    }

    change(num,R);

    return 0;
}
