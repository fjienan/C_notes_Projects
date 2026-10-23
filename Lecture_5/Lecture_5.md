# :five: Lecture >> Function
## :ocean: Declare/define/call a function
1. Structure
```C
return_tpye function_name(parameters/* 形式参数*/){
    body of the function;
    return;
}
```
> return_type:
    int/ float/ void(不返回)/ char

2. Compostion
* Declare the function
```C
// 声明必须在main函数之前
int addition(int a, int b);
//";"依旧很重要
```
* Define the function
```C
//添加了函数主体
int addition(int a, int b);{
    return a+b;
}
```
> Define 可以同时main函数之前与Declare同时进行；Define 可以单独在main函数之后定义
* Call the function
```C
int addition(int a, int b);{
    int z = a + b;
    return z;
}

int main(){
    int a = 1, b = 2;
    int z = addition(a, b);
    // 之后在main中调用了这个function，它才会真正被激活。
    //Arguments（实际参参） 是被复制了一份导入了函数为parameters(形式参数)而不是直接对变量进行处理。
    printf("%d",z);
    return 0;
}
// 这两个z不一样，不会根据名称来链接，所以需要指针(pointer)
```
> 函数是一个封闭的计算盒，一般不会直接和外界变量进行数据作用，传入数据是拷贝的，变量的封闭的。

**:bangbang:函数不允许被多次定义（在C里面）**
3. Nesting 
函数之间可以以不同的方式进行嵌套
* 线形嵌套
* 循环嵌套（循环）
* 自嵌套（递归recursion）

## :hamburger: Variable Scope
1. Global Variable and Local Variable

|Variable Type|Definition Method|Accessibility|Changablility|
|---|---|---|---|
|Global Variable|Declare before main function|Everywhere|Can be changed everywhere||
|Local Variable|Inside the Function|Inside Functions where it was defined|only can be changed within the function|

**:warning: Global and local 
variables can share 
the same name, Local variable has the priority**

2. Storage Classes for Variable ( identifiers )
* `auto`: 随着函数自动生成和销毁的变量，局部变量都是默认`auto` 的
* `static`:全局存在且全局只定义一次，哪怕代码中有多次初始化指令，**但不代表可以全局调用**，全 局变量都是默认`static`的
* `extern`
* `register`:

## :fried_shrimp: Recursion