#include <stdio.h>
#include <stdlib.h>

int* getAB(char* s)
{
    int* pResList = (int*)malloc(2*sizeof(int));memset(pResList,0,2*sizeof(int));
    int i = 0,a = 0,b = 0;
    int flagA = 0,flagB = 0;
    if(s[0] == '-'){flagA = 1;i++;}
    while((s[i] != 0)&&(s[i] != '+')&&(s[i] != '-')&&(s[i]>='0')&&(s[i]<='9'))
    {
        a = 10*a + s[i]-'0';i++;
    }
    if(s[i] == '+'){flagB = 0;}
    else if(s[i] == '-'){flagB = 1;}
    i++;
    while(s[i] != 0)
    {
        if((s[i]>='0')&&(s[i]<='9')){b = 10*b + s[i]-'0';}
        else if(s[i] == 'i'){b = 1;}
        i++;
    }
    if(flagA == 1){a = a*(-1);}
    if(flagB == 1){b = b*(-1);}
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

    int res[1000];memset(res,0,100*sizeof(int));
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

    for(int i = j-1;i>=0;i--)
    {
        printf("%d",res[i]);
    }

    return 0;
}
