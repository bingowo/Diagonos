#include <stdio.h>

int
main()
{
    int N;
    int num;
    int flag = 1;
    int begin = 0;
    
    scanf("%d",&N);
    for (int c=0; c<N; c++)
    {
        flag = 1;
        begin = 0;
        printf("case #%d:\n",c);
        for (int i=0; i<9; i++)
        {
            scanf("%d",&num);
            if (num==0 && 8-i != 0)
            {
                continue;
            }
            else if(num==0 && 8-i==0)
            {
                if (flag)
                {
                    printf("0\n");
                }
                else
                {
                    printf("\n");
                }
            }
            else
            {
                flag = 0;
            }

            if (num>0)
            {
                switch (8-i)
                {
                    case 8:
                        begin = 1;
                        if (num==1)
                        {
                            printf("x^8");
                        }
                        else
                        {
                            printf("%dx^8",num);
                        }
                        break;
                    case 7:
                    case 6:
                    case 5:
                    case 4:
                    case 3:
                    case 2:
                        if (num == 1)
                        {
                            if (begin)
                            {
                                printf("+x^%d",8-i);
                            }
                            else
                            {
                                begin = 1;
                                printf("x^%d",8-i);
                            }
                        }
                        else
                        {
                            if (begin)
                            {
                                printf("+%dx^%d",num,8-i);
                            }
                            else
                            {
                                printf("%dx^%d",num,8-i);
                                begin = 1;
                            }
                        }
                        break;
                    case 1:
                        if (num == 1)
                        {
                            if (begin)
                            {
                                printf("+x");
                            }
                            else
                            {
                                printf("x");
                                begin = 1;
                            }
                            
                        }
                        else
                        {
                            if (begin)
                            {
                                printf("+%dx",num);
                            }
                            else
                            {
                                printf("%dx",num);
                            }
                        }
                        break;
                    case 0:
                        if (begin)
                        {
                            printf("+%d\n",num);
                        }
                        else
                        {
                            printf("%d\n",num);
                            begin = 1;
                        }
                        break;
                }
            }
            else if (num < 0)
            {
                switch (8-i)
                {
                    case 8:
                        begin = 1;
                        if (num==-1)
                        {
                            printf("-x^8");
                        }
                        else
                        {
                            printf("-%dx^8",-1*num);
                        }
                        break;
                    case 7:
                    case 6:
                    case 5:
                    case 4:
                    case 3:
                    case 2:
                        if (num == -1)
                        {
                            if (begin)
                            {
                                printf("-x^%d",8-i);
                            }
                            else
                            {
                                begin = 1;
                                printf("-x^%d",8-i);
                            }
                        }
                        else
                        {
                            if (begin)
                            {
                                printf("-%dx^%d",-1*num,8-i);
                            }
                            else
                            {
                                printf("-%dx^%d",-1*num,8-i);
                                begin = 1;
                            }
                        }
                        break;
                    case 1:
                        if (num == -1)
                        {
                            if (begin)
                            {
                                printf("-x");
                            }
                            else
                            {
                                printf("-x");
                                begin = 1;
                            }
                            
                        }
                        else
                        {
                            if (begin)
                            {
                                printf("-%dx",-1*num);
                            }
                            else
                            {
                                printf("-%dx",-1*num);
                            }
                        }
                        break;
                    case 0:
                        if (begin)
                        {
                            printf("-%d\n",-1*num);
                        }
                        else
                        {
                            printf("-%d\n",-1*num);
                            begin = 1;
                        }
                        break;
                }
            }
        }
    }
    
    return 0;
}
