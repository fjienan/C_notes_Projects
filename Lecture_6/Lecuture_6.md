# :six: Lecuture>> Pointer I
## :cop: Memory Address
**The memory address is the location of where the variable is stored on a PC**
1. **Step 1**: When a variable is created in C, a memory address is assigned to the variable.
2. **Step 2**: When we assign a value to the variable, it is stored in this memory address.

内存地址名称是一个16进制数（Hexadecimal）
check a variable address ( & reference operator)
```C
int var1;
printf("the address of var1 is %p/n", &var1);
//&var1 地址总是一个指针类型的变量
```

## :feet: Pointer
它的作用就是不用复制大体量的数据本身，只需要记录这个数据在哪里就行了，从而非常有效的管理了内存

### · Declaration and Definition
```C
// Method_1: 声明后存放
type *var2;
var2 = &var1；
// Method_2: 声明并存放
type *var2 = &var1;
```
### · Interpret Pointer
Two ideas about `int *b`
1. `b` has data type `int*`, it stores the address.
2. `*b` has data type `int`, it corresponds to the value stored in the address ( it is not just copy.).

Sometimes, we can also define the pointer in this way:
```C
// I think it is much easier to understand.
int a = 1;
int* b = &a;
```

### · Pointer allows changing source
参考上面的定义。
既然`a`和`*b`**指向的是同一个地址内储存的值**，那么当我修改其中一个变量的值的时候，另一个也会被修改。

利用这个特征，我们可以**让函数确确实实影响到外参数空间**
E.g. 
1. Swap funtion:
```C
void swap(int *var1, int *var2){
    int temp;
    temp = *var1;
    *var1 = var2;
    *var2 = *temp;
}
```
2. Multiple function outputs
```C
int a = 10, b = 5, sum, sub, mul, div;
func(a, b, &sum, &sub, &mul, &div);
```

### · Array again
**Array 本质是一个pointer，它指向了第一个元素的地址**

>Arithmetic operators:
>1. `ptr++` ( 向后 1 个**单元** )
>2. `ptr+n` ( 向后移动 n 个**单元** )
>3. `ptr--` ( 向前 1 个**单元** )
>4. `ptr-n` ( 向前移动 n 个**单元** )
>
>Logic operators: **\>、<、==** 

有了这些运算，我们可以很好地进行Array的数据处理，尤其是在函数中