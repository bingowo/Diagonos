#include <stdio.h>
#include <string.h>

//ZERO ONE TWO THREE FOUR FIVE SIX SEVEN EIGHT NNE 
//zxsvfwgoir利用这些字母来确定数字 
//只有ZERO中有'Z',只有SIX中有'X',计算出SIX的个数后，丢掉SIX,此时只有SEVEN中有'S';
//计算出SEVEN的个数，此时只有FIVE中有'V';计算出FIVE的个数，只有FOUR中有'F',..... 
int table[30];//table[]内存储整数,table[0]表示'A'的个数...table[1]表示B的个数 .....table[25]表示Z的个数  
int num[11];//num[0]存储0的个数,num[1]存储1的个数.....num[9]存储9的个数 
int main()
{
    int cases = 0;
    scanf("%d",&cases);
    char str[256];

    for (int ca = 0 ; ca < cases ; ++ca){
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++){
            table[str[i]-'A']++;
        }
        int tmp;
        //zxsvfwgoir   0  zro
        tmp=table['Z'-'A'];//tmp表示Z的个数 ,只有ZERO中有'Z'，tmp表示0的数量 
        table['O'-'A']-=tmp;
        table['R'-'A']-=tmp;
        num[0]=tmp;
        //xsvfwgoir   6  xsi
        tmp=table['X'-'A'];
        table['S'-'A']-=tmp;
        table['I'-'A']-=tmp;
        num[6]=tmp;
        //svfwgoir   7  sv
        tmp=table['S'-'A'];
        table['V'-'A']-=tmp;
        num[7]=tmp;
        //vfwgoir   5  vfi
        tmp=table['V'-'A'];
        table['F'-'A']-=tmp;
        table['I'-'A']-=tmp;
        num[5]=tmp;
        //fwgoir   4  for
        tmp=table['F'-'A'];
        table['O'-'A']-=tmp;
        table['R'-'A']-=tmp;
        num[4]=tmp;
        //wgoir   2  wo
        tmp=table['W'-'A'];
        table['O'-'A']-=tmp;
        num[2]=tmp;
        //goir   8  gi
        tmp=table['G'-'A'];
        table['I'-'A']-=tmp;
        num[8]=tmp;
        //oir   1  o
        tmp=table['O'-'A'];
        num[1]=tmp;
        //ir   9  i
        tmp=table['I'-'A'];
        num[9]=tmp;
        //r 3    r
        tmp=table['R'-'A'];
        num[3]=tmp;
        printf("case #%d:\n",ca);
        for(int j=0;j<10;j++){
            for(int t=0;t<num[j];t++){
                printf("%d",j);
            }
        }
        printf("\n");
        memset(table,0,sizeof(table));
        memset(num,0,sizeof(num));
    }
}