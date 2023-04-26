#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define ll long long
#define ull unsigned long long
#define N 1010

typedef struct pair
{
    ull key;         // 键
    char element[N]; // 数据类型--->字符串类型
} DATA, *LPDATA;

typedef struct hashTable
{
    LPDATA *table; // 数据用二级指针表示 便于初始化，以及判断当前hash地址是否存在冲突
    int divisor;   // H(key)=key%p -->就是限定hash地址的数目 数据要%p需要传入p
    int curSize;   // 当前元素个数
} HASH, *LPHASH;

LPHASH createHashTable(int p)
{
    LPHASH hash = (LPHASH)malloc(sizeof(HASH)); // 动态内存申请
    assert(hash);
    // 给数据做初始化
    hash->curSize = 0;
    hash->divisor = p;
    hash->table = (LPDATA *)malloc(sizeof(LPDATA) * hash->divisor); // 容量由取余数决定
    assert(hash->table);
    for (int i = 0; i < hash->divisor; i++) // 多个一级指针
    {
        hash->table[i] = NULL; // 二级指针申请内存后给每个一级指针做初始化
    }
    return hash;
}

// 要找的表 传入键
int search(LPHASH hash, ull key)
{
    int pos = key % hash->divisor; // 不存在冲突的hash地址 正常情况
    int curPos = pos;              // 存在冲突 开放地址法做哈希地址的查找
    do
    {
        // key相同，采用覆盖的数据方式 不当做哈希冲突来做
        if (hash->table[curPos] == NULL || hash->table[curPos]->key == key)
            return curPos;                     // 判断当前位置能不能用 ==NUll说明可以用
        curPos = (curPos + 1) % hash->divisor; // 不为NULL往后走 如果后面为NULL就插到当前位置
    } while (curPos != pos);                   // 当前Pos不等于原来Pos就一直去做查找
    return curPos;
}
//!= 原来地址一直做查找
//== 原来地址:找完一圈后回到原来的位置说明它没有合适的位置 直接返回

void insertData(LPHASH hash, DATA data)
{
    // 做插入前先求hash地址--->调用哈希函数                  //不存在哈希冲突
    int pos = search(hash, data.key); // 找到要存储数据的哈希地址
    if (hash->table[pos] == NULL)     // 当前下标没有数据 直接插入
    {
        hash->table[pos] = (LPDATA)malloc(sizeof(DATA)); // 注意先申请内存再拷贝元素
        memcpy(hash->table[pos], &data, sizeof(DATA));   // 内存拷贝
        hash->curSize++;
    }
    else // 存在哈希冲突
    {
        if (hash->table[pos]->key == data.key) // 键相同回到原来位置
        {
            strcpy(hash->table[pos]->element, data.element); // 用覆盖元素的方式
        }
        else // 键不同回到原来位置说明满了
        {
            printf("hash表满了,无法插入!\n");
            // return;
        }
    }
}

void printHash(LPHASH hash)
{
    for (int i = 0; i < hash->divisor; i++) // 用最大容量长度做打印
    {
        if (hash->table[i] == NULL)
        {
            // printf("NULL\n");
        }
        else // 不为空打印元素
        {
            printf("%llu:%s\n", hash->table[i]->key, hash->table[i]->element);
        }
    }
}

int cmp(const void *a, const void *b)
{
    return strcmp(*(char *)a, *(char *)b);
}

int main()
{
    int T, m = 0;
    scanf("%d\n", &T);
    // getchar();
    while (T--)
    {
        printf("case #%d:\n", m++);
        char ss[N], tmp[N];
        gets(ss);
        int len = strlen(ss);
        for (int i = 0; i < len; i++)
            if (!isalpha(ss[i]))
                ss[i] = ' ';

        // static char whitespace[] = " \t\n\v\f\r";
        LPHASH hash = createHashTable(N * 2);
        DATA arr[N];
        char delims[] = " ";
        char *token = strtok(ss, delims);
        int k = 0;
        while (token != NULL)
        {
            char word[N];
            strcpy(word, token);
            char *p = word;
            ull sum = 0;
            while (*p)
            {
                sum += (int)*p;
                sum *= 29;
                p++;
            }
            // printf("%llu ", sum);
            arr[k].key = sum; 
            strcpy(arr[k].element, token);
            insertData(hash, arr[k]);
            token = strtok(NULL, delims);
            k++;
        }
        // printf("\n");
        // printHash(hash);
        char res[N][N];
        int cnt = 0;
        for (int i = 0; i < hash->divisor; i++) // 用最大容量长度
        {
            if (hash->table[i] != NULL)
                strcpy(res[cnt++], hash->table[i]->element);
        }
        qsort(res, cnt, sizeof(res[0]), cmp);
        for (int i = 0; i < cnt; i++)
        {
            printf("%s", res[i]);
            if (i != cnt - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}