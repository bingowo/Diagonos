#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 10100

typedef struct{
    char s[40];
    int L;
}node;

int LEN;
int ans;
char s[30000];

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int M;scanf("%d",&M);
        printf("case #%d:\n",i);
        node *ch = (node*)malloc(N*sizeof*ch);
        char c = getchar();
        gets(s);
        int check = 0,cnt = 0;
        for(int i = 0;i < strlen(s);i++){
            if(isspace(s[i])) {
                if(isspace(s[i+1])) continue;
                else if(ans == 0 && check == 0) {check = 1;continue;}
                ch[ans].s[cnt] = '\0';
                ch[ans].L = strlen(ch[ans].s);
                ans++;
                cnt = 0;
            }
            else{
                ch[ans].s[cnt++] = s[i];
                check = 1;
            }
        }
        ch[ans].s[cnt] = '\0';
        ch[ans].L = strlen(ch[ans].s);
        ans++;
        for(int j = 0;j < ans;j++){
            int sum = 0;
            for(int k = j;k < ans;k++){
                sum += ch[k].L;
                if(sum+k-j > M){       //判断一行能容纳多少字符串并且开始输出
                    sum -= ch[k].L;
                    k--;
                    int numspace = M-sum;            //空格的数量
                    int numdis = k-j;
                    if(numspace % numdis != 0){
                        int small = numspace/numdis;
                        int numbig = numspace%numdis;
                        int numsmall = numdis-numbig;
                        printf("%s",ch[j].s);
                        for(int p = j+1;p <= k;p++){
                            int key = p-j;
                            if(key <= numsmall){
                                for(int u = 0;u < small;u++) printf(" ");
                            }
                            else{
                                for(int u = 0;u < small+1;u++) printf(" ");
                            }
                            printf("%s",ch[p].s);
                        }
                    }
                    else{
                        int time = numspace/numdis;
                        printf("%s",ch[j].s);
                        for(int p = j+1;p <= k;p++){
                            for(int u = 0;u < time;u++) printf(" ");
                            printf("%s",ch[p].s);
                        }
                    }
                    j = k;                           //下一次从这里开始判断
                    printf("\n");
                    break;
                }
                else{
                    if(k == ans-1){
                        for(int p = j;p < ans;p++){
                            printf("%s%c",ch[p].s,p == ans-1 ? '\n' : ' ');
                        }
                        j = ans-1;
                    }
                    else
                        continue;
                }
            }
        }
        free(ch);
        ans = 0;
        memset(s,'\0',sizeof(s));
        LEN = 0;
    }
    return 0;
}