#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[100];
    int size;
    int year, month, day, hour, min;
}file;

int compare1(const void *p1, const void *p2){
    file file1 = *(file*) p1;
    file file2 = *(file*) p2;
    return file1.size - file2.size; 
}

int compare3(const void *p1, const void *p2);
int compare2(const void *p1, const void *p2){
    file file1 = *(file*) p1;
    file file2 = *(file*) p2;
    int res;
    if (file1.year == file2.year){
        if (file1.month == file2.month){
            if (file1.day == file2.day){
                if (file1.hour == file2.hour){
                    if (file1.min == file2.min)
                        return compare3(p1, p2);
                    return file1.min - file2.min;  
                }
                return file1.hour - file2.hour;
            }
            return file1.day - file2.day;
        }
        return file1.month - file2.month;
    }
    return file1.year - file2.year;
}

int compare3(const void *p1, const void *p2){
    return strcmp(((file*)p1)->name, ((file*)p2)->name);
}

void output(file* files, int len){
    for (int i = 0; i != len; i++)
        printf("%04d-%02d-%02d %02d:%02d %16d %s\n", files[i].year, files[i].month, files[i].day,
                                                   files[i].hour, files[i].min, files[i].size, files[i].name);

    printf("\n");
}

void sort(file *files, char *way, int len){
    if (strcmp(way, "/SIZE") == 0) qsort(files, len, sizeof(files[0]), compare1);
    else if (strcmp(way, "/TIME") == 0) qsort(files, len, sizeof(files[0]), compare2);
    else qsort(files, len, sizeof(files[0]), compare3);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n != 0){
        file *files = (file*) malloc(sizeof(file) * n);
        for (int i = 0 ; i != n; i++)
            scanf("%d-%d-%d%d:%d%d%s", &files[i].year, &files[i].month, &files[i].day,
                                    &files[i].hour, &files[i].min, &files[i].size, files[i].name);
        char garba[6], way[6];
        scanf("%s %s", garba, way);
        sort(files, way, n);
        output(files, n);
        free(files);
        scanf("%d", &n);
    }
    return 0;
}