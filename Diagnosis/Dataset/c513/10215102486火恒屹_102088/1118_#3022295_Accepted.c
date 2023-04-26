#include <stdio.h>
#include <stdlib.h>
int width,height;
long long angle=0;
int matrix[202][202];
int matrix2[202][202];
void turnright(int *m1,int *m2)
{
    for(int i=1;i<=height;i++)
        for(int j=1;j<=width;j++)
        {
            m2[j*202+height-i+1]=m1[i*202+j];
        }
    int temp=width;
    width=height;
    height=temp;
}

int main()
{
    char d;
    scanf("%d %d %lld %c",&width,&height,&angle,&d);
    for(int i=1;i<=height;i++)
        for(int j=1;j<=width;j++)
            scanf("%d",&matrix[i][j]);
    if(angle>=360)
        angle=angle-360*(angle/360);
    if(d=='L')
        angle=360-angle;
    if(angle>=360)
        angle-=360;
    if(angle==90)
        turnright(matrix,matrix2);
    else if(angle==180)
    {
        turnright(matrix,matrix2);
        turnright(matrix2,matrix);
    }
    else if(angle==270)
    {
        turnright(matrix,matrix2);
        turnright(matrix2,matrix);
        turnright(matrix,matrix2);
    }
    printf("%d %d\n",width,height);
    if((angle/90)%2==0)
    {
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)
                printf("%d ",matrix[i][j]);
            printf("\n");
        }
    }
    else
    {
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)
                printf("%d ",matrix2[i][j]);
            printf("\n");
        }
    }
    return 0;
}
