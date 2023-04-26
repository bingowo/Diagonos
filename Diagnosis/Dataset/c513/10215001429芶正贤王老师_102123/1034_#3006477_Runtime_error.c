#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    double ans;
    char charrr;
}DATA;

double cmp(const void *a , const void *b)
{     //频率降序，ascii降序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    
    if(x->ans != y->ans)
        return (x->ans - y->ans);
    else
        return ( (x->charrr) - (y->charrr) );
}

int main()
{
    int T;
    scanf("%d",&T);            //输入问题数
    
    int index,i,j,r;
    
    for(index = 0;index < T;index++)  //第index个问题
    {
        double freq[26];
        for(i = 0;i<26;i++)
            scanf("%lf",&freq[i]);
        //读入字母的频率
        
        DATA tests[120];             //定义结构体数组
        
        j = 0;
        while(  scanf("%c",tests[j].charrr) != EOF  )
        {
            
            int tmp;
            int temp;
            tmp  = ( tests[j].charrr - 'A' );
            temp = ( tests[j].charrr - 'a' );
            if(tmp < 30) //大写字母
                tests[j].ans = freq[tmp] ;
            else         //小写字母
                tests[j].ans = freq[temp] ;
            
            j++;
        }
        
        int len = i;        //字符个数
      
        printf("case #%d:\n",index);
        
        qsort(tests, len , sizeof(DATA) , cmp);  
        
        for(r=0;r<len-1;r++)
            printf("%c",tests[r].charrr);
        
        printf("%c\n",tests[len].charrr);
        
    }
    
    return 0;
}