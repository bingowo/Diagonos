#include <stdio.h>
#include <string.h>

int judge(char* roma);
int Match(char* temp);
int main(int argc, const char * argv[]) {
    char roma[50];
    scanf("%s",roma);
    printf("%d",judge(roma));
    return 0;
}

int judge(char* roma)
{
    int num=0,i,j,k=0,l=0;
    char temp[4]={0};
    int res[4]={0};
    for(i=0;i<strlen(roma);i=i+k)
    {

        for(j=3;j>=0;j--)
        {



                memset(temp, '\0', sizeof(temp));

                for(k=0;k<=j;k++)
                {
                    temp[k]=roma[i+k];
                }
                //判断temp
                if(Match(temp)!=0)
{


                    res[l++]=Match(temp);
                    break;
}


        }
    }
    for(l=0;l<4;l++)
    {
        num+=res[l];
    }
    return num;
}

int Match(char* temp)
{
    char* r[50]={"M","MM","MMM",
        "C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
        "X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
        "I","II","III","IV","V","VI","VII","VIII","IX"};
    for(int i=0;i<30;i++)
    {
        if(strcmp(r[i], temp)==0)
        {
            switch (i) {
                case 0:return 1000;
                case 1:return 2000;
                case 2:return 3000;
                case 3:return 100;
                case 4:return 200;
                case 5:return 300;
                case 6:return 400;
                case 7:return 500;
                case 8:return 600;
                case 9:return 700;
                case 10:return 800;
                case 11:return 900;
                case 12:return 10;
                case 13:return 20;
                case 14:return 30;
                case 15:return 40;
                case 16:return 50;
                case 17:return 60;
                case 18:return 70;
                case 19:return 80;
                case 20:return 90;
                case 21:return 1;
                case 22:return 2;
                case 23:return 3;
                case 24:return 4;
                case 25:return 5;
                case 26:return 6;
                case 27:return 7;
                case 28:return 8;
                case 29:return 9;
                    break;

                default:
                    break;
            }
        }
    }
    return 0;
}
