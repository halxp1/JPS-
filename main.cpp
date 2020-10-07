#include <iostream> //"#"代表预处理命令
#include<cstring>
#include<fstream>//读写头文件
#include<time.h>
#include"astar.h"
#include"jps.h"
using namespace std;    //使用standard命名空间


int main(){
    int height = 100;
    int width = 100;

    int start_x =1,start_y =1;
    int end_x   =1,end_y  =9;
    cout<<"地图尺寸（height*width）: "<<height<<"*"<<width;
    cout<<endl<<"开始点（y，x）："<<start_x<<","<<start_y<<endl;
    cout<<"结束点（y，x）："<<end_x<<","<<end_y<<endl;

    time_t time_start_ms,time_end_ms;//时间记录ms

    //读取地图
    string filepath="/Users/halxp/Desktop/test3/JPS/map/map100x100_small.txt";
    ifstream fin(filepath.c_str());
    if(!fin)
    {
        cout<<endl<<"文件不存在"<<endl;
        //system("pause");
    }

    int **pMap;//地图二维指针数组
    pMap = new int* [height];
    for(int i=0;i < height;i++){
        pMap[i] = new int[width];
        for(int j=0;j < width;j++){
            char c;
            fin>>c;
            if('.' == c) pMap[i][j] = 0;
            else pMap[i][j] = 1;
        }
    }

    cout<<"------------JPS---------------"<<"\n";
    Jps jps;
    Jps::PathNode jStart = {start_x,start_y};
    Jps::PathNode jEnd = {end_x, end_y};

    time_start_ms = clock();//JpsPrune寻路开始时间

    jps.Init(pMap, height, width);

    jps.FindPath(jStart, jEnd);

    time_end_ms = clock();//JpsPrune寻路结束时间
    cout<<"Jps寻路使用时间："<<difftime(time_end_ms, time_start_ms)<<"ms";
    jps.PrintRoute();
    jps.PrintAllRoute();
    cout<<"------------回路-----------------"<<"\n";
    jps.UpdateMap();
    jStart = {end_x,end_y};
    jEnd = {start_x,start_y};
    jps.FindPath(jStart, jEnd);
    jps.PrintRoute();
    jps.PrintAllRoute();

    return 0;
}
