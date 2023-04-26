void op(int num,int len);
int
main()
{
    char num[501] = {'\0'};
    int length;
    int N,remain;
    
    gets(num);
    length = strlen(num);
    N = length/3;
    remain = length%3;
    printf("0001");
    op(length, 10);
    for (int i=0; i<N; i++)
    {
        char temp[4];
        temp[3] = '\0';
        temp[0] = *(num+i*3+0);
        temp[1] = *(num+i*3+1);
        temp[2] = *(num+i*3+2);
        op(atoi(temp), 10);
    }
    if (remain==2)
    {
        char temp[3];
        temp[2] = '\0';
        temp[0] = *(num+N*3+0);
        temp[1] = *(num+N*3+1);
        op(atoi(temp), 7);
    }
    else if (remain==1)
    {
        char temp[2];
        temp[1] = '\0';
        temp[0] = *(num+N*3+0);
        op(atoi(temp), 4);
    }
    printf("\n");
    
    return 0;
}

void
op(int num,int len)
{
    for (int i=len-1; i>-1; i--)
    {
        if ((num>>i&1)==1)
        {
            printf("1");
        }
        else    printf("0");
    }
}