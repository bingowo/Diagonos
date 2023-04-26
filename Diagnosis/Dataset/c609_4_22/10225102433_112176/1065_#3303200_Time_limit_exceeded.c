#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int sig;                 //sig为0说明是数字为1则是运算符
    double value;            //对于数字既是数字符号的话1，2，3，4代表加减乘除
}node;

int trans(char c)
{
    if(c == '+') return 1;
    else if(c == '-') return 2;
    else if(c == '*') return 3;
    else return 4;
}

int Head;
double ans;

double solve(double x,double y,double k)
{
    if(k == 1) return x+y;
    else if(k == 2) return x-y;
    else if(k == 3) return x*y;
    else return x/y;
}

void RC(node *arr)
{
    if(Head == 3) {
        ans = solve(arr[1].value,arr[2].value,arr[0].value);
        return;
    }
    for(int i = Head-1;i >= 0;i--){
        if(arr[i].sig == 0 && arr[i-1].sig == 0 && arr[i-2].sig == 1){
            arr[i-2].sig  = 0;
            arr[i-2].value = solve(arr[i-1].value,arr[i].value,arr[i-2].value);
            for(int j = Head-1;j > i;j--){
                arr[j-2] = arr[j];
            }
            Head -= 2;
            break;
        }
    }
    RC(arr);
}

int main()
{
//    freopen("C:\\Users\\HP\\CLionProjects\\ecnuoj\\CODING\\hh","r",stdin);
    int T;scanf("%d",&T);
    for(int i = 0;i < T;i++){
        node ch[101];
        printf("case #%d:\n",i);
        Head = 0;
        ans = 0;
        char s[10] = {0};
        while((scanf("%s",s) != EOF)){
            if(strlen(s) == 1){
                char res = s[0];
                if(isdigit(res)){
                    double val;
                    sscanf(s,"%lf",&val);
                    ch[Head].sig = 0;
                    ch[Head].value = val;
                    Head++;
                }
                else{
                    ch[Head].sig = 1;
                    ch[Head].value = trans(res);
                    Head++;
                }
            }
            else{
                double val;
                sscanf(s,"%lf",&val);
                ch[Head].sig = 0;
                ch[Head].value = val;
                Head++;
            }
        }
        RC(ch);
        printf("%f\n",ans);
//        free(ch);
    }
    return 0;
}