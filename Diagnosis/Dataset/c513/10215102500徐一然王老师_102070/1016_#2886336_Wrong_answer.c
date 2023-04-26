#include<stdio.h>

int main()
{
    int x,B,i=0;
    scanf("%d %d",&x,&B);
    char A[100];
    int temp;
    while(x!=0)
    {
        if(x%B<0)
        {
            temp=x-(x/B+1)*B;
            if((temp+'A'-10)>='A'&&(temp+'A'-10)<='F')
            {
                A[i]=temp+'A'-10;
                i++;
            }
            else
            {
                A[i]=temp+'0';
                i++;
            }
            x=(x/B+1)*B;

        }
        else
        {
            temp=x%B;
            if((temp+'A'-10)>'A')
            {
                A[i]=temp+'A'-10;
                i++;
            }
            else
            {
                A[i]=temp+'0';
                i++;
            }
            x=x/B;

        }
    }
    i--;
    for(int j=i;j>=0;j--)
    {
        printf("%c",A[j]);
    }

}
