# crim犯罪率
# zn住宅用地所占比例
# indus城镇中非住宅用地所占比例
# chas是否穿过查尔斯河
# nox氮氧化污染物
# rm每栋住宅的房间数
# age1940年以前建成的自住单位的比例
# dis距离5个波士顿的就业中心的加权距离
# rad距离高速公路的便利指数
# tax每一万美元的不动产税率
# ptratio城镇中的教师学生比例
# b城镇中的黑人比例
# lstat低收入群比例
# medv价格
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import matplotlib as mp
from sklearn import linear_model
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split
import warnings
warnings.filterwarnings('ignore')

# 搞了半天的最大二乘法，结果和sk库一摸一样！
def zd_wish(x, y):      # 钟迪的祝福
    x_ = test[['crim', 'zn', 'indus', 'chas', 'nox', 'rm', 'age', 'dis', 'rad', 'tax', 'ptratio', 'b', 'lstat']]
    # print(x_)
    y_ = test['medv']
    a_ = [1]
    length = len(x_)
    # print(type(a_))
    for i in range(length - 1):
        a_.append(1)
    a = np.matrix(a_)
    # print(len(a_))
    x = np.matrix(x_)
    # print(len(x))
    xx = np.column_stack((a.T, x))
    # print(xx)
    y = np.matrix(y_)
    # m = len(x)
    # w = my_linear_model(x, y, 1)
    w = np.dot(np.dot(np.linalg.inv(np.dot(xx.T, xx)), xx.T), y.T)
    # print(w)
    return w


test = pd.read_csv(r'D:\python学习\BostonHousing.csv')
pd.set_option('display.max_columns', None)
print(test.head())
# print(test)   # 看下表长什么鸟样
# print(test.describe())    # 查看平均值，标准差，最小值，各段数目，最大值，均值
# test.info()   # 查看统计和数据类型
# print(test.isnull().sum())     # 查看缺失值(无缺失，不用补齐)
# print(test.corr())      # 查看相关性

# 下面进行可视化

# 发现chas的相关性很高,进行画饼可视化
plt.figure(figsize=(10, 10))
# print(test['chas'].value_counts())
CHAS = test['chas'].value_counts().plot.pie(autopct='%1.2f%%')
CHAS.set_xlabel('chas')
CHAS.set_ylabel('')
# plt.show()
# 用数据看一下chas和价格的关系
chas_judge = test.groupby(['chas'])['medv'].mean()
Chas_Judge = pd.DataFrame(chas_judge)
Chas_Judge.rename(columns={'chas': 'medv'}, inplace=True)
Chas_Judge.reset_index(inplace=True)
# print(Chas_Judge)

# 看各个数据与price的散点图已便计算
x_label = test[['crim', 'zn', 'indus', 'chas', 'nox', 'rm' , 'age', 'dis', 'rad', 'tax', 'ptratio', 'b', 'lstat']]
# print(x_label)
y_label = test[['medv']]
plt.figure(figsize=(30, 10))
for i in range(13):
    plt.subplot(4, 4, i+1)
    plt.scatter(x_label.values[:, i], y_label, s=5)
    plt.xlabel(x_label.columns[i])
    plt.ylabel('medv')

plt.tight_layout()      # 自动调整参数
plt.show()

# 运用线性回归实现对数据的学习
x = pd.DataFrame(test[['crim', 'zn', 'indus', 'chas', 'nox', 'rm' , 'age', 'dis', 'rad', 'tax', 'ptratio', 'b', 'lstat']])
y = test['medv']

# 以下为测试集测试
# (x_train, x_test, y_train, y_test) = train_test_split(x, y, test_size=.2)     # 将训练集分为训练集和测试集
# clf = linear_model.LinearRegression()
# clf.fit(x_train, y_train)       # 建立模型
# # print(clf.coef_)      # 每一列的系数系数(即w1，w2......wn)
# # print(clf.intercept_)     # 第1项的系数（即w0）
# y_pred = clf.predict(x_test)        # 预测
# # print(y_pred)
# score = r2_score(y_test, y_pred)        # 得到分数（约为0.67~0.76）
# print(score)

# 以下为全训练集构建
# clf2 = linear_model.LinearRegression()
# clf2.fit(x, y)
# print(clf2.coef_)
# print(clf2)
# y_pred2 = clf2.predict(x)
# score2 = r2_score(y, y_pred2)
# print(score2)

# 以下为自定义函数构建
clf3 = zd_wish(x, y)
b = clf3[0, 0]
# print(b)
clf3 = np.delete(clf3, 0, 0)
length = len(clf3)
# print(clf3)
a = [0]
print("输入你要预测房价的'crim', 'zn', 'indus', 'chas', 'nox', 'rm', 'age', 'dis', 'rad', 'tax', 'ptratio', 'b', 'lstat':")
i = 0
while i < length:
    try:
        put = float(input())
    except:
        print("输入错误，请重新输入！")
        continue
    if i == 0:
        a[0] = put      # 输入为字符串，需要转换，防止报错
    else:
        a.append(put)
    i = i+1
a_ = np.matrix(a)
print("所预测房价结果为：")
c = np.dot(clf3.T, a_.T)
print(c)
# 'crim', 'zn', 'indus', 'chas', 'nox', 'rm' , 'age', 'dis', 'rad', 'tax', 'ptratio', 'b', 'lstat'
