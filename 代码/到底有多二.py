a=input()
b=len(a)
c=e=0
d=[]
for i in range(b):
    if a[0]=='-':#判断为负数
        b=len(a)-1
        d=a.split()#转换为列表形式，方便利用列表函数
        c=a.count('2')
        if int(d[0])%2==0:#具体将列表中的元素转换为整型
            e=c/b*1.5*2*100
        else:
            e=c/b*1.5*100
    elif int(d[0])%2!=0:
        c=a.count('2')
        e=c/b*100
print("%.2f%%"%e)#“%%”打印一个‘%’