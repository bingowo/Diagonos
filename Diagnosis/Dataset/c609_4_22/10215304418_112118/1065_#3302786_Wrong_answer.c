#include <stdio.h>
#include <stdlib.h>

char c[1234];

int main()
{
    int t;
    scanf("%d",&t);
    for (int l=0;l<t;l++){
        int t=0;
        int f=0;
        double a=0,b=0;
        char st[1234];
        scanf("%s",st);
        t++;
        c[t]=st[0];
        while (t>=1){
            scanf("%s",st);
            if (st[0]=='-' || st[0]=='+' || st[0]=='*' || st[0]=='/'){
                t++;
                c[t]=st[0];
            }
            else{
                if (f==0){
                    a=atof(st);
                    f=1;
                }
                else{
                    b=atof(st);
                    if (c[t]=='-'){
                        a=a-b;
                        t--;
                    }
                    else if (c[t]=='+'){
                        a=a+b;
                        t--;
                    }
                    else if (c[t]=='*'){
                        a=a*b;
                        t--;
                    }
                    else if (c[t]=='/'){
                        a=a/b;
                        t--;
                    }
                }
            }
            printf("%d\n",a);
        }

        printf("case #%d:\n",l);
        printf("%ld\n",a);
    }
    return 0;
}
