# Python 书写规范
## 分号
* 不要在行尾加分号, 也不要用分号将两条命令放在同一行.
## 行长度
- 每行不超过80个字符


#  Python 报错记录
### No Python at 'C:\Users\Allen\AppData\Local\Programs\Python\Python38\python.exe'
在clone Python项目时，运行报错，需要设置python安装路径。
    
- 1 打开你项目的venv文件夹下的pyvenv.cfg文件
```
home = C:\Users\yulee\AppData\Local\Programs\Python\Python38-32 #此处改为本地python地址
include-system-site-packages = false
version = 3.8.1
```
- 2再次输入pip install reuqests


``` javascript
functionwrap(points){
    const hull =[]
    let current ={x:Infinity}
    for(const p of points){
        if(p.x < current.x) 
           current = p
  }
  let i =0, end

  while(true){
    hull[i]= current
    end = points[0]
    for(let j =1; j < points.length; j++){
        if((end.x === current.x && end.y === current.y)||inline(points[j], hull[i], end)>0){
            end = points[j]
        }
    }
    i +=1
    current = end

    if(end.x === hull[0].x && end.y === hull[0].y)
        break
    }
    return hull
}
```

## 关于[:]的含义
```python
a=[1,2,3]
b=a
b[0]=2
print a
print b
c=b[:]
c[0]=3
print b
print c
```