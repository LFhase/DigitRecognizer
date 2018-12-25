#ifndef NEURON_H
#define NEURON_H

#include "mvector.h"

class Neuron
{
public:
    friend class BPNeuralNetwork;
    Neuron(int n=0);           //构造函数,构造一个接受n维输入的神经元
    Neuron(const Neuron& neu);      //复制构造函数
    ~Neuron();             //析构函数
    void setWeight(int i, double w);        //set和get方法
    void setBias(double b);
    double getWeight(int i);
    double getBias();
    double getOutput();
    void sigmoid(mvector& x);         //sigmoid激活函数
                                     //mvector& operator = ()
private:
    mvector weight;         //连接该神经元与上一层的权值
    double bias;            //连接该神经元与上一层的偏移
    double output;          //该神经元的激励
};

#endif // NEURON_H
