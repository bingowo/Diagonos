#include <stdio.h>
int L[500][200];
void add(int a,int c)
{
    int count=0,temp=0;
    for(int i=199;i>=0;i--)
    {
       temp = L[c][i]+L[a][i]+count;
       count = temp/10;
       L[c][i] = temp%10;
    }
}
int main()
{
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
            L[i][j]=0;
    L[0][199] = 1;
    L[1][199] = 2;
    L[2][199] = 3;
    L[3][199] = 6;
    int num = 0;
    scanf("%d",&num);
    for(int i=4;i<num;i++)
    {
        add(i-1,i);
        add(i-2,i);
        add(i-4,i);
    }
    int zero = 0;
    for( zero=0; L[num-1][zero]==0; zero++);
    for( int i=zero; i<200; i++){
        printf("%d",L[num-1][i]);
    }
    return 0;
}