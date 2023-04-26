#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int val[10],stk[10],top;
char s[10][10];
int mp[10]= {5,1,7,3,6,2,4,0}; //A+,A-,AB+,AB-,B+,B-,O+,O-

void outp()
{
    if(top==0)
        printf("impossible");
    else
    {
        if(top>1)
            putchar('{');
        for(int i=1; i<=top; i++)
        {
            if(stk[i]%4==0)
                putchar('O');
            else if(stk[i]%4==1)
                putchar('A');
            else if(stk[i]%4==2)
                putchar('B');
            else
                printf("AB");
            if(stk[i]>=4)
                putchar('+');
            else
                putchar('-');
            if(i!=top)
                putchar(',');
            else if(top!=1)
                putchar('}');
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1; i<=3; i++)
        {
            scanf("%s",s[i]); //s为二维数组
            if(s[i][0]=='?')
                val[i]=-1; //未知
            else if(s[i][0]=='O')
                val[i]=0;  //'O'
            else if(s[i][0]=='B')
                val[i]=2;  //'B'
            else if(s[i][1]=='B')
                val[i]=3; //'AB'
            else
                val[i]=1; //'A'
            if(val[i]!=-1)
            {
                if(s[i][1]=='+'||s[i][2]=='+')
                    val[i]+=4; //区分'+'和'-' 参见上面的mp
            }
        }
        top=0;  //top为可能数
        //父亲血型未知
        if(val[1]==-1)
        {
            //关键算法
            for(int c=0; c<8; c++) //奇数含A 偶数含B 也可以包括0！ 非常的重要的判断血型的代码
                //分别是 AB AB B A O自然成立
                if(((mp[c]&1)|(val[2]&2))==val[3]%4||((mp[c]&2)|(val[2]&1))==val[3]%4||((mp[c]&2)|(val[2]&2))==val[3]%4||((mp[c]&1)|(val[2]&1))==val[3]%4) //ABO判断
                {
                    if(mp[c]<4&&val[2]<4&&val[3]>=4) //Rh判断   由于'-'不可能产生'+' 所以cnotinue
                        continue;
                    stk[++top]=mp[c];
                }
            outp();
            printf(" %s %s",s[2],s[3]);
        } //以下同理
        //母亲血型未知
        else if(val[2]==-1)
        {
            for(int c=0; c<8; c++)
                if(((mp[c]&1)|(val[1]&2))==val[3]%4||((mp[c]&2)|(val[1]&1))==val[3]%4||((mp[c]&2)|(val[1]&2))==val[3]%4||((mp[c]&1)|(val[1]&1))==val[3]%4)
                {
                    if(mp[c]<4&&val[1]<4&&val[3]>=4)
                        continue;
                    stk[++top]=mp[c];
                }
            printf("%s ",s[1]);
            outp();
            printf(" %s",s[3]);
        }
        //孩子血型未知
        else
        {
            for(int c=0; c<8; c++)
                if(((val[2]&1)|(val[1]&2))==mp[c]%4||((val[2]&2)|(val[1]&1))==mp[c]%4||((val[2]&2)|(val[1]&2))==mp[c]%4||((val[2]&1)|(val[1]&1))==mp[c]%4)
                {
                    if(val[2]<4&&val[1]<4&&mp[c]>=4)
                        continue;
                    stk[++top]=mp[c];
                }
            printf("%s %s ",s[1],s[2]);
            outp();
        }
        puts("");
    }
    return 0;
}
//巧妙在运用二进制来判断
//非常的重要的判断血型的代码
