#include "bpneuralnetwork.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <QDialog>
#include <iostream>
#include <QMessageBox>
#include "trainingmsg.h"
#include "ui_trainingmsg.h"
using namespace std;

BPNeuralNetwork::BPNeuralNetwork(int inum, int hnum, int onum)    //构造函数hnum为隐藏层神经元数，onum为输出层神经元数
{
    isLoaded = false;
    this->inum = inum;
    this->hnum = hnum;
    this->onum = onum;
    hresult = mvector(hnum);
    result = mvector(onum);
    hiddenLayer = new Neuron[hnum + 1];
    for (int i = 0; i <= hnum; ++i)	hiddenLayer[i] = Neuron(inum);
    outLayer = new Neuron[onum + 1];
    for(int i = 0 ;i <= onum; ++i)	outLayer[i] = Neuron(hnum);

}

BPNeuralNetwork::BPNeuralNetwork(const BPNeuralNetwork& net)    //复制构造函数
{
    //因调用场合限制，故此为简化版
    this->inum = net.inum;
    this->hnum = net.hnum;
    this->onum = net.onum;
    isLoaded = net.isLoaded;
    hresult = mvector(hnum);
    result = mvector(onum);
    if(hiddenLayer!=NULL)   delete []hiddenLayer;
    hiddenLayer = new Neuron[hnum + 1];
    for (int i = 0; i <= hnum; ++i)	hiddenLayer[i] = net.hiddenLayer[i];
    if(outLayer!=NULL)   delete []outLayer;
    outLayer = new Neuron[onum + 1];
    for(int i = 0 ;i <= onum; ++i)	outLayer[i] = net.outLayer[i];
    studyRate = net.studyRate;
    result = net.result;
    hresult = net.hresult;
    finalEpoch = net.finalEpoch;
    numOfTrainset = net.numOfTrainset;
    trainPicHeight = net.trainPicHeight, trainPicWidth = net.trainPicWidth;
}

BPNeuralNetwork::~BPNeuralNetwork()                 //析构函数
{
    if (hiddenLayer != 0)
    {
        delete[]hiddenLayer;
        hiddenLayer = 0;
    }
    if (outLayer != 0)
    {
        delete[]outLayer;
        outLayer = 0;
    }
}

mvector& BPNeuralNetwork::getResult()            //获得结果
{
    return result;
}

void BPNeuralNetwork::assumpt(mvector x)        //输入x求得当前网络输出值
{
    for (int i = 1; i <= hnum; ++i)
    {
        hiddenLayer[i].sigmoid(x);
        hresult[i] = hiddenLayer[i].output;
    }
    for (int j = 1; j <= onum; ++j)
    {
        outLayer[j].sigmoid(hresult);
        result[j] = outLayer[j].output;
    }
}

int  BPNeuralNetwork::praAsssumpt(mvector x)        //输入x求得当前网络确切的输出值（数）
{
    assumpt(x);
    int maxNum = 1;
    for (int i = 2; i <= 10; ++i)
        if (result[i]>result[maxNum])    maxNum = i;
    return maxNum - 1;
}

double BPNeuralNetwork::getSquareError(mvector x, mvector a)     //输入自变向量x和期望向量a求方差
{
    double re = 0;
    for (int i = 1; i <= x.getLen(); ++i)
        re += pow(fabs(a[i] - result[i]), 2);
    return re*0.5;
}

