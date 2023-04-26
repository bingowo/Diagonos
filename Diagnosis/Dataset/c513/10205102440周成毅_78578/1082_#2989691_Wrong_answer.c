#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[1001], b[1001], c[1001];
    char sum[1002];
    memset(a, 48, sizeof(a)-sizeof (char));
    memset(b, 48, sizeof(b)-sizeof (char));
    memset(c, 48, sizeof(c)-sizeof (char));
    memset(sum, 48, sizeof(sum)-sizeof (char));
    a[1000]=b[1000]=c[1000]='\0';
    sum[1001]='\0';
    scanf("%s %s %d", a, b, &n);
    int lena = strlen(a), lenb = strlen(b);
    int ap, bp, sp, flag = 1;//记录小数点位置
    for (int i = 0; i < lena; i++)
        if (a[i] == '.') {
            ap = i;
            flag = 0;
            break;
        }
    if (flag) {
        a[lena] = '.';
        ap = lena;
    }
    flag = 1;
    for (int i = 0; i < lenb; i++)
        if (b[i] == '.') {
            bp = i;
            flag = 0;
            break;
        }
    if (flag) {
        b[lenb] = '.';
        bp = lenb;
    }
    int len = bp - ap;
    if (len >= 0) {
        c[len] = '\0';
        strcat(c, a);
        int lenc= strlen(c);
        b[lenb]='0';
        c[lenc]='\0';
        int ans = 1000;
        int bit, jin = 0;
        for (int i = 999; i >= 0; i--) {
            if (c[i] == '.') {
                sp = ans;
                sum[ans--] = '.';
            } else {
                bit = (c[i] - '0' + b[i] - '0' + jin) % 10;
                jin = (c[i] - '0' + b[i] - '0' + jin) / 10;
                sum[ans--] = bit + '0';
            }
        }
        sum[0] = jin + '0';
    } else {
        len = -len;
        c[len] = '\0';
        strcat(c, b);
        int lenc= strlen(c);
        c[lenc]='\0';
        a[lena]='0';
        int ans = 1000;
        int bit, jin = 0;
        for (int i = 999; i >= 0; i--) {
            if (c[i] == '.') {
                sp = ans;
                sum[ans--] = '.';
            }
            else {
                bit = (c[i] - '0' + a[i] - '0' + jin) % 10;
                jin = (c[i] - '0' + a[i] - '0' + jin) / 10;
                sum[ans--] = bit + '0';
            }
        }
        sum[0] = jin + '0';
    }
    if(sum[sp+n+1]>='5'){
        int jin=1,bit;
        for(int i=sp+n;i>=0;i--){
            if(jin==0)
                break;
            else {
                if(sum[i]=='.')
                    continue;
                bit = (sum[i] - '0' + jin) % 10;
                jin = (sum[i] - '0' + jin) / 10;
                sum[i] = bit + '0';
            }
        }
    }
    int co=0;
    while (sum[co]=='0')
        co++;
    if(sum[co]=='.')
        printf("0");
    for(int i=co;i<=sp+n;i++)
        printf("%c",sum[i]);
    printf("\n");
    return 0;
}
