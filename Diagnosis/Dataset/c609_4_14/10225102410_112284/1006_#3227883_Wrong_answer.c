#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d",&num);
    for(int i = 0;i < num;i++){
        char input[60];
        memset(input, 0, sizeof(char) * 60); //This will reinitialize all to ZERO
        char *in = input;
        char nm[65];
        char *nu = nm;
        int n = 2;int e = 1;
        scanf("%c",in);
        if(i > 0) in++;
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
        in = in + e;
        int ans = 1;
        for(int j = 0;j < e - 1;j++){
            ans = ans * n + 1;
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
