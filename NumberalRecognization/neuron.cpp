#include <cmath>
#include <random>
#include <ctime>
#include "neuron.h"
#include <iostream>
using namespace std;
uniform_int_distribution<int> d(0, 1000);
default_random_engine e((unsigned)time(NULL));      //随机设定神经元权值和偏移

Neuron::Neuron(int n)    //构造函数
{
    weight = mvector(n);
    while (n)
    {
        double t = (double)(d(e)-500) / 1000.0;///(double)(weight.getLen()+1);
        weight[n--] = t;
    }
    bias = (double)d(e)/ 501.0;
    //bias = 1.0;
    output = 0;
}

Neuron::Neuron(const Neuron& neu)      //复制换构造函数
{
    weight = neu.weight;
    bias = neu.bias;
    output = neu.output;
}


void Neuron::setWeight(int i, double w)        //权值和偏移set和get方法
{
    weight[i] = w;
}

void Neuron::setBias(double b)
{
    bias = b;
}

double Neuron::getWeight(int i)
{
    return weight[i];
}

double Neuron::getBias()
{
    return bias;
}

double Neuron::getOutput()
{
    return output;
}

void Neuron::sigmoid(mvector& x)         //sigmoid激活函数
{
    double re = x*weight;
    re -= bias;
    re *= -1.0;
    re = 1.0 + exp(re);
    re = 1.0 / re;
    output = re;
}

Neuron::~Neuron()             //析构函数
{
    weight.~mvector();
}
