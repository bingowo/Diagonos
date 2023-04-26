#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char c;
    int D;
} KEY;

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        char s[61];
        scanf("%s",s);
        int length=strlen(s);
        int n1=0,d1=0;
        long long int x=0;
        KEY* p=(KEY*)malloc(length*sizeof(KEY));
        for (int f=0;f<length;f++){
            if (f==0) {
                (p+n1)->c=s[f];
                (p+n1)->D=1;
                n1++;
            }
            else {
                int k1=0;
                for(;k1<n1;k1++){if ((p+k1)->c==s[f]) break;}
                if (k1==n1){
                    (p+n1)->c=s[f];
                    (p+n1)->D=d1;
                    n1++;
                    d1= (d1==0) ? 2 : d1+1;
                }
            }
        }
        for (int j=0;j<length;j++){
            for(int k=0;k<n1;k++){
                if((p+k)->c==s[j]) x=x+((p+k)->D)*pow(n1,length-1-j);
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",x);
        free(p);
    }
    return 0;
}
