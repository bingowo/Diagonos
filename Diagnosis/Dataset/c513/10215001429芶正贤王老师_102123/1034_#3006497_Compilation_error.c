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
        
        
        char s[len];
        scanf("%s",s);
        int len = strlen(s);        //字符个数
        DATA tests[len];             //定义结构体数组
        
        for(j=0;j < len;j++)
        {
            tests[j].charrr = s[j];
            int tmp,temp;
            tmp  = ( tests[j].charrr - 'A' );
            temp = ( tests[j].charrr - 'a' );
            if(tmp < 28) //大写字母
                tests[j].ans = freq[tmp] ;
            else         //小写字母
                tests[j].ans = freq[temp] ;
        }
          
        printf("case #%d:\n",index);
        
        qsort(tests, len , sizeof(DATA) , cmp);  
        
        for(r=0;r<len-1;r++)
            printf("%c",tests[r].charrr);
        
        printf("%c\n",tests[len-1].charrr);
        
    }
    
    return 0;
}