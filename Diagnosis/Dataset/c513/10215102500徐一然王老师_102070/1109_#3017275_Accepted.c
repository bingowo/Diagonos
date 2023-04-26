#include <stdio.h>

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    int i;
    while(count--)
    {
        int A;int flag=0;int sign=0;
        printf("case #%d:\n",count1-count-1);
        for (i=8;i>=0;i--)
        {
            scanf("%d",&A);
            if(i==1)
            {
                if(A==0){flag++;continue;}
                else if(A==1)
                {
                    if(sign==0)
                    {
                        printf("x");sign++;
                    }
                    else {printf("+x");sign++;}

                }
                else if(A==-1)
                {
                    printf("-x");sign++;
                }
                else
                {
                    if(A>0&&sign!=0)
                    {
                        printf("+%dx",A);sign++;
                    }
                    else if(A>0&&sign==0)
                    {
                        printf("%dx",A);sign++;
                    }
                    else if(A<0)
                    {
                        printf("%dx",A);sign++;
                    }

                }
            }
            else if(i==0)
            {
                if(A>0&&sign!=0){printf("+%d",A);sign++;}
                else if(A>0&&sign==0){printf("%d",A);sign++;}
                else if(A<0){printf("%d",A);sign++;}
                else {flag++;continue;}
            }
            else
            {
                if(A==0){flag++;continue;}
            else if(A==1&&sign!=0)
            {
                printf("+x^%d",i);sign++;
            }
            else if(A==1&&sign==0)
            {
                printf("x^%d",i);sign++;
            }
            else if(A==-1)
            {
                printf("-x^%d",i);sign++;
            }
            else
            {
                if(A>0&&sign!=0)
                {
                    printf("+%dx^%d",A,i);sign++;
                }
                else if(A>0&&sign==0)
                {
                    printf("%dx^%d",A,i);sign++;
                }
                else if(A<0)
                {
                    printf("%dx^%d",A,i);sign++;
                }

            }
            }

        }
        if(flag==9)printf("0");
        printf("\n");
    }
}
