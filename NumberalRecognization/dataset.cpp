#include "dataset.h"
#include <fstream>
#include <iostream>
using namespace std;

bool dataset::readData(string ad, string fileName, int n, bool labelAns,int start)        //读取数据,ad为地址目录，fileName为前缀
{
    totalNum = n;
    /*lable = mvector(n);
    readLable(ad+"t10k-labels.idx1-ubyte",n);*/
    numOfSet = 1;
    data = new imageSet[2];
    data[1].sizeOfPerSet = n;
    data[1].List = new imageEle;        //设定头指针
    imageEle* plast = data[1].List;

    for (int i = 0; i<n; ++i)           //对于这n个图像，若非label其期望输出均为文件名数字对10取余
    {
        char num[10];
        sprintf(num, "%d.bmp",labelAns? start+i+1:start+i);
        plast->expOutput = labelAns?(int)lable[start+i]:start+i%10;            //设定期望输出
        string tt(ad + fileName + num);
        if(!plast->imageInfo.readImage(tt))   //读取文件
        {
            plast->pNext = NULL;
            return false;
         }
        if (i < n - 1)
        {
            plast->pNext = new imageEle;                //逐步构造链表
            plast = plast->pNext;                       //移动标志指针
        }
    }
    plast->pNext = 0;           //设定尾为0
    return true;
}

void dataset::shuffle(int n)            //将数据分为n组
{
    numOfSet = n;
    int perSize = data[1].sizeOfPerSet / n;
    int lastSize = data[1].sizeOfPerSet%n;

    imageSet* newSetptr = new imageSet[n + 1];
    imageEle* localptr = data[1].List;
    for (int i = 1; i<n; ++i)                //前n-1个集合的设置
    {
        newSetptr[i].List = new imageEle;
        newSetptr[i].List->pNext = localptr;
        newSetptr[i].sizeOfPerSet = perSize;
        for (int j = 1; j <= perSize; ++j)
            localptr = localptr->pNext;
        imageEle* temp = localptr;
        localptr = localptr->pNext;
        temp->pNext = NULL;
    }

    newSetptr[n].List = localptr;           //设置最后一个图像
    newSetptr[n].sizeOfPerSet = lastSize;
    for (int j = 1; j <= lastSize; ++j)
        localptr = localptr->pNext;
    imageEle* temp = localptr;
    localptr = localptr->pNext;
    temp->pNext = NULL;
    delete[]data;
    data = newSetptr;                   //设置当前数据指针为新集合指针
}

dataset::~dataset()             //析构函数
{
    for (int i = 1; i <= numOfSet; ++i)
    {
        imageEle* localptr = data[i].List;
        imageEle* lastptr = localptr;
        while (localptr != NULL)
        {
            localptr = localptr->pNext;
            delete lastptr;
            lastptr = localptr;
        }
    }

}

void dataset::setEpoch(int n)           //设置总的训练次数
{
    totalEpoch = n;
}

bool dataset::readLable(string ad,int n,int start)				//读取数据集的期望输出值
{
    n += start;
    lable = mvector(n);
    ifstream file(ad, ios::binary);
    if (file.is_open())
    {
        int magic_number = 0;
        int number_of_images = 0;
        file.read((char*)&magic_number, sizeof(magic_number));
        file.read((char*)&number_of_images, sizeof(number_of_images));
        magic_number = ReverseInt(magic_number);
        number_of_images = ReverseInt(number_of_images);
        for (int i = 0; i < n; i++)
        {
            unsigned char label = 0;
            file.read((char*)&label, sizeof(label));
            lable[i] = label;
        }
        file.close();
    }
    else
        return false;
    return true;
}

int dataset::ReverseInt(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
