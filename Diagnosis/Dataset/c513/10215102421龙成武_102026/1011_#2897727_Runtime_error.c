#include<stdio.h>
#include<string.h>
#include<malloc.h>
char alpha[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
char reference[16][5] = {"0000","0001","0010","0011",\
                        "0100","0101","0110","0111",\
                        "1000","1001","1010","1011",\
                        "1100","1101","1110","1111"};
void changedigit(char *c,char num)
{
    int tim,i;
    for(i=0;i<16;i++)
    {
        if(alpha[i]==num)
            break;
    }
    for(tim=0;tim<4;tim++)
    {
        c[tim]=reference[i][tim];
    }
    //待删掉前导零
}
void changei_1(char *c,long long int *res);       //不能用减号做函数名
int main()
{
    int i,j;
    long long int res[2];
    char a[65],*c;
    c=(char*)malloc(sizeof(char)*65);
    memset(c,0,sizeof(char)*65);
    getchar();
    getchar();
    scanf("%s",a);
    for(i=0,j=0;i<strlen(a);i++,j+=4)
    {
        changedigit(c+j,a[i]);
    }
    for(i=0,j=0;i<3;i++)
    {
        if(c[i]=='0')
            j++;
        else if(c[i]!='0')          //只要删掉从一开始连续出现的0，而不是前三位所有的0
            break;
    }
    c+=j;       //删掉前导0

    changei_1(c,res);

    if(res[0]!=0&&res[1]!=0)
    {
        if(res[1]>0)
        {
            if(res[1]!=1)
                printf("%d+%di",res[0],res[1]);
            else
                printf("%d+i",res[0],res[1]);
        }
        else if(res[1]<0)
        {
            if(res[1]!=-1)
                printf("%d%di",res[0],res[1]);
            else
                printf("%d-i",res[0],res[1]);
        }
    }
    else if(res[1]==0)
    {
        printf("%d",res[0]);
    }
    else if(res[0]==0)
    {
        if(res[1]!=1)
            printf("%di",res[1]);
        else
            printf("i");
    }


    free(c);
    return 0;
}
void changei_1(char *c,long long int *res)
{
   long long int qr,qi,i,q1r,q1i;
   qr=qi=0;
   for(i=0;i<strlen(c);i++)
   {
       q1r=-(qr+qi)+(c[i]-'0');
       q1i=qr-qi;

       qr=q1r; qi=q1i;
   }
   res[0]=qr;
   res[1]=qi;
}
