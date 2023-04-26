#include <stdio.h>
#include <stdlib.h>  //atoi atof

int main()
{
    char ss[20];
    memset(ss,'\0',20);//用长度为4的数组储存0 1 2 3次的系数
    while(scanf("%s",ss)!=EOF)
    {
        int i=5;
        char temp[10];
        int num[4]={0};
        memset(temp,'\0',10);
        int j=0;
        while(ss[i]!='\0'&&i<strlen(ss))
        {
            j=0;
            while(ss[i]!='x'&&ss[i]!='\0')
            {
                temp[j]=ss[i];
                j++;
                i++;
            }//此时s[i]==x或者s[i]=='\0'
            //如果是x那么要读到他的次数
            //如果是s[i]=='\0'那么直接结束 break
            int tempnum=(int)atoi(temp);
            memset(temp,'\0',10);
            //printf("%doo\n",tempnum);
            int c;
            if(ss[i]=='x')
            {
                //那么就判断次数
                if(ss[i+1]=='^')
                {
                    c=ss[i+2]-'0';
                    i+=2;
                    i++;
                }
                else
                {
                    c=1;
                    i++;
                }

            }

            else if(ss[i]=='\0')
            {
                c=0;
            }

            num[c]=tempnum;

            if(ss[i]=='\0'||i>=strlen(ss)) break;
        }

        //printf("o%do\n",num[2]);
        //于是得到 0 1 2 3次方的系数

        /*先初始化一个20*20的点阵 之后再进行描点
        */

        char s[41][41];

        for(int i=0;i<41;i++)
        {
            for(int j=0;j<41;j++)
            {
                if(j==20&&i==0)
                {
                    s[i][j]='^';
                }
                else if(j==20)
                {
                    s[i][j]='|';
                }
                else {s[i][j]='.';}
            }
        }

        for(int i=0;i<41;i++)
        {
            if(i==40) s[20][i]='>';
            else if(i!=20) s[20][i]='-';
            else s[20][i]='+';
        }

        /*for(int k=0;k<41;k++)
            for(int z=0;z<41;z++)
        {
            printf("%c",s[k][z]);
            if(z==40) printf("\n");
        }*/


        for(int x=0;x<=20;x++)//以原点为中点 算出的x和y去加和减去 原点坐标20,20
        {
            int y;
            y=x*x*x*num[3]+x*x*num[2]+x*num[1]+num[0];
           // printf("%d\n",y);
            if(y<=20&&y>=-20)
            {
                s[20-y][20+x]='*';
            }
        }

        for(int x=0;x>=-20;x--)
        {
            int y;
            y=x*x*x*num[3]+x*x*num[2]+x*num[1]+num[0];
            if(y<=20&&y>=-20)
            {
                s[20-y][20+x]='*';
            }
        }

        for(int k=0;k<41;k++)
            for(int z=0;z<41;z++)
        {
            printf("%c",s[k][z]);
            if(z==40) printf("\n");
        }

    }
    return 0;
}

