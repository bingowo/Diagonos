#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char data[11];
    char time[6];
    int size;
    char id[64];
}file;

char sortType[5];   //排序命令

int cmp(const void *_a, const void *_b){
    file a = *(file *)_a;
    file b = *(file *)_b;
    if (strcmp(sortType, "SIZE") == 0){
        //大小升序
        if (a.size != b.size)
            return a.size - b.size;
    }else if (strcmp(sortType, "TIME")){
        //时间升序
        if (strcmp(a.time, b.time) != 0)
            return strcmp(a.time, b.time);
    }
    //名称字典序排序
    return strcmp(a.id, b.id);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0){
        file a[n];
        int i;
        //输入
        for (i = 0; i < n; i++)
            scanf("%s%s%d%s", a[i].data, a[i].time, a[i].size, a[i].id);
        //格式
        scanf("LIST /%s", sortType);

        qsort(a, n, sizeof(a[0]), cmp);
        //输出
        for (i = 0; i < n; i++)
            printf("%s %s %d %s\n", a[i].data, a[i].time, a[i].size, a[i].id);
        printf("\n");

        //新的一组数据
        scanf("%d", &n);
    }
    return 0;
}