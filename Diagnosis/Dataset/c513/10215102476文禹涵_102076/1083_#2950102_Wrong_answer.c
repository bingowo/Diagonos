#include<stdio.h>


int CountZero(int n)
{
   long count = 0;
        long temp=n/5;
        while (temp!=0) {
            count+=temp;
            temp/=5;
        }
        return count;

}
int main()
{
    int i,t;
    scanf("%d",&t);
    int N;
    for(i=0;i<t;i++){
        scanf("%d",&N);
        printf("case #%d\n",i);
        printf("%d\n",CountZero(N));
    }
}