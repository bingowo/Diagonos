#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long long cnt;
    int flag;
    char s[105];
}number;

int cmp(const void* a, const void* b)
{
    number p = *(number*)a, q = *(number*)b;
    int i1 = p.flag;
    int i2 = q.flag;
    if(p.cnt != q.cnt)
    {
        if(p.cnt >= q.cnt)
            return 1;
        return -1;
    }
    if(p.cnt == q.cnt)
    {
        if(i1 != i2)
            return i2 - i1;
        while(p.s[i1] != q.s[i1])
            i1++;
        if(p.cnt >= 0)
        {
            
        }
        
        
    }
    
    
    
    
}


int main()
{
    

    return 0;
}
