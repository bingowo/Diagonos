#include <stdio.h>



void change()
{
    int A[9]={1,1,1,1,1,1,1,1,1};
    int n;
    for (int i=0;i<9;i++)
    {
        scanf("%d",&n);
        if(n%2==1)
        {
            switch(i)
            {
                case 0:A[0]=-A[0];A[1]=-A[1];A[3]=-A[3];break;
                case 1:A[0]=-A[0];A[1]=-A[1];A[2]=-A[2];A[4]=-A[4];break;
                case 2:A[1]=-A[1];A[2]=-A[2];A[5]=-A[5];break;
                case 3:A[0]=-A[0];A[3]=-A[3];A[6]=-A[6];A[4]=-A[4];break;
                case 4:A[3]=-A[3];A[1]=-A[1];A[5]=-A[5];A[4]=-A[4];A[7]=-A[7];break;
                case 5:A[5]=-A[5];A[8]=-A[8];A[2]=-A[2];A[4]=-A[4];break;
                case 6:A[6]=-A[6];A[7]=-A[7];A[3]=-A[3];break;
                case 7:A[7]=-A[7];A[6]=-A[6];A[8]=-A[8];A[4]=-A[4];break;
                case 8:A[5]=-A[5];A[7]=-A[7];A[8]=-A[8];break;
            }
        }

    }
    for (int i=0;i<9;i++)
    {
        if(A[i]==-1)
        {
            printf("0 ");
        }
        else printf("1 ");
        if((i+1)%3==0)
        printf("\n");
    }

}

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        printf("case #%d:\n",count1-count-1);
        change();
    }
}
