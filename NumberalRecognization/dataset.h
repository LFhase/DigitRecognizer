#ifndef DATASET_H
#define DATASET_H

#include "mvector.h"
#include "bmpImage.h"
#include <string>

typedef struct imageEle         //图像信息链表节点
{
    bmpImage    imageInfo;      //图像信息
    int         expOutput;      //期望输出
    imageEle*   pNext;          //指针域
}*imageList;
struct imageSet
{
    imageList List;     //集合数据
    int sizeOfPerSet;       //集合元素个数
};
class dataset
{
    friend class BPNeuralNetwork;
public:
    dataset() = default;              //构造函数
    ~dataset();             //析构函数
    void setEpoch(int n);           //设置总的训练次数
    bool readData(std::string ad, std::string fileName, int n, bool labelAns,int start=0);
    //读取数据,ad为地址目录，fileName为前缀
    void shuffle(int n);            //将数据分为n组
    bool readLable(std::string ad, int n,int start=0);
    //读取数据集的期望输出值
private:
    int  ReverseInt(int i);			//转换
public:
    imageSet* data;         //全部数据
    int  numOfSet;          //数据中集合的个数
    int  totalNum;			//数据中元素的个数
    int  totalEpoch;        //总的训练次数
    double  studyRate;		//指定学习率
    mvector lable;			//对应的图片的期望输出
};

#endif // DATASET_H
