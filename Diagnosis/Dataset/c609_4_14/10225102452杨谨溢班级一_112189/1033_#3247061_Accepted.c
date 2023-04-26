#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char C[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main()
{
    int cases;
    scanf("%d",&cases);
    for (int cas = 0;cas<cases;++cas)
    {
        char str[106];
        scanf("%s",str);
        int binary[805] = {0};
        int e = 0;
        int l = strlen(str);
        //printf("l:  %d\n",l);
        for (int i = 0;i<l;++i)
        {
            int  c = str[i];
            int n = 128;
            for (int j = 0;j<8;++j)
            {
                if ((c & n) != 0)   binary[e] = 1;
                //printf("B:   %d  %d\n", c & n,binary[e]);
                n = n >> 1;
                e++;
            }
        }
        e = 0;
        char sstr[140] = {0};
        int ll = (l*8+5)/6;   // 计算新的字符串的长度
        //printf("ll:  %d\n",ll);
        int i = 0;
        for (i = 0;i< ll;++i)
        {
            int cc = 0;
            for (int j = 0;j<6;++j)   cc = cc * 2 + binary[e++];
            sstr[i] = C[cc];
            //printf("C:%d   %c\n",cc,C[cc]);
        }
        while (i%4 != 0)  sstr[i++] = '=';
        sstr[i] = '\0';
        printf("case #%d:\n",cas);
        printf("%s\n",sstr);
    }
    return 0;
}
