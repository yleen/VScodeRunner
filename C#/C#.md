# C#中Equals和==的区别
1.对值类型
  两者比较的都是内容，即值是否相同

```C#
int i = 9;
int j = 9;

Console.WriteLine("Equals和= =(等于号)的比较");
Console.WriteLine("i.Equals(j) :" + i.Equals(j));
Console.WriteLine("i==j " + (i == j));
```
输出
```
Equals和= =(等于号)的比较
i.Equals(j) :True
i==j True
```

2.对引用类型
- string类型
  

==比较的是两变量引用是否一样 即引用地址是否相同。Equals比较的还是内容
```C#
string s1 = "abc";
string s2 = "abc";

Console.WriteLine("Equals和= =(等于号)的比较");
Console.WriteLine("s1==s2 " + (s1 == s2));
Console.WriteLine("s1.Equals(s2) " + s1.Equals(s2));
```
输出
```
Equals和= =(等于号)的比较
s1==s2 True
s1.Equals(s2) True
```
>此处由于string是微软封装的一个字符串类，在内部他已经对 = = 操作符进行了重写。重写后他比较的则是两个变量的内容是否相同。重写后的 = = 操作符内部调用的即是 equals 方法，所以输出的是true

- 自定义引用类型
```C#
Person p1 = new Person("aa", 12);
Person p2 = new Person("aa", 12);

Console.WriteLine("Equals和= =(等于号)的比较");
Console.WriteLine("p1==p2  " + (p1 == p2));
Console.WriteLine("p1.Equals(p2)  " + p1.Equals(p2));
```
输出
```
Equals和= =(等于号)的比较
p1==p2 False
p1.Equals(p2) False
```
>对于 p1==p2 比较的结果是false，这点是毫无疑问的，因为他俩是两个不同的变量，所以引用的地址也是不同的。但是对于p1.Equals(p2) 返回false，可能有人会产生疑问，p1 和p2的内容是相同的啊，为什么他俩的比较结果却是为false呢？。原因就在于在Equals是Object中的一个虚方法，而person类中没有对她进行重写，因此此时调用的仍是父类中的Equals方法。但是父类是无法知道你都有哪些成员字段的，因此返回的是false。要想让他能够比较两个变量的内容是否相同，那就应该重写Equals方法
```C#
public override bool Equals(object obj)
{
    Person p = obj as Person;
    //对变量的所有的属性都要进行比较  只有都相同才返回true
    if (this.Age == p.Age && this.Name == p.Name)
    {
        return true;
    }
    else
    {
        return false;
    }

}
```

# C# yield return的用法

对于函数

```csharp
        public static List<int> Unique(IEnumerable<int> nums)
        {
            List<int> uniqueVals = new List<int>();

            foreach(int num in nums)
            {
                if(!uniqueVals.ContainsKey(num))
                {
                    uniqueVals.Add(num);
                    Console.WriteLine(num);
                }
            }
            return uniqueVals;
        }
```

不难理解，传进来一个数组，比如说是一个 list，返回一个去重的 list 出去，简单明了，事实上，这个函数如果不需要复用的话，没有任何问题。但是，作为程序员，我们遇到不需要复用的情形实际上是非常少的。

比方说，现在有一个要求，让你把一个去重的 list 乘方，你会怎么做，我们可能很自然的想到，把这个 Unique 函数的输出结果当做输入传到另一个乘方函数里面，然后再遍历一遍即可解决。

可是，这样的问题是，我们完全可以把去重和乘方放在一次遍历里面一起解决啊，你这样多遍历了一次，增加了时间复杂度。

又有同学可能要说，我们直接去改 Unque 函数不就行了吗，再里面添加一段乘方逻辑。好，这样的话我再问你，比方说现在又有一个需求，让你把一个 list 去重以后开方，你怎么办？你是要再写一个新的函数么？这样的话，你这两个函数里面都有 list 去重这段逻辑，造成了代码冗余，这是软件工程的禁忌。

那怎么办？yield return 可以完美的解决这个问题，以上面的去重乘方需求为例，我们可以把 Unique 函数改写为：

```c#
using System;
using System.Collections.Generic;
using System.Linq;

var l = new List<int> { 0, 3, 4, 5, 7, 3, 2, 7, 8, 0, 3, 1 };
foreach (int num in Square(Unique2(l)))
    Console.WriteLine($"{num}");

static IEnumerable<int> Unique2(IEnumerable<int> nums)
{
    List<int> uniqueVals = new List<int>();

    foreach (int num in nums)
    {
        if (!uniqueVals.Contains(num))
        {
            uniqueVals.Add(num);
            yield return num;
        }
    }
}

static IEnumerable<int> Square(IEnumerable<int> nums)
{
    foreach (var num in nums)
        yield return num * num;
}
```

