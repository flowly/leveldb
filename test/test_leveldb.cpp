/**
 * @file   test_leveldb.cpp
 * @author donzell <donzell.wu@gmail.com>
 * @date   Sat Jun  8 23:54:36 2013
 * 
 * @brief  测试leveldb，gdb跟踪代码用的。
 * 
 * 
 */
#include "leveldb/db.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status s = leveldb::DB::Open(options, "./testdb", &db);
    if(!s.ok()){
        cerr<<s.ToString()<<endl;
        return -1;
    }
    string key1("hello");
    string key2("world");
    std::string value;
    for(int i=0;i<10240;i++){
        value += "this_is_test_value";
    }
    
    s = db->Get(leveldb::ReadOptions(), key1, &value);
    if(!s.ok()){
        cerr<<s.ToString()<<endl;
    }

    for(int i=0;i<1024;i++){
        s = db->Put(leveldb::WriteOptions(), key2, value);
    }
    
    s = db->Delete(leveldb::WriteOptions(), key1);
    if(!s.ok()){
        cerr<<s.ToString()<<endl;
    }
    
    delete db;
    return 0;

}