void  BPNeuralNetwork::train(dataset& dataSet)         //训练神经网络
{
    mvector prehlDelta(hnum);           //当前隐层的误差
    mvector preolDelta(onum);          //当前输出层的误差
    double error = 1000;
    int t;
    trainingMsg* msg = new trainingMsg;                 //输出训练信息
    msg->ui->info->setText("Train Start...");
    msg->ui->textBrowser->hide();
    msg->show();
    for ( t = 1;t<=dataSet.totalEpoch&&error>=0.001/*&&maxNum<dataSet.data[1].sizeOfPerSet*//*&&maxNum<10*/; ++t)            //总的数据集迭代
    {

        for (int m = 1; m <= dataSet.numOfSet; ++m)					//mini-batch迭代
        {
            imageEle* localptr = dataSet.data[m].List;          //迭代指示指针
            prehlDelta.initialize();
            preolDelta.initialize();

            while (localptr != NULL)					//一个mini-batch内迭代
            {
                assumpt(localptr->imageInfo);                   //结果正向传播

                for (int i = 1; i <= onum; ++i)           //误差反向传播求输出层误差
                {
                    preolDelta[i] =  (((i - 1) == localptr->expOutput) ? 0.9 : 0.1) - result[i];
                    preolDelta[i] *= (1 - result[i])*result[i];
                    outLayer[i].bias -= studyRate*preolDelta[i];
                    for (int j = 1; j <= hnum; ++j)
                        outLayer[i].weight[j] += studyRate*preolDelta[i] * hiddenLayer[j].output;
                }

                for (int i = 1; i <= hnum; ++i)           //误差反向传播求隐藏层误差
                {
                    prehlDelta[i] = 0;
                    for (int j = 1; j <= onum; ++j)
                        prehlDelta[i] += outLayer[j].weight[i] * preolDelta[j];

                    prehlDelta[i] *= (1 - hiddenLayer[i].output)*hiddenLayer[i].output;
                    hiddenLayer[i].bias -= studyRate*prehlDelta[i];
                    double ttt;
                    for (unsigned int j = 1; j <= localptr->imageInfo.imageHead.biSizeImage; ++j)
                    {
                         ttt =  localptr->imageInfo.pImageBody[j - 1];
                         ttt *= studyRate*prehlDelta[i];
                         hiddenLayer[i].weight[j]+= ttt;
                         ttt = hiddenLayer[i].weight[j];
                    }
                }										//反向传播结束

                localptr = localptr->pNext;             //移动指针迭代
            }

        }
        imageEle* ptr = dataSet.data[1].List;
        error = 0;
        while (ptr != NULL)                     //计算方差
        {
            assumpt(ptr->imageInfo);
            mvector tt(10);
            for (int i = 1; i <= 10; ++i)
                tt[i] = ((i-1) == ptr->expOutput) ? 0.9 : 0.1;
            error += getSquareError(result, tt);
            ptr = ptr->pNext;
        }
        error /= (double)dataSet.data[1].sizeOfPerSet;
        char info[100];
        sprintf(info,"SquareError: %.6f in Epoch %d",error,t);
        cout<<info<<endl;
        QString qinfo(info);
        msg->ui->info->setText(qinfo);              //更新训练信息
        QApplication::processEvents();
    }
    finalEpoch = t==dataSet.totalEpoch+1?t-1:t;					//存储最后的训练代数
    numOfTrainset = (dataSet.numOfSet - 1)*dataSet.data[1].sizeOfPerSet + dataSet.data[dataSet.numOfSet].sizeOfPerSet;		//计算训练集合大小
    trainPicHeight = dataSet.data[1].List->imageInfo.imageHead.biHeight;
    trainPicWidth = dataSet.data[1].List->imageInfo.imageHead.biWidth;
    msg->close();                   //关闭子窗口
}

bool BPNeuralNetwork::storeModel(string fileName)			//存储当前训练结果
{

   /* string fileName, ad;
    cout << "Input the address where you want to save the model" << endl;
    cin >> ad;
    cout << "Input the file's name where you want to save the model" << endl;
    cin >> fileName;
    string file(ad+ fileName + ".gou");				//自定义文件存储
    ofstream storeFile(file);*/
    ofstream storeFile(fileName);
    if (storeFile.is_open())
    {
        storeFile << (unsigned)time(NULL) <<" "<< 2048 << endl;				//首先存入时间 + 标志数
        storeFile << inum << " " << hnum << " " << onum << endl;		//其次存入各层数量
        storeFile << trainPicHeight <<" "<<trainPicWidth <<endl;           //存入训练集图片高宽
        storeFile << numOfTrainset << " " << finalEpoch << " " << studyRate << endl;
        for (int i = 1; i <= onum; ++i)								//存储输出层数据
        {
            for (int j = 1; j <= hnum; ++j)
                storeFile << outLayer[i].weight[j] << " ";
            storeFile << outLayer[i].bias << endl;
        }
        for (int i = 1; i <= hnum; ++i)								//存储隐藏层数据
        {
            for (int j = 1; j <= inum; ++j)
                storeFile << hiddenLayer[i].weight[j] << " ";
            storeFile << hiddenLayer[i].bias << endl;
        }
        storeFile.close();
        cout << "Succeed to save the model" << endl;
    }
    else
    {
        cout << "Fail to save the model. Please check your input. " << endl;
        return false;
    }
    return true;
}

