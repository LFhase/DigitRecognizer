
#include "mvector.h"
#include <cstring>

#include <iostream>

using namespace std;

double operator* ( mvector& v1,  mvector& v2)        //向量点乘
{
    int len = v1.len<v2.len ? v1.len : v2.len;
    double re = 0;
    while (len)
    {

        re += v1[len] * v2[len];
    //	cout << v1[len] << " " << v2[len] << " " << re << endl;
        len--;

    }
    return re;
}

mvector::mvector(int n)         //构造函数
{
    len = n;
    data = new double[n + 1];
    while (n)  data[n--] = 1;
}

mvector::mvector()             //默认构造函数
{
    data = 0;
    len = 0;
}

mvector::mvector(const mvector& v)      //复制构造函数
{
    if (v.data == 0) { data = 0; len = 0; }
    else
    {
        int temp = v.len;
        data = new double[temp + 1];
        len = temp;
        while (temp)
        {
            data[temp] = v.data[temp];
            temp--;
        }
    }

}

mvector::mvector(bmpImage& image)       //类型转换构造函数
{
    data = new double[image.imageHead.biSizeImage + 1];
    len = image.imageHead.biSizeImage;
    //double ttt[785];
    for (unsigned int i = 1; i <= image.imageHead.biSizeImage; ++i)
    {
        //ttt[i] = image.pImageBody[i - 1];
        data[i] = image.pImageBody[i - 1];
        //ttt[i] = data[i];
    }
}

mvector::~mvector()             //析构函数
{
    if (data!=NULL)  delete[]data;
     data = 0;
}

mvector& mvector::operator* (double num)         //向量数乘
{
    for (int i = 1; i <= len; ++i)
        data[i] *= num;
    return *this;
}

mvector& mvector::operator = (const mvector& v)           //赋值函数
{
    if (v.data == this->data)  return *this;
    if (v.data == 0) { this->data = 0;   return *this; }
    if (data != 0) delete[]data;

    len = v.len;
    int temp = v.len;
    data = new double[temp + 1];
    while (temp)
    {
        data[temp] = v.data[temp];
        temp--;
    }
    return *this;
}

double mvector::operator * (bmpImage& imageVector)       //向量与图像向量乘法
{
    double re = 0;
    for (int i = 1; i <= len; ++i)
        re += imageVector.pImageBody[i-1] * data[i];
    return re;
}

double& mvector::operator[] (int i)const                  //下标访问
{
    return data[i];
}

int mvector::getLen()           //访问其长度
{
    return len;
}

void mvector::initialize()          //将向量数据全部置为0
{
    for (int i = 0; i <= len; ++i)
        data[i] = 0;
}
