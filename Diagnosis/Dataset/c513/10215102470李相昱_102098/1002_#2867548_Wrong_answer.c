#include <stdio.h>
#include <ctype.h>
int main()
{
    int t,i,m,n,c,num;
    char q;
    int a[123];
    for(i=0;a[i];i++)
    {
        a[i] = -1;
    }
    int l[60];
    scanf("%d",&t);
    for(i = 0;i<=t+1;i++){
        m = 0;
        n = 0;
        num = 0;
        long long int res=0;
        while(scanf("%c",&q)&& isalnum(q)){
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
            l[m] = a[q];
            m++;

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
            printf("case #%d:\n", i - 1);
            printf("%d\n", res);
        }
    }

    return 0;
}
