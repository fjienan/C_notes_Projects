# :seven: Lecture >> self-define types
In C, we can define our type of data.
## :hamster: Struct (结构体), Union (共用体), Enumerate (枚举体)
拓展数据类型，方便我们储存和处理更多类型的数据。
### 1. Struct (结构体)
结构体定义了一种数据类型，里面可以储存**不同的数据类型**的数据。
```C
struct name{
    /* type variabel;*/
    int variable_1;
    float variable_2;
}
```
example:
```C
struct student{
    char name[20];
    int age;
    int ID;
    float height;
};
```
:warning:
1. `struct` 这个字段不是一种数据类型.
2. `student` in this case is not an array.

#### · How to define a struct
1. we must define the struct data **before the main function**
2. 这个有点像python中的类，可以对对象内的变量赋值。并且这个**关键字也就被占用了**。
```C
int main{
    //method 1
    struct student student_1 = {18, 172.0};
    //method 2
    struct student student_2;
    student_2.age = 18;
    student_2.height = 172.0;
    // 对于内部array的定义方式遵守正常的array的规则，声明struct的时候相当于内部定义的变量都声明并定义了一遍。
    strcpy(student_2.name, "Jack Chen")
}
```
3. 可以在定义的结构体的同时定义全局的结构体变量
```C
struct student{
    int age;
    float height;
} student1, student2 ;
```
#### Other Properties   
1. 结构体可以嵌套
```C
struct birthday{
    int year;
    int month;
    int day;
}
struct student{
    int age;
    struct birthday birth;
}
```
2. 结构体也可以用于定义成array
```C
struct student stu[2];
struct student stu_1[2]={{"Jack", 16, 60.5},{"Alice", 21, 49.0}}
```
3. 结构体也有指针: 
    1. 结构体变量的地址，是第一个子变量的地址
    2. 其他成员变量也有自己的地址
    3. 对于结构体array，`ptr+n` 地址跳转不会在子变量之间穿行，因为`struct`不是array，它整体是一个变量
4. Access member of struct using ptr
    ```C
    struct student stu;
    struct student *ptr = &stu;
    // method_1
    printf("name of the student is %s/n",*ptr.name);
    // method_2
    printf("name of the student is %s/n", ptr->name);
    ```
5. 结构体作为函数的输入输出——逻辑和一般变量是一样的。

### 2. Union (共用体)
共用体定义了一种数据类型，它使得内部的不同类型的变量**共用同一块内存空间**
```C
union student{
    char name[20];
    int ID;
    int grade;
}

sizeof(student) /* 会输出这个三个变量内存占用空间的最大值，因为共用一块地 */
``` 

:warning: 所以会有个很大的问题：因为空间共用，所以我们只能给其中的一种变量赋值并使用（没什么用～～）

### 3. Enumerate (枚举型)
共用体定义了一种数据类型，它将一系列变量重新分配成了整数序列。
```C
enum week { 
    variable_1; // 0
    variable_2; // 1
    variable_3; // 2
}

int main(){
    enum week day = variable_1; // day = 0
    enum week day_2;
    day_2 = variable_3; //day_2 = 2
    return 0;
}
```
**适用于天生自带顺序的一些列名字**

我们还可以定义整数序列的起始值:
```C
enum week { 
    variable_1 = 3; // 3
    variable_2; // 4
    variable_3; // 5
}
```

## :wolf: Typedef and \#define

### 1. Typedef
就是重命名变量关键字，简化代码。
```C
typedef struct Books{
    char title[50];
    char author[50];
} Book ; //将原本的变量名struct Books 更名为Book，简化代码
int main(){
    Book book_1 = {"Happy","Jack"};
    return 0;
}
```
**遵守scope rules，因为它相当于复制了一种同类不同名的变量。如果定义在函数类，那么也只是在函数内有效**

### \#define
`#define`允许我们定义宏，编译前的硬编码。**本质依旧是改名字**，会在编译前把所以关键字替换掉，类似`include`
```C
#define PI 3.14
```
**不遵守scope rules，因为本质会被替换掉**