#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *p1, const void *p2){
    return *(char*)p1 - *(char*)p2;
}

int main(void)
{
    char pro[500000];
    char a;
    int state = 0;
    int cnt = 0;

    while((a = getchar()) != EOF){
        switch(state){
            case 0:
                if(a == '"'){
                    state = 1;
                    pro[cnt++] = a;
                    break;
                }

                else if(a == '/'){
                    a = getchar();
                    if(a == '*'){
                        while(getchar() != '*') continue;
                        getchar();
                        break;
                    }
                    else{
                        while(getchar() != '\n') continue;
                        pro[cnt++] = '\n';
                        break;
                    }
                }

                else if(a == '\''){
                    state = 2;
                    pro[cnt++] = a;
                    break;
                }

                else{
                    pro[cnt++] = a;
                    break;
                }

            case 1:
                if(a == '"') state = 0;
                pro[cnt++] = a;
                break;

            case 2:
                if(a == '\'') state = 0;
                pro[cnt++] = a;
                break;
        }
    }

    printf("%s",pro);

    return 0;
}