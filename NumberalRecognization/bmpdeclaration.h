#ifndef BMPDECLARATION_H_INCLUDED
#define BMPDECLARATION_H_INCLUDED


typedef unsigned short   WORD;                  //数据类型名称替换1
typedef unsigned long    DWORD;                 //数据类型名称替换2
typedef long             LONG;                  //数据类型名称替换3
typedef unsigned char    BYTE;                  //数据类型名称替换4

typedef struct tagBITMAPFILEHEADER             //位图头部分信息
{
    WORD    bfType;                         //类型
    DWORD   bfSize;                         //文件大小
    WORD    bfReserved1;                    //保留字1
    WORD    bfReserved2;                    //保留字2
    DWORD   bfOffBits;                      //偏移量
} BITMAPFILEHEADER;                         //结构体名称替换

typedef struct tagBITMAPINFOHEADER        //位图图像头信息
{
    DWORD      biSize;                  //图像大小
    LONG       biWidth;                 //图像宽度
    LONG       biHeight;                //图像高度
    WORD       biPlanes;
    WORD       biBitCount;              //位数
    DWORD      biCompression;
    DWORD      biSizeImage;             //图像大小
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;               //使用的颜色
    DWORD      biClrImportant;
} BITMAPINFOHEADER;                     //结构体名称替换

typedef struct tagRGBQUAD               //调色板
{
    BYTE    rgbBlue;                    //蓝色值
    BYTE    rgbGreen;                   //绿色值
    BYTE    rgbRed;                     //红色值
    BYTE    rgbReserved;
} RGBQUAD;                              //结构体名称替换



#endif // BMPDECLARATION_H_INCLUDED

