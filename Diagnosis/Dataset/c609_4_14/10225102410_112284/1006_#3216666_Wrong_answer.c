#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        char input[10000];
        char *in = input;
        char nm[65];
        char *nu = nm;
        int n = 2;int e = 1;
        scanf("%c",in);
        while(scanf("%c",in) == 1 && *in != '\n') in++;
        in = input;
        *(nu + 1) = *in;
        while(*in  == *(in + 1)) {
              in++;e++;
        }
        in++;
        *nu = *in;nu++;nu++;in++;
        while(*in  != '\n') {
                 if(strchr(nm, *in) == NULL) {*nu = *in;nu++;n++;}
                 in++;

        }
        in = input;
        in++;in++;
        int ans = 0;
        for(int j = 0;j < e;j++){
            ans = ans * n + n;
        }
         while(*in != '\n') {
                {nu = strchr(nm, *in);
                 ans = ans * n + nu - nm;
                 in++;}

        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
}
