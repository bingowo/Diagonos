#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    int cnt, x[101]={0}, y[101]={0};
    for(cnt=1; (c=getchar())!='\n'; ++cnt) {
        x[cnt] = x[cnt-1];  y[cnt] = y[cnt-1];
        switch(c) {
            case 'U': ++y[cnt];  break;
            case 'D': --y[cnt];  break;
            case 'R': ++x[cnt];  break;
            case 'L': --x[cnt];  break;
        }
    }
    int mx = x[cnt-1], my = y[cnt-1], q;
    scanf("%d",&q);
    for(int j=0; j<q; ++j) {
        int a, b, i=0;
        scanf("%d %d",&a, &b); //target
        if(mx==0 && my==0) {
            for(; i<cnt; ++i)
                if(x[i]==a && y[i]==b) break;
        }else if(mx == 0) {
            for(; i<cnt; ++i)
                if(x[i]==a && (b-y[i])%my==0 && (b-y[i])/my>=0) break;
        }else if(my == 0) {
            for(; i<cnt; ++i)
                if(y[i]==b && (a-x[i])%mx==0 && (a-x[i])/mx>=0) break;
        }else {
            for(; i<cnt; ++i)
                if((a-x[i])%mx==0 && (b-y[i])%my==0 && (a-x[i])/mx==(b-y[i])/my && (b-y[i])/my>=0)
                    break;
        }
        printf("%s\n",i<cnt?"Yes":"No");
    }
    return 0;
}
