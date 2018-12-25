#ifndef BPNEURALNETWORK_H
#define BPNEURALNETWORK_H

#include "mvector.h"
#include "neuron.h"
#include "dataset.h"
#include <string>

class BPNeuralNetwork
{
    friend class recognizationUi;
public:
    BPNeuralNetwork(int inum=0,int hnum = 0, int onum = 0);    //构造函数hnum为隐藏层神经元数，onum为输出层神经元数
    ~BPNeuralNetwork();                 //析构函数
    BPNeuralNetwork(const BPNeuralNetwork& net);    //复制构造函数
    mvector& getResult();            //获得结果
    void assumpt(mvector x);        //输入x求得当前网络输出值（向量）
    int  praAsssumpt(mvector x);        //输入x求得当前网络确切的输出值（数）
    double getSquareError(mvector x, mvector a);     //输入自变向量x和期望向量a求方差
    void  train(dataset& dataset);         //训练神经网络
    void  test(dataset &testSet);         //测试数据集中数据
    bool storeModel(std::string fileName);				//存储当前训练结果
    bool loadModel(std::string fileName);					//加载模型
    void setStudyRate(double sr);            //设置学习率
    BPNeuralNetwork& operator = (const BPNeuralNetwork& net);   //赋值函数
    int getInum()       {return inum;}
    bool ifLoaded()     {return isLoaded; }
private:
    Neuron* hiddenLayer;        //隐藏层
    int inum, hnum, onum;       //输入层、隐藏层、输出层维数
    mvector hresult;            //隐藏层激活情况
    Neuron* outLayer;           //输出层
    mvector result;             //输出结果
    double studyRate = 0.05;        //学习率
    int    finalEpoch;				//训练完成后总的训练代数
    int	   numOfTrainset;			//训练完成后训练集的元素个数
    int trainPicHeight, trainPicWidth;          //训练图片的宽度和高度
    bool isLoaded;                      //判断是否是载入的模型
};

#endif // BPNEURALNETWORK_H
