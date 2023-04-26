#include <stdio.h>
#include <stdlib.h>

int* getAB(char* s)
{
    int* pResList = (int*)malloc(2*sizeof(int));memset(pResList,0,2*sizeof(int));
    int i = 0,a = 0,b = 0,n1 = 0,n2 = 0;
    int flagA = 1,flagB = 1,flag1 = 1,flag2 = 1;//flag1和flag2表示第一第二个数的正负
    int flag = 0,flag_i1 = 0,flag_i2 = 0;//flag表示第一个数就是bi,flag_i1表示第一个数就是i,flag_i2表示第二个数是i
    if(s[0] == '-'){flag1 = -1;i++;}
    else if(s[0] == 'i'){flag_i1 = 1;}
    while((s[i] != 0)&&(s[i]>='0')&&(s[i]<='9'))
    {
        n1 = 10*n1 + s[i]-'0';//获取第一个数
        i++;
    }
    if(s[i] == '+'){flag2 = 1;}
    else if(s[i] == '-'){flag2 = -1;}
    else if(s[i] == 'i'){flag = 1;}
    i++;
    if(s[i] == 'i'){flag_i2 = 1;}
    while((s[i] != 0)&&(s[i]>='0')&&(s[i]<='9'))
    {
        n2 = 10*n2 + s[i]-'0';//获取第二个数
        i++;
    }

    a = n1*flag1;
    b = n2*flag2;

    if(flag_i1 == 1){b = 1*flag1;a = 0;}
    else if(flag_i2 == 1){b = 1*flag2;}
    else if(flag == 1){b = n1*flag1;a = 0;}


    pResList[0] = a;pResList[1] = b;
    return pResList;
}

int getR(int a, int b)
{
    if((a+b)%2 == 0){return 0;}
    else{return 1;}
}
int getQi(int a, int b, int r)
{
    int Qi = 0;
    Qi = (r-a-b)/2;
    return Qi;
}

int main()
{
    char* s[100];memset(s,0,100*sizeof(char));
    scanf("%s",s);
    int* pab = getAB(s);
    int a = pab[0], b = pab[1],Qi = 0,Qr = 0;
    int r = getR(a,b);
    free(pab);
    //printf("a = %d,b = %d,r = %d\n",a,b,r);

    int res[100];memset(res,0,100*sizeof(int));
    int j = 0;
    while(!((a == 0)&&(b == 0)))
    {
        r = getR(a,b);
        Qi = getQi(a,b,r);
        Qr = Qi + b;
        a = Qr;b = Qi;
        res[j++] = r;
        //printf("a = %d, b = %d, Qr = %d, Qi = %d, r = %d\n",a,b,Qr,Qi,r);
    }
    if(s[0] == '0'){printf("0");}
    else
    {
        for(int i = j-1;i>=0;i--)
        {
            printf("%d",res[i]);
        }
    }

    return 0;
}
