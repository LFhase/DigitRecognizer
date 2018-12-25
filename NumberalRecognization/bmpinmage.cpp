#include "bmpImage.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

bool bmpImage::readImage(string name)         //读取图片
{
    imageName = name;
    char* fileName = new char[name.length() + 1];
    for (unsigned int i = 0; i < name.length(); ++i)   fileName[i] = name[i];
    fileName[name.length()] = '\0';

    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL)			return false;
    fread(&fileHead.bfType, 1, 2, fp);                                                  //读取文件信息
    fread(&fileHead.bfSize, 1, 4, fp);
    fread(&fileHead.bfReserved1, 1, 2, fp);
    fread(&fileHead.bfReserved2, 1, 2, fp);
    fread(&fileHead.bfOffBits, 1, 4, fp);
    fread(&imageHead, sizeof(BITMAPINFOHEADER), 1, fp);
    unsigned int biSize = 0;
    unsigned int biWidth = 0;
    if (imageHead.biBitCount == 8)						//读取调色板信息
    {
        pColorTable = (unsigned char*)calloc(257, sizeof(RGBQUAD));
        fread(pColorTable, sizeof(RGBQUAD), 256, fp);
        biWidth = (imageHead.biWidth*imageHead.biBitCount / 8 + 3) / 4 * 4;
        biSize = biWidth * imageHead.biHeight;
    }
    unsigned char* tempP = new unsigned char[biSize + 1];
    double* reLoad = new double[biSize + 1];
    pImageBody = new double[biSize/16 + 1];
    fread(tempP, 1, biSize, fp);				//读取颜色信息
    for (int i = 1; i <= imageHead.biHeight; ++i)			//顺序读取行
        for (unsigned int j = 1; j <= biWidth; ++j)
            reLoad[(i - 1)*biWidth + j - 1] = (double)tempP[(imageHead.biHeight - i)*biWidth + j - 1] / 255.0;

    for (int i = 1; i <= imageHead.biHeight; i+=4)			//降维处理
    {
        double sum = 0;
        for (unsigned int j = 1; j <= biWidth; j+=4)
        {
            sum = 0;
            sum = reLoad[(i - 1)*biWidth + j - 1] + reLoad[(i - 1)*biWidth + j] + reLoad[(i - 1)*biWidth + j+1] + reLoad[(i - 1)*biWidth + j+2];
            sum += reLoad[i*biWidth + j - 1] + reLoad[i*biWidth + j] + reLoad[i*biWidth + j + 1] + reLoad[i*biWidth + j + 2];
            pImageBody[(i - 1)*biWidth / 16 + j / 4] = sum / 16.0;
        }
    }
    imageHead.biSizeImage /= 16;
    delete[]reLoad;
    delete []fileName;
    delete []tempP;
    fclose(fp);
    return true;
}

bmpImage::~bmpImage()            //析构函数
{
    if (pImageBody)  delete []pImageBody;
    if (pColorTable)	free(pColorTable);
}

