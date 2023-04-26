#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    char N[T][50];
    for(int i=0;i<T;i++){
        scanf("%s",&N[i]);
    }
    for(int i=0;i<T;i++){
        printf("case #%d\n",i);
        double sum=0.0;
        int l=strlen(N[i]);
        for(int j=2;j<l;j++){
            sum+=(N[i][j]-'0')*pow(0.125,j-1);
        }
        printf("%.150g\n",sum);
    }
    return 0;
}