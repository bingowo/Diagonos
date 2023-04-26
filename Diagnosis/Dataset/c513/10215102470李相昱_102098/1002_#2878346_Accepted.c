#include <stdio.h>
#include <ctype.h>
int main()
{
    int t,i,m,n,c,num,d;
    char g;
    int a[123];
    int l[60];
    scanf("%d",&t);
    getchar();
    for(i = 0;i<t;i++){
        for(d=0;d<123;d++)
        {
            a[d] = -1;
        }
        m = 0;
        n = 1;
        num = 0;
        long long int res=0;
        while(scanf("%c",&g)&& isalnum(g)){
            int q = g;
            if(a[q]==-1)
            {
                num++;
                if(num == 2){
                    a[q] = 0;
                }
                else
                {
                    a[q] = n++;
                }
            }
            l[m++] = a[q];

        }
        if(num == 1){
            for(c=0;c<m;c++){
                res = res *2+l[c];
            }
        } else{
            for(c= 0;c<m;c++){
                res = res *num +l[c];
            }
        }
        if(num) {
            printf("case #%d:\n", i);
            printf("%lld\n", res);
        }
    }
    return 0;
}