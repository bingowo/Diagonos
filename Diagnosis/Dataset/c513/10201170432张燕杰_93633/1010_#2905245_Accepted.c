#include<stdio.h>
#include<stdlib.h>

int ex3(char a,char b,char c)
{
    int x;
    x = ((int)a-48)*100+((int)b-48)*10+(int)c-48;
    int ans[10];
    for(int i = 0;i<10;i++)
    {
        ans[i] = x%2;
        x = x/2;
    }
    for(int i = 9;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}

int ex2(char a,char b)
{
    int x;
    x = ((int)a-48)*10+(int)b-48;
    int ans[7];
    for(int i = 0;i<7;i++)
    {
        ans[i] = x%2;
        x = x/2;
    }
    for(int i = 6;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}

int ex1(char a)
{
    int x;
    x = (int)a;
    int ans[4];
    for(int i = 0;i<4;i++)
    {
        ans[i] = x%2;
        x = x/2;
    }
    for(int i = 3;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}

int ex(int x)
{
    int ans[10];
    for(int i = 0;i<10;i++)
    {
        ans[i] = x%2;
        x = x/2;
    }
    for(int i = 9;i>=0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}

int main()
{
    char num[500] = {'\0'};
    int count = 0;
    while((num[count]=getchar())!='\n')
    {
        count = count+1;
    }
    char tail[10] = {'\0'};
    char body[10] = {'\0'};
    printf("0001");
    int i=0;
    if(count == 1)
    {
         ex(1);
       ex1(num[0]);
       return 0;
    }

    if(count == 2)
    {
        ex(2);
       ex2(num[0],num[1]);
       return 0;
    }

    if(count==3)
    {
        ex(3);
        ex3(num[0],num[1],num[2]);
        return 0;
    }

    else
    {
        ex(count);
        int flag = count%3;
        for(i = 0;i+2<count;i=i+3)
        {
            ex3(num[i],num[i+1],num[i+2]);
        }
        if(flag==1)
        {
            ex1(num[count-1]);
            return 0;
        }
        else if(flag==2)
        {
            ex2(num[count-2],num[count-1]);
            return 0;
        }
        else{return 0;}
    }
}