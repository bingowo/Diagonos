#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000
#define N 100

typedef struct {
    char word[40];
    int length;
} Unit;

int main() {
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++) {
        int m, l, i, cnt=0, j=0, check=0;
        char sor[2018];
        Unit unit[1000];
        scanf("%d",&m);
        getchar();
        gets(sor);
        l=strlen(sor);
        for(i=0; i<l; i++) {
            if(sor[i]==' ') {
                if(sor[i+1]==' ') continue;
                else if(cnt==0&&check==0) {
                    check=1;
                    continue;
                }
                unit[cnt].word[j]='\0';
                unit[cnt].length=strlen(unit[cnt].word);
                cnt++;
                j=0;
            }
            else {
                unit[cnt].word[j++]=sor[i];
                check=1;
            }
        }
        unit[cnt].word[j]='\0';
        unit[cnt].length=strlen(unit[cnt].word);
        cnt++;
        int max=cnt, k, x, y, z;
        printf("case #%d:\n",I);
        for(i=0, j=0, l=0, cnt=0, z=0; i<max; i++) {
            l+=(unit[i].length+1);
            cnt++;
            if(l>m+1) {
                cnt-=2;
                l-=(unit[i--].length+2);
                l-=cnt;
                j=(m-l)/cnt;
                k=(m-l)%cnt;
                for(x=cnt; x>=0; x--) {
                    printf("%s",unit[z++].word);
                    if(x<=k&&x)
                        for(y=0; y<j+1; y++)
                            printf(" ");
                    else
                        for(y=0; y<j; y++)
                            printf(" ");
                }
                printf("\n");
                cnt=0;
                l=0;
            }
        }
        for(x=max-z; x>0; x--)
            printf("%s ",unit[z++].word);
        printf("\n");
    }
    return 0;
}
