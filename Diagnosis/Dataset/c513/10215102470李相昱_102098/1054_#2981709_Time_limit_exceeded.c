#include <stdio.h>
#include <string.h>
typedef struct {
    char str[35];
    int len;
}Str;
int main() {
    int T;
    scanf("%d",&T);
    Str a[1001];
    for(int i=0;i<T;i++){
        int M;
        scanf("%d",&M);
        int j=0;
        char c;
        do{
            scanf("%s",a[j].str);
            a[j].len= strlen(a[j].str);
            j++;
            c = getchar();
        }while(c!='\n');
        printf("case #%d:\n",i);
        int sum=0;
        int cnt=0;
        int sum2=0;
        int ave=0;
        int num=0;
        for(int t=0;t<j;t++){
            sum=sum+a[t].len;
            cnt++;
            if(sum+cnt-1>M) {
                cnt--;
                sum = sum - a[t].len;
                sum2 = M - sum;
                ave = sum2 / (cnt - 1);
                num = sum2 % (cnt - 1);
                for (int p = 0; p < cnt; p++) {
                    printf("%s", a[t - cnt + p].str);
                    if (p != cnt - 1) {
                        int num2 = ave;
                        if (p >= (t - num - 1)) {
                            num2++;
                        }
                        for (int q = 0; q < num2; q++) {
                            printf(" ");
                        }
                    } else {
                        printf("\n");
                    }
                }
                t--;
            }
            if(t==j-1){
                for (int p = 0; p < cnt; p++) {
                    printf("%s%c", a[t - cnt + p].str,p==cnt-1?'\n':' ');
                }
            }
            
        }
    }

    return 0;
}
