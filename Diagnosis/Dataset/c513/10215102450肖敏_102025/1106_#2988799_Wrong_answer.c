#include <stdio.h>
#include <string.h>

int main() {
    char w[1001];
    scanf("%s",w);
    int len= strlen(w);
    int mod=1;
    int a[1001];
    if(len == 1)
        printf("1\n");
    else {
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                if (w[0] == w[1])
                    a[0]=1;
                else a[0]=2;
            }
            else if(i == len-1)
            {
                if(w[len-1]==w[len-2])
                    a[len-1]=1;
                else
                    a[len-1]=2;
            }
            else
            {
                if((w[i]==w[i-1] && w[i]!=w[i+1]) || (w[i]!=w[i-1] && w[i]==w[i+1]))
                    a[i]=2;
                else if(w[i]==w[i-1] && w[i]==w[i+1])
                    a[i]=1;
                else
                    a[i]=3;
            }
            mod=mod%1000000007*a[i];
        }
        printf("%d\n",mod);
    }
    return 0;
}
