#### NumberalRecognization   v 1 .1
> Build Time: 2017 - 6 - 25
> Accuracy: 94%

使用CPU的深度学习程序，推荐配置i7-6700HQ ，RAM 8G
系统目前仅在win10上测试成功

1.  数据读取默认地址为原程序下文件地址请修改
2. 读取数据时label标签勾选则使用MINIST库下的label故还应输入label文件地址
3. 训练文件配置后缀名为.gou
4. 程序执行只需根据标签提示进行即可
5. 训练所需时间可能较长，可以直接加载模型
6. 模型与图片格式有一一对应的关系，故需匹配才可正常执行
7. testset为手写采集图片，hugeSet为60000测试集，dataset为10000测试集
