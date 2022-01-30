#解法1:
import re
a=input()
result=[]#定义空列表，因为正则函数返回列表类型
n=n1=0
result = re.findall(r'\d+', a)#利用正则匹配出输入数据中的整数部分
for j in range(len(result)):
    if 3 < len(result[j]) < 9:#选出长度在3~9之间的字符串
        n += 1#统计个数
        a = a.replace(result[j],'9',n)#替换n次
        n = 0#重新赋值零，这里重新赋值零是因为若继续自增，替换次数也会增加，导致结果不对
    elif len(result[j]) > 9:
        n1+=1
        a = a.replace(result[j],'27',n1)
        n1 = 0#同上
print(a)
#解法2:
n = input()
pattern1 = re.sub(r'[6]{10,}','27',n)#sub为替换，且可控制替换次数。
pattern2 = re.sub(r'[6]{4,}','9',pattern1)
print(pattern2)