#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void turn(int j)
{
    if((j>=1)&&(j<=9))
        printf("%d",j);
    else
        printf("%c",j-10+'A');
}
int main()
{
    int goal;
    int R;
    scanf("%d %d",&goal,&R);
    int i=1;
    int num=0;
    if(goal<0)
    {while(-(-R-1)*pow(-R,i)>goal)
        i=i+2;
    for(i=i;i>=0;i=i-1)
    {
        if(i%2)
        {
            if(num==goal)
            {
                printf("0");
                continue;
            }
            for(int j=1;j<=-R-1;j++)
            {
                
                if((num-j*pow(-R,i)<=goal)&&(num-(j-1)*pow(-R,i)>goal))
                    {turn(j);
                    num=num-j*pow(-R,i);
                    break;}
            }
        }
        else
        {
            if(num==goal)
            {
                printf("0");
                continue;
            }
            for(int j=1;j<=-R-1;j++)
            {
                if((num+j*pow(-R,i)>=goal)&&(num+(j-1)*pow(-R,i)<goal))
                    {turn(j);
                    num=num+j*pow(-R,i);
                    break;}
            }
        }
    }}
    else if(goal==0)
        printf("0");
    else
    {i=0;
        while((-R-1)*pow(-R,i)<goal)
        i=i+2;
    for(i=i;i>=0;i=i-1)
    {
        if(i%2)
        {
            if(num==goal)
            {
                printf("0");
                continue;
            }
            for(int j=1;j<=-R-1;j++)
            {
                if((num-j*pow(-R,i)<=goal)&&(num-(j-1)*pow(-R,i)>goal))
                    {turn(j);
                    num=num-j*pow(-R,i);
                    break;}
            }
        }
        else
        {
            if(num==goal)
            {
                printf("0");
                continue;
            }
            for(int j=1;j<=-R-1;j++)
            {
                if((num+j*pow(-R,i)>=goal)&&(num+(j-1)*pow(-R,i)<goal))
                    {turn(j);
                    num=num+j*pow(-R,i);
                    break;}
            }
        }
    }}
    return 0;
}
