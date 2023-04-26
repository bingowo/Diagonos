 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 typedef struct {
    char stnum[12]; 
 int sum; 
    int score; 
 } Student;
 int cmp(const void* a, const void* b) {
    Student pa = *(Student*)a;
    Student pb = *(Student*)b;
    if (pa.score != pb.score) { 
        return pb.score - pa.score;
   }
    else { 
        return strcmp(pa.stnum, pb.stnum);
   }
 }
 int main() {
    int t; 
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, m, g;
        scanf("%d %d %d", &n, &m, &g);
        int point[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &point[j]);
       }
        Student s[n];
        int count = 0; 
        for (int k = 0; k < n; k++) {
            scanf("%s %d", s[k].stnum, &s[k].sum);
            s[k].score = 0;

            for (int l = 0; l < s[k].sum; l++) {
                int t;
                scanf("%d", &t);
                if (t > 0) { 
          s[k].score += point[t-1];
               }
           }
            if (s[k].score >= g) { 
                count++;
           }
       }
        qsort(s, n, sizeof(Student), cmp);
        printf("case #%d:\n", i);
        printf("%d\n", count); 
        for (int k = 0; k < n; k++) {
            if (s[k].score >= g) { 
                printf("%s %d\n", s[k].stnum, s[k].score);
           }
       }
   }
    return 0;
 }