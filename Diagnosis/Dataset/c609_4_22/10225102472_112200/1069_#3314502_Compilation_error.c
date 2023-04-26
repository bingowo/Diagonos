#ifndef PAPERLESS_H_INCLUDED 
#define PAPERLESS_H_INCLUDED

#include<bits/stdc++.h>

class paperless{
public:
    map<int,map<string, string>> work; // 定义一个 map，键为作业编号，值为另一个 map，其键为学生 ID，值为学生提交的代码
    class bad_paperless{ // 定义一个 bad_paperless 类，用于抛出异常
    public:
        exception a;
    };
    void submit(string id,int assignNo,string code){
        work[assignNo][id] = code; // 将学生提交的代码存储在 work 中
    }
    void discard(string id,int assignNo){ // 删除学生提交的作业
        if(work[assignNo].find(id) == work[assignNo].end()) // 如果找不到学生提交的作业
            throw bad_paperless{}; // 抛出 bad_paperless 异常
        else // 否则
            work[assignNo].erase(id); // 删除学生提交的作业
    }
    int count(int assignNo){ // 统计某次作业的提交人数
        return work[assignNo].size();
    }
};
#endif