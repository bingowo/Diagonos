#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        printf("case #%d:\n",cas);
        char oct[100], dec[200];
        scanf("%s",oct);
        int len=strlen(oct);//例：0.0123456的len=9
        for(int i=len; i<100; i++)
            oct[i]='0';//初始化oct
        int start;//获取oct中小数点后第一个非零数的位置
        for(int i=2; i<len; i++)
        {
            if(oct[i]!='0')
            {
                start=i;
                break;
            }
        }//例：0.0123456的start=3
        if(start>2)
        {
            printf("0.");
            for(int i=0; i<start-2; i++)
                printf("0");
        }
        else
            printf("0.");
        int digit=oct[start]-'0';//记录oct的当前位（初始值为首非零数）
        int j=0;//对应dec的位数
        for(int i=start+1; i<100; i++) //终止条件并不是i<len，要补0
        {
            digit=digit*10+oct[i]-'0';
            dec[j]=digit/8;
            j++;
            digit%=8;
            if(digit==0)
                break;
        }
        for(int i=0; i<j; i++)
            printf("%d",dec[i]);
        printf("\n");
    }
}
