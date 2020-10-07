#include <iostream>
//#include<windows.h>
#include<vector>
#include<cmath>

using namespace std;
using std::vector;

class Astar
{
public:
    struct MyPoint{
        int row;//??
        int col;
        int g,h,f;
        void GetF(){
            f = g + h;
        }
    };
    //???????
    enum Direct{
        p_up,p_down,p_left,p_right,p_leftup,p_leftdown,p_rightup,p_rightdown
    };
    //??????????
    struct PathNode{
        int     value;//
        bool    isroute;//????????????��????
        bool    isfind;//??????
    };
    //??????????
    struct MyTreeNode{
        MyPoint pos;
        MyTreeNode* parent;
        vector<MyTreeNode*> child;//????????????��???��?????????????????
    };

    int VerticalDist; //??????????????10
    int ObliqueDist;  //????????��?????14

    int ROW,COL;//?????????????????
    int **map;//???????

    //???????????
    PathNode **pathMap;
    MyPoint beginPoint;
    MyPoint endPoint;

    MyTreeNode* beginTreeNode;//?????��????????????????

    //????????????????
    MyTreeNode* pTemp;//?????
    MyTreeNode* pTempChild;//????

    //????????????????
    vector<MyTreeNode*> openTree;//?????��?

    vector<MyTreeNode*>::iterator minF_Iter;//????????��f????��???????
    vector<MyTreeNode*>::iterator it;//??????????????

    vector<MyTreeNode*> retPath;//???????????

    //????????��????��???true
    bool isRoad(const MyPoint& point,PathNode **_pathMap){
        if(point.col <0 || point.col >= COL ||
           point.row <0 || point.row >= ROW
           )//???????
           return false;
        if(1 == _pathMap[point.row][point.col].value)//???????
            return false;
        if(_pathMap[point.row][point.col].isfind)//?????????
            return false;
        return true;
    }

    //?��??(row,col)?????????
    bool isBarrier(int row, int col, PathNode **_pathMap){
        if(col <0 || col >= COL ||
           row <0 || row >= ROW
           )//???????
           return true;
        if(1 == _pathMap[row][col].value)//???????
            return true;
        return false;
    }

    //????h?
    int GetH(const MyPoint& point,const MyPoint& endpos){
        int x = abs(point.col - endpos.col);//????????????
        int y = abs(point.row - endpos.row);//?????????????
        return (x + y)*VerticalDist;
    }

    void Init(int **_map,int height,int width,MyPoint _beginPoint,MyPoint _endPoint);
    void FindPath();
    void PrintRoute();
    void PrintRouteMap();

};