bool BPNeuralNetwork::loadModel(string fileName)					//加载模型
{
   /* string fileName, ad;
    cout << "Input the address where the model is" << endl;
    cin >> ad;
    cout << "Input the file's name where the model is" << endl;
    cin >> fileName;
    string file(ad + fileName + ".gou");				//自定义文件存储
    ifstream modelFile(file);*/
    ifstream modelFile(fileName);
    if (modelFile.is_open())
    {
        bool flag = true;
        int temp;
        int tempInum, tempHnum, tempOnum;
        modelFile >> temp;
        modelFile >> temp;
        if (temp != 2048)	 flag = false;				//首先读取时间 + 标志数
        modelFile >> tempInum >> tempHnum >> tempOnum;			//其次加载各层数量
       if ((!inum && !hnum && !onum)||
         (tempInum == inum && tempHnum == hnum&& tempOnum == onum))//判断当前参数是否匹配
            {
                inum = tempInum;
                hnum = tempHnum;
                onum = tempOnum;
                hresult = mvector(hnum);
                result = mvector(onum);
                hiddenLayer = new Neuron[hnum + 1];
                for (int i = 0; i <= hnum; ++i)	hiddenLayer[i] = Neuron(inum);
                outLayer = new Neuron[onum + 1];
                for (int i = 0; i <= onum; ++i)	outLayer[i] = Neuron(hnum);
                isLoaded = true;
            }
            else
                return flag;
       if(!flag)    return flag;
       int temptrainPicHeight, temptrainPicWidth;
        modelFile >> temptrainPicHeight >>temptrainPicWidth ;           //加载训练集图片高宽
        if((trainPicHeight&&trainPicWidth)&&(temptrainPicHeight!=trainPicHeight||temptrainPicWidth!=trainPicWidth))
        {
            flag = false;
            return flag;
        }
        trainPicHeight = temptrainPicHeight, trainPicWidth = temptrainPicWidth;
        int trainSetSize, totalEpoch;
        modelFile >> trainSetSize;	modelFile >> totalEpoch;		modelFile >> studyRate;
        for (int i = 1; i <= onum; ++i)								//加载输出层数据
        {
            for (int j = 1; j <= hnum; ++j)
                modelFile >> outLayer[i].weight[j];
            modelFile >> outLayer[i].bias;
        }
        for (int i = 1; i <= hnum; ++i)								//加载隐藏层数据
        {
            for (int j = 1; j <= inum; ++j)
                modelFile >> hiddenLayer[i].weight[j];
            modelFile >> hiddenLayer[i].bias;
        }
        modelFile.close();
        char msg[200];
        sprintf(msg,"Succeed to load the model\n"                       //读取成功后显示该模型信息
                    "its inputDimension: %d   hiddenLayerDimension: %d  outputLayerDimension:  %d\n"
                    "In the last train...\n"
                    "trainSet's size: %d totalEpoch: %d studyRate: %.4f",
                    inum,hnum,onum,trainSetSize,totalEpoch,studyRate);
        QString msgb(msg);
        QMessageBox::about(NULL,"LoadModel",msgb);
    }
    else
    {
        cout << "Fail to load the model. Please check your input. " << endl;
        return false;
    }
    return true;
}

void BPNeuralNetwork::setStudyRate(double sr)            //设置学习率
{
    this->studyRate = sr;
}

BPNeuralNetwork& BPNeuralNetwork::operator = (const BPNeuralNetwork& net)   //赋值函数
{
    //因调用场合限制，故此为简化版
    this->inum = net.inum;
    this->hnum = net.hnum;
    this->onum = net.onum;
    isLoaded = net.isLoaded;
    hresult = mvector(hnum);
    result = mvector(onum);
    if(hiddenLayer!=NULL)   delete []hiddenLayer;
    hiddenLayer = new Neuron[hnum + 1];
    for (int i = 0; i <= hnum; ++i)	hiddenLayer[i] = net.hiddenLayer[i];
    if(outLayer!=NULL)   delete []outLayer;
    outLayer = new Neuron[onum + 1];
    for(int i = 0 ;i <= onum; ++i)	outLayer[i] = net.outLayer[i];
    studyRate = net.studyRate;
    result = net.result;
    hresult = net.hresult;
    finalEpoch = net.finalEpoch;
    numOfTrainset = net.numOfTrainset;
    trainPicHeight = net.trainPicHeight, trainPicWidth = net.trainPicWidth;
    return *this;
}

void  BPNeuralNetwork::test(dataset& testSet)         //测试数据集中数据
{
    double error = 0;
    int amount = 0;
    int rightPic = 0;
    trainingMsg* msg = new trainingMsg;                 //输出训练信息
    msg->ui->label_2->setText("Testing");
    msg->ui->textBrowser->append("Test Start...");
    msg->show();

    imageEle* ptr = testSet.data[1].List;
    while (ptr != NULL)                     //计算方差
    {
        amount++;
        int re = praAsssumpt(mvector(ptr->imageInfo));
        if(re==ptr->expOutput)    rightPic++;
        mvector tt(10);
        for (int i = 1; i <= 10; ++i)
                tt[i] = ((i-1) == ptr->expOutput) ? 0.9 : 0.1;
            error += getSquareError(result, tt);

         int sec=re==0?2:1;
         for(int i=1;i<=10;++i)
          if(result[i]>result[sec]&&i!=re+1)
                  sec = i;

         char info[100];
         sprintf(info,"Pic_%d Result: %d  Accuracy: %.2f",amount,re,result[re+1]-result[sec]);
         QString qinfo(info);
         msg->ui->textBrowser->append(qinfo);              //更新测试信息
         QApplication::processEvents();
         ptr = ptr->pNext;
     }
      error /= (double)testSet.data[1].sizeOfPerSet;
    char info[100];
    sprintf(info,"Test Completed!\n"
                 "TotalTestingAmount %d   RightPicAmount %d\n"
                 "TotalAccuracy  %.2f  SquareError  %.6f",amount,rightPic,(double)rightPic/amount,error);

    QMessageBox::about(NULL,"TestComplete",QString(info));
    msg->close();                   //关闭子窗口
    cout << "gg again" << endl;
}
