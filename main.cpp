#include <iostream>
#include "json/Json.h"
#include "json/Parser.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace json;

int main() {
//单独数据类型
//    Json v1;
//    Json v2 = true;
//    Json v3 = 123;
//    Json v4 = 1.23;
//    Json v5 = "hello world";
//
//    bool b = v2;
//    int i = v3;
//    double d = v4;
//    const string & s = v5;
// 数组
//    Json arr;
//    arr[0] = true;
//    arr[1] = 123;
//    arr[2] = 1.23;
//
//    arr.append("hello, world");
//    std::cout<<arr.str()<<std::endl;
//
//    bool b = arr[0];
//    int i = arr[1];
//    double f = arr[2];
//    const string & s = arr[3];
// 对象

//    Json obj;
//    obj["bool"] = true;
//    obj["int"] = 123;
//    obj["double"] = 1.23;
//    obj["str"] = "hello, world";
//
//    std::cout<< obj.str()<<std::endl;

//    Json arr;
//    arr[0] = true;
//    arr[1] = 123;
//    arr[2] = 1.23;
//    arr[3] = "hello,world";
////    for(auto it = arr.begin() ; it!= arr.end(); it++){
////        std::cout<<(*it).str()<<std::endl;
////    }
//    std::cout<< arr.has(0)<<std::endl;
//    std::cout<< arr.has(4)<<std::endl;
//    arr.remove(0);
//    std::cout<< arr.str()<<std::endl;

//     ifstream fin("test.json");
//     stringstream ss;
//     ss << fin.rdbuf();
//     const string & data = ss.str();
//     Json v;
//     v.parse(data);
//     std::cout << v.str() << std::endl;


    try{
        ifstream fs("test.json");
        stringstream ss;
        ss<<fs.rdbuf();
        const string & data = ss.str();
        Json json1;
        json1.parse(data);
        cout<<json1.str()<<endl;
        json1["age"] = 20;
        cout<<json1.str()<<endl;
        json1.clear();
    }
    catch (exception & e){
        cout<<"catch exception" <<e.what()<<endl;
    }
    return 0;
}
