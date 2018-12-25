#ifndef BMPIMAGE_H
#define BMPIMAGE_H

//#include "bmpdeclaration.h"
#include <windows.h>
#include <string>

class bmpImage
{
    friend class BPNeuralNetwork;
    friend class mvector;
    friend class dataset;
public:
    bmpImage() :pImageBody(0),pColorTable(0) {}             //构造函数
    ~bmpImage();            //析构函数
    bool readImage(std::string name);           //读取图片
public:
    BITMAPFILEHEADER fileHead;                 //用于读取文件头
    BITMAPINFOHEADER imageHead;                  //用于读取图像信息头
    double*			pImageBody;                  //图像信息
    unsigned char* pColorTable;						//调色板
    std::string		imageName;                       //图像名称
};

#endif // BMPIMAGE_H
