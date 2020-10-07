#include <iostream> //"#"����Ԥ��������
#include<cstring>
#include<fstream>//��дͷ�ļ�
#include<time.h>
#include"astar.h"
#include"jps.h"
using namespace std;    //ʹ��standard�����ռ�


int main(){
    int height = 100;
    int width = 100;

    int start_x =1,start_y =1;
    int end_x   =1,end_y  =9;
    cout<<"��ͼ�ߴ磨height*width��: "<<height<<"*"<<width;
    cout<<endl<<"��ʼ�㣨y��x����"<<start_x<<","<<start_y<<endl;
    cout<<"�����㣨y��x����"<<end_x<<","<<end_y<<endl;

    time_t time_start_ms,time_end_ms;//ʱ���¼ms

    //��ȡ��ͼ
    string filepath="/Users/halxp/Desktop/test3/JPS/map/map100x100_small.txt";
    ifstream fin(filepath.c_str());
    if(!fin)
    {
        cout<<endl<<"�ļ�������"<<endl;
        //system("pause");
    }

    int **pMap;//��ͼ��άָ������
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

    time_start_ms = clock();//JpsPruneѰ·��ʼʱ��

    jps.Init(pMap, height, width);

    jps.FindPath(jStart, jEnd);

    time_end_ms = clock();//JpsPruneѰ·����ʱ��
    cout<<"JpsѰ·ʹ��ʱ�䣺"<<difftime(time_end_ms, time_start_ms)<<"ms";
    jps.PrintRoute();
    jps.PrintAllRoute();
    cout<<"------------��·-----------------"<<"\n";
    jps.UpdateMap();
    jStart = {end_x,end_y};
    jEnd = {start_x,start_y};
    jps.FindPath(jStart, jEnd);
    jps.PrintRoute();
    jps.PrintAllRoute();

    return 0;
}