准确的说，启动两次 for 循环，每次循环执行一次运算，和启动一次 for 循环，一次循环执行两次运算，这两种开销是不一样的，比如说，启动 for 循环的代价是 m，一次运算的代价是 n，共 k 次运算，那么前者的开销是 k(m+n) 后者是 m + kn。

[参考](https://zhuanlan.zhihu.com/p/103850999)

# C#中List用法

List的方法和属性 方法或属性 作用
```C#
//Capacity 用于获取或设置List可容纳元素的数量。当数量超过容量时，这个值会自动增长。您可以设置这个值以减少容量，也可以调用TrimExcess()方法来减少容量以适合实际的元素数目。*注意 Capacity表示的是容量而不是元素个数，调用TrimExcess()是来动态调整Capacity的值以便最适合该List
List<int> list = new List<int>();//list.Capacity==0
list.Capacity = 10;//list.Capacity==10
list.Add(1);
list.Add(1);
list.Add(1);//list.Capacity==10
list.TrimExcess();//list.Capacity==3
list.Add(1);
list.Add(1);//list.Capacity==6
list.TrimExcess();//list.Capacity==6
//Count 属性，用于获取数组中当前元素数量
//*此方法已被删去*，新方法和数组一样用[]    Item( ) 通过指定索引获取或设置元素。对于List类来说，它是一个索引器。
list[0]//指向索引为0的元素
//Add( ) 在List中添加一个对象的公有方法
//AddRange( ) 公有方法，在List尾部添加实现了ICollection接口的多个元素
list.AddRange(list);//自己添加自己   Count==10
//BinarySearch( ) 重载的公有方法，用于在排序的List内使用二分查找来定位指定元素. *必须有序*
//Clear( ) 在List内移除所有元素
//Contains( ) 测试一个元素是否在List内 返回True\False
//Exists( ) 测试一个元素是否在List内 与Contains()的区别是 Exists传入判断函数
list.Exists(i=>i==2)
//Find( ) 查找并返回List内的出现的第一个匹配元素     这两个都
//FindAll( ) 查找并返回List内的所有匹配元素         需要传入判断函数
//GetEnumerator( ) 重载的公有方法，返回一个用于迭代List的枚举器  
//GetRange( ) 拷贝指定范围的元素到新的List内
//IndexOf( ) 重载的公有方法，查找并返回每一个匹配元素的索引
//Insert( ) 在List内插入一个元素
//InsertRange( ) 在List内插入一组元素
//CopyTo( ) 重载的公有方法，把一个List拷贝到一维数组内
//LastIndexOf( ) 重载的公有方法，，查找并返回最后一个匹配元素的索引
//Remove( ) 移除与指定元素匹配的第一个元素
//RemoveAt( ) 移除指定索引的元素
//RemoveRange( ) 移除指定范围的元素
//Reverse( ) 反转List内元素的顺序
//Sort( ) 对List内的元素进行排序
//ToArray( ) 把List内的元素拷贝到一个新的数组内
//************************************************************************
//部分方法实例
//1.声明
List<T> list = new List<T>();  
//2.添加元素
list . Add(T item)  ;
//3.添加一组元素
list . AddRange(IEnumerable<T> collection)  ;
List<string> mList = new List<string>();
string[] temArr = { "a","sdg", "sddd", "0fg", "Jay", "2333" };
mList.AddRange(temArr);
//4.在index位置添加一个元素
Insert(int index, T item); 
//5.遍历List中元素
foreach (T item in mList)  //T的类型与mList声明时一样
{
    Console.WriteLine(item );
}
//6.删除一个值
List. Remove(T item);
//7.删除下标为index的元素
List. RemoveAt(int index);   
//8.从下标index开始，删除count个元素
List. RemoveRange(int index, int count);
//9.判断某个元素是否在该List中(返回值为：true/false)
List. Contains(T item);  
//10.给List里面元素排序(默认是元素第一个字母按升序)
List. Sort ();  
//11.给List里面元素顺序反转 (可以与List. Sort ()配合使用，达到想要的效果)
List. Reverse ();   
//12.List清空
List. Clear ();
//13.获得List中元素数目(返回int值)
List. Count ();    
//******************************************************************************************************
//list进阶
//1.List.FindAll方法：检索与指定谓词所定义的条件相匹配的所有元素 
public List<T> FindAll(Predicate<T> match);
//2.List.Find 方法：搜索与指定谓词所定义的条件相匹配的元素，并返回整个 List 中的第一个匹配元素。
//Predicate是对方法的委托，如果传递给它的对象与委托中定义的条件匹配，则该方法返回 true。
//当前 List 的元素被逐个传递给Predicate委托，并在 List 中向前移动，从第一个元素开始，到最后一个元素结束。
//当找到匹配项时处理即停止。
//Predicate 可以委托给一个函数或者一个拉姆达表达式:
public T Find(Predicate<T> match);
//委托给拉姆达表达式：
string listFind = mList.Find(name =>  //name是变量，代表的是mList中元素，自己设定
{     
   if (name.Length > 3)
   {
      return true;
   }
  return false;
});
Console.WriteLine(listFind);
//委托给一个函数：
string listFind1 = mList.Find(ListFind);  //委托给ListFind函数
Console.WriteLine(listFind);    
//ListFind函数
public bool ListFind(string name)
{
    if (name.Length > 3)
    {
        return true;
    }
    return false;
}
//3.List.FindLast 方法：搜索与指定谓词所定义的条件相匹配的元素，并返回整个 List 中的最后一个匹配元素。
//用法与List.Find相同。
public T FindLast(Predicate<T> match);
//4.List.TrueForAll方法：  确定是否 List 中的每个元素都与指定的谓词所定义的条件相匹配。
//用法与List.Find相同。
public bool TrueForAll(Predicate<T> match);
//5.List.Take(n)方法：  获得前n行 返回值为IEnumetable<T>，T的类型与List<T>的类型一样
IEnumerable<string> takeList=  mList.Take(5);
foreach (string s in takeList)
{
      Console.WriteLine("element in takeList: " + s);//这时takeList存放的元素就是mList中的前5个。
}
//6.List.Where方法：检索与指定谓词所定义的条件相匹配的所有元素。跟List.FindAll方法类似。
//7.List.RemoveAll方法：移除与指定的谓词所定义的条件相匹配的所有元素。
public int RemoveAll(Predicate<T> match);
mList.RemoveAll(name =>
{
     if (name.Length > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
});

foreach (string s in mList)
{
    Console.WriteLine("element in mList:     " + s);//这时mList存储的就是移除长度大于3之后的元素。
} 
```

# C#中Hash用法
Java 中的 哈希表 使用 HashMap 类 来实现。 在 C# 中，官方的哈希表实现为 Dictionary 。

可能很多读者会想到 Hashtable 类，它也是哈希表，但所有元素都为object类型，不支持泛型。官方推荐使用 Dictionary，可以简单的把它理解为支持泛型的Hashtable.

- 官方推荐使用 Dictionary 来代替 Hashtable ，具体可以查看下面两篇官方文章。

[HashTable用法](https://docs.microsoft.com/zh-cn/dotnet/api/system.collections.hashtable?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(System.Collections.Hashtable);k(DevLang-csharp)%26rd%3Dtrue&view=netframework-4.8)

[推荐使用泛型代替非泛型](https://github.com/dotnet/platform-compat/blob/master/docs/DE0006.md)

简单的说，HashTable支持泛型，Dictionary必须规定类型。Hashtable 和Dictionary从数据结构上来说都属于Hashtable，都是对关键字（键值）进行散列操作，将关键字散列到Hashtable的某一个槽位中 去，不同的是处理碰撞的方法。散列函数有可能将不同的关键字散列到Hashtable中的同一个槽中去，这个时候我们称发生了碰撞。
## Dictionary
- 支持泛型，Type safety在定义的时候就必须指定键值类型
- 需线程同步，不支持线程安全。
- 访问速度快，本身不用打包（boxing）和解包（unboxing），速度稍稍稍微快了一点
- 访问不存在的键值对会抛异常
- 处理冲突时使用链表法
## HashTable
- 不支持泛型，但插入类型Object可为任意类型。但会存在插入取出时频繁装箱拆箱，具有一定开销。
- 支持多路读线程且单路写线程安全
- 访问不存在的键值对会返回null
- 数据都是Object类型的，不易维护。
- 处理冲突时使用开放定址法。

Dictionary和HashTable是同源，它们实现了自己的哈希算法。至于两者之间的效率，那得具体看情况了。对于含有大量装箱拆箱的操作，那当然了用泛型字典合适。对于数据量比较小的字符串处理，用HashTable反倒效率可能高一些。
参考:
[图解泛型](https://www.cnblogs.com/wangqiang3311/p/5910254.html)
[浅析C#Dictionary实现原理](https://zhuanlan.zhihu.com/p/96633352)

# C# @符号的含义

在 C# 规范中, @ 可以作为标识符（类名、变量名、方法名等）的第一个字符，以允许C# 中保留关键字作为自己定义的标识符。
如

```c#
class @class
{
   public static void @static(bool @bool) {
      if (@bool)
         System.Console.WriteLine("true");
      else
         System.Console.WriteLine("false");
   }   
}
class Class1
{
   static void M() {
      cl\u0061ss.st\u0061tic(true);
   }
}
```

注意，@ 虽然出现在标识符中，但不作为标识符本身的一部分。
因此，以上示例，定义了一个名为 class 的类，并包含一个名为 static 的方法，以及一个参数名为了 bool 的形参。

这样，对于跨语言的移植带来了便利。因为，某个单词在 C# 中作为保留关键字，但是在其他语言中也许不是。