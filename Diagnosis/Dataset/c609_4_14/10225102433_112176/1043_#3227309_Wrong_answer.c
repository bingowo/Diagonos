#include <stdio.h>
#include <string.h>
#define N 110

int f[N];
int dep = 1;
int n;

int trans(char c)
{
    if(c == '{') return 3;
    else if(c == '[') return 2;
    else if(c == '(') return 1;
    else if(c == '}') return -3;
    else if(c == ']') return -2;
    else return -1;
}

int main()
{
    scanf("%d",&n);
    char ch = getchar();
    while(n--)
    {
        int flag = 1;
        char c;
        c = getchar();
        f[dep] = trans(c);
        while(1)
        {
            c = getchar();
            if(c == '\n') break;
            int res = trans(c);
            if (res > 0){
                if(dep == 0){
                    f[++dep] = res;
                }
                else{
                    if((res == f[dep]-1) || ((res == 3) && (f[dep] == 1))){
                        f[++dep] = res;
                    }
                    else{
                        flag = 0;
                        while(1)
                        {
                            char p;
                            p = getchar();
                            if(p == '\n') break;
                        }
                        break;
                    }
                }
            }
            else{
                if(res == -f[dep]){
                    f[dep] = 0;
                    dep--;
                }
                else{
                    flag = 0;
                    while(1)
                    {
                        char p;
                        p = getchar();
                        if(p == '\n') break;
                    }
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
        dep = 1;
        memset(f,0,sizeof(f));
    }
    return 0;
}