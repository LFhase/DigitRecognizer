#ifndef MVECTOR_H
#define MVECTOR_H

#include "bmpImage.h"

class mvector
{
    friend double operator * ( mvector& v1,   mvector& v2);         //向量点乘
public:
    mvector();
    mvector(int n);         //构造函数
    mvector(bmpImage& image);       //类型转换构造函数
    mvector(const mvector& v);      //复制构造函数
    ~mvector();             //析构函数
    int getLen();           //访问其长度
    void initialize();          //将向量数据全部置为0
    mvector& operator = (const mvector& v);           //赋值函数
    double& operator [] (int i)const;                  //下标访问
    double  operator * (bmpImage& imageVector);        //向量与图像向量乘法
    mvector& operator * (double num);                        //向量数乘
private:
    double* data;       //数据
    int len;             //长度
};

#endif // MVECTOR_H
