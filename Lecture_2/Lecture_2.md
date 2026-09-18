# :two: Lecture >>Basics
## :blush: 1. bit and byte
### Bit : the smallest unit for storage 
> 对应的就是二极管（Diode）的两种状态（0 or 1）,硬件层面的存储
### Byte : the smallest unit for information storage
$$
 1 \space byte = 8 \space bits
$$
> more units about byte:\
    1 KB (Kilobyte) = 1024 bytes\
    1 MB (Megabyte) = 1024 KB\
    1 GB (Gigabyte) = 1024 MB\
    1 TB (Terabyte) = 1024 GB\
    1 PB (Petabyte) = 1024 TB

### Numbering system
计算机总是以二进制的方式储存和处理数据

### Use byte to store numbers
#### interger
可以用8位来记录对应的二进制数
> 6 (decimal)=110 (binary)
#### character
用8位来储存character对应的ASCII码(是个整数)
>A = 65
#### real number
转化成二进制科学计数法，32位浮点数 
$$
88.8125=1.0110001101×2^6
$$

>1 bit 表示 符号\
8 bits 表示 小数点位置/指数\
23 bits 表示小数部分（整数1是默认的，不需要专门储存）

## :smile: 2.Data types and variables
### Data types
|data type|storage size|value range|example|details|
|---|---|---|---|---|
|char|1 byte|signed: -128 ~ 127<br>unsigned: 0 ~ 255|`char grade = 'A';`|用于储存单个字符或小整数；`char` 默认是否带符号取决于编译器|
|int|通常为 4 bytes|-2,147,483,648 ~ 2,147,483,647|`int age = 18;`|每个 bit 都用于表示符号或参与计数，可以精确表示范围内的整数|
|float|4 bytes|约 $\pm 3.4 \times 10^{38}$|`float pi = 3.14f;`|使用二进制科学计数法，通常有 6～7 位十进制有效数字，范围大但精度有限|
|double|8 bytes|约 $\pm 1.7 \times 10^{308}$|`double pi = 3.1415926;`|双精度浮点数，通常有 15～16 位十进制有效数字|
|void|无|-|`void print(void);`|表示“无类型”或“没有返回值”，不能声明普通的 `void` 变量|

### Variables
变量需要声明类型，声明了类型内存就会专门给这个变量分一块地用于储存具体数据，毕竟不同数据的对应逻辑是不同的。

**变量相当于就是某一个块地皮的拥有者或者是数值的容器**

**变量只能定义一次，或者说声明只能执行一次，一般都可以二次赋值**
> Constant Variable: 用于保护一些变量确保不被修改
```C
int x = 3; //正常变量，可以二次赋值
const int y = 3; //常量，不能二次修改
```

· **Cast Variable：** 强制转换
```C
float x;
int y = 3;
x = (float)y;
```

## :tent: 3.Operation
### Operators 算子
1. Arithmetic Operators 
2. Relational Operators
3. Logistic Operators
4. Assignment Operators
5. Misc Operators
#### 1> Arithmetic Operators
|Operators|Description|Example|
|---|---|---| 
|`+`|加法：计算两个操作数之和|`5 + 2` 的结果是 `7`|
|`-`|减法：用左操作数减去右操作数|`5 - 2` 的结果是 `3`|
|`*`|乘法：计算两个操作数的乘积|`5 * 2` 的结果是 `10`|
|`/`|除法：左操作数除以右操作数；两个整数相除时舍去小数部分|`5 / 2` 的结果是 `2`，`5.0 / 2` 的结果是 `2.5`|
|`%`|取余：得到整数除法的余数，**只能用于整数**|`5 % 2` 的结果是 `1`|
|`++`|自增：使变量的值增加 `1`|`x++` 或 `++x`|
|`--`|自减：使变量的值减少 `1`|`x--` 或 `--x`|

Notes：Post-increment & Pre-increment
```C
int A = 20，C = 20;
int B = A++; //Post-increment：先赋值再自增修改A的值
int D = ++C; // Pre-increment: 先自增修改C的值再赋值
```

#### 2> Relational Operators
|Operators|Description|Example|
|---|---|---|
|`==`|等于：判断两个操作数的值是否相等|`5 == 5` 的结果是 `1`|
|`!=`|不等于：判断两个操作数的值是否不相等|`5 != 2` 的结果是 `1`|
|`>`|大于：判断左操作数是否大于右操作数|`5 > 2` 的结果是 `1`|
|`<`|小于：判断左操作数是否小于右操作数|`5 < 2` 的结果是 `0`|
|`>=`|大于等于：判断左操作数是否大于或等于右操作数|`5 >= 5` 的结果是 `1`|
|`<=`|小于等于：判断左操作数是否小于或等于右操作数|`5 <= 2` 的结果是 `0`|

> 在 C 语言中，关系表达式成立时结果为 `1`，不成立时结果为 `0`。注意：`==` 用于比较，`=` 用于赋值。

#### 3> Logical operators 
|Operators|Description|Example|
|---|---|---|
|`&&`|逻辑与（AND）：两个条件都成立时结果才为 `1`|`(5 > 2) && (3 < 4)` 的结果是 `1`|
|`\|\|`|逻辑或（OR）：至少一个条件成立时结果为 `1`|`(5 < 2) \|\| (3 < 4)` 的结果是 `1`|
|`!`|逻辑非（NOT）：将真、假结果取反|`!(5 > 2)` 的结果是 `0`|

> 在 C 语言中，`0` 表示假，任何非零值都表示真；逻辑运算的结果为 `0` 或 `1`。

**Short-circuit evaluation（短路求值）：**

- 对于 `A && B`，如果 `A` 为假，则不会再计算 `B`。
- 对于 `A || B`，如果 `A` 为真，则不会再计算 `B`。

#### 4> Assignment Operators
|Operators|Description|Example|
|---|---|---|
|`=`|将右侧表达式的值赋给左侧变量|`x = 5;`|
|`+=`|先进行加法，再将结果赋给左侧变量|`x += 2;` 等价于 `x = x + 2;`|
|`-=`|先进行减法，再将结果赋给左侧变量|`x -= 2;` 等价于 `x = x - 2;`|
|`*=`|先进行乘法，再将结果赋给左侧变量|`x *= 2;` 等价于 `x = x * 2;`|
|`/=`|先进行除法，再将结果赋给左侧变量|`x /= 2;` 等价于 `x = x / 2;`|
|`%=`|先进行取余，再将结果赋给左侧变量，只适用于整数|`x %= 2;` 等价于 `x = x % 2;`|

> `=` 表示赋值，`==` 表示比较是否相等。例如，`x = 5` 会修改 `x`，而 `x == 5` 只会判断条件是否成立。

#### 5> Misc Operators
|Operators|Description|Example|
|---|---|---|
|`sizeof`|获取类型或对象占用的字节数，结果类型为 `size_t`|`sizeof(int)`、`sizeof x`|
|`条件 ? 值1 : 值2`|条件运算符：条件为真时得到值1，否则得到值2|`max = (a > b) ? a : b;`|
|`&`|取地址运算符：获取变量在内存中的地址|`int *p = &x;`|
|`*`|解引用运算符：访问指针所指向的值|`value = *p;`|


> `&` 在这里表示“取地址”，`*` 在这里表示“解引用”；它们作为二元运算符使用时，也可以分别表示按位与和乘法。

· Conditional Operator
```C
int a=12,b=23;
int flag = a>b ？1:0; 
//有点像 python中：
//flag = 1 if a>b else 0
``` 