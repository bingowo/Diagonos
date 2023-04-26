#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    double ans;
    char array;
}DATA;

double cmp(const void *a , const void *b)
{     //频率降序，ascii降序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    
    if(x->ans != y->ans)
        return (x->ans - y->ans);
    else
        return ( ((x->array)-'A') - ((y->array)-'A') );
}

int main()
{
    int T;
    scanf("%d",&T);            //输入问题数
    
    int index,i,j,r;
    
    double freq[26];
    
    for(index = 0;index < T;index++)  //第index个问题
    {
        DATA tests[100];             //定义结构体数组
        
        for(i = 0;i<26;i++)
            scanf("%lf",&freq[i]);
        //读入字母的频率
        
        i = 0;
        while(  scanf("%c",tests[i].array) != EOF  )
        {
            
            int tmp;
            int temp;
            tmp  = ( tests[i].array - 'A' );
            temp = ( tests[i].array - 'a' );
            if(tmp < 30) //大写字母
                tests[i].ans = freq[tmp] ;
            else         //小写字母
                tests[i].ans = freq[temp] ;
            
            i++;
        }
        
        int N = i;
      
        printf("case #%d:\n",index);
        
        qsort(tests, N , sizeof(DATA) , cmp);  
        
        for(r=0;r<N-1;r++)
            printf("%s",tests[r].array);
        
        printf("%s\n",tests[N].array);
        
    }
    
    return 0;
}