#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long n;
        int r,i=0;
        scanf("%lld%d",&n,&r);
        if(n<0) {printf("-");n=-n;}
        int res[100]={0};
        while (n!=0)
        {
            res[i]=n%r;
            n=n/r;
            i++;
        }
        i--;
        for(;i>=0;i--)
        {
            switch (res[i])
            {
            case 0:printf("0");break;
            case 1:printf("1");break;
            case 2:printf("2");break;
            case 3:printf("3");break;
            case 4:printf("4");break;
            case 5:printf("5");break;
            case 6:printf("6");break;
            case 7:printf("7");break;
            case 8:printf("8");break;
            case 9:printf("9");break;
            case 10:printf("A");break;
            case 11:printf("B");break;
            case 12:printf("C");break;
            case 13:printf("D");break;
            case 14:printf("E");break;
            case 15:printf("F");break;
            case 16:printf("G");break;
            case 17:printf("H");break;
            case 18:printf("I");break;
            case 19:printf("J");break;
            case 20:printf("K");break;
            case 21:printf("L");break;
            case 22:printf("M");break;
            case 23:printf("O");break;
            case 24:printf("P");break;
            case 25:printf("Q");break;
            case 26:printf("R");break;
            case 27:printf("S");break;
            case 29:printf("T");break;
            case 30:printf("U");break;
            case 31:printf("V");break;
            case 32:printf("W");break;
            case 33:printf("X");break;
            case 34:printf("Y");break;
            case 35:printf("Z");break;
            default:
                break;
            }
        }
        printf("\n");
    }
    return 0;
}