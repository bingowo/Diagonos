#include <stdio.h>
#include <string.h>

int Tab[]={2,3,5,7,11,13,17,19,
23,29,31,37,41,43,47,53,59
,61,67,71,73,79,83,89,97};

int main()
{
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; t++){
        int a[25], b[25];
        int i = 0, j = 0;
        char ch;
        do {
            scanf("%d", &a[i++]);
            ch = getchar();
        } while(ch == ',');
        do {
            scanf("%d", &b[j++]);
            ch = getchar();
        } while(ch == ',');


        int ans[25];
        int cnt = 0;
        int carry = 0;
        for (cnt = 0; i > 0 || j > 0; cnt++, j--, i--){
            int res;
            if (i > 0 && j > 0)
                res = a[i-1] + b[j-1] + carry;
            else
                if (i < 1)
                    res = b[j-1] + carry;
                else
                    res = a[i-1] + carry;

            if (res >= Tab[cnt]){
                ans[cnt] = res - Tab[cnt];
                carry = 1;
            }
            else{
                ans[cnt] = res;
                carry = 0;
            }
                
        }

        if (carry)
            ans[cnt++] = carry;
        printf("case #%d:\n", t);
        for (i = cnt - 1; i > 0; i--)
            printf("%d,",ans[i]);
        printf("%d\n", ans[0]);
    }
    return 0;
}