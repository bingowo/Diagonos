#include <stdio.h>

char toput[1000] = {0};
long long to_trans[33] = {0};//你需要转化的数据
int base[33] = {0};//进制
char Alpha[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};//十一进制转化

int main()
{
    int total, num, order;
    scanf("%d",&total);
    for(int i = 0; i < total; i++)
        {
            scanf("%d",&num);
            to_trans[i] = num;
            scanf("%d",&order);
            base[i] = order;
        }
    for(int i = 0; i < total; i++)
    {
        int length = 0;//转化之后的长度
        int nega = 0;
        if(to_trans[i] < 0)
        {
            nega = 1;
            to_trans[i] = 0 - to_trans[i];
        }
        while(to_trans[i])
        {

            int each_num = to_trans[i] % base[i];
            to_trans[i] /= base[i];
            toput[length++] = each_num;

        }
        if (nega)
        {
            printf("-");
        }
        for(int j = length - 1; j >= 0; j--)
        {
            printf("%c",Alpha[toput[j]]) ;
        }
        printf("\n") ;
    }

    return 0;

}
