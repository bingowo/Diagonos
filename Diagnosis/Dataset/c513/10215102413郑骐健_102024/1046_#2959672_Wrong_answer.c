#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007





int main()
{

    char p[6][7] = {"the","a","an","of","for","and"};
    int t ;
    scanf("%d",&t);
    for(int k =0;k<t;k++)
    {
        printf("case #%d:\n",k);
        int count =0;
        char mid [200];
        char c;
        while(scanf("%s%c",mid,&c))
        {
            int flag = 1;
            for(int q = 0;q<6;q++)
            {
                if(strcmp(p[q],mid)==0)flag =0;
            }
            if(flag)count++;
            if(c=='\n')break;
        }
        printf("%d",count);
        if(k!=t-1)printf("\n");
    }
    return 0;
}
