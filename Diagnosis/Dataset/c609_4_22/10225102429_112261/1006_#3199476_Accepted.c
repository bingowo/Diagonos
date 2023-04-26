#include <stdio.h>
#include <string.h>
int main()
{
    int T; scanf("%d",&T);
    for(int i = 0; i<T; i++)
    {
        int Var,Val;
        unsigned long long sum = 0,pow = 1;
        char s1[61] = {0},s2[61] = {0};
        scanf("%s",s1);
        s2[0] = s1[0];
        for(int j = 1; j<strlen(s1); j++)
        {
            int k = 0;
            for(; k<strlen(s2); k++) {
                if(s2[k] == s1[j]) break;
            }
            if(k==strlen(s2)) s2[k] = s1[j];
        }
        //printf("%s\n",s2);
        Var = strlen(s2);
        if(Var == 1) {
            if (strlen(s1) > 1) {
                for (int k = 0, a = 1; k < strlen(s1); k++) {
                    sum += a;
                    a *= 2;
                }
                printf("case #%d:\n%llu\n", i, sum);
                continue;
            }
            else {printf("case #%d:\n%llu\n", i, 1);continue;}
        }
        //printf("%d\n",Var);
        Val = Var-2;
        for(int j = strlen(s1)-1; j>-1; j--)
        {
            int val;
            for(int k = 0; k<Var; k++)
            {
                if(s2[k]==s1[j]){
                if(k==0) {val = 1; break;}
                else if(k>1) {val = k; break;}
                else if(k==1){val = 0; break;}
                }
            }
            sum+=val*pow;
            pow*=Var;
            //printf("sum = %d\n",sum);
        }
        printf("case #%d:\n%llu\n",i,sum);
    }
    return 0;
}