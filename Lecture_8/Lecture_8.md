# :eight: Lecture >> I/O
## :kissing_smiling_eyes: User I/O
### · getchar ( ) and putchar ( )
1. `getchar()`reads the next **single character** and returns an integer representing the character in ASCII table. 返还单一字符的 ASCII 码
2. `putchar()`puts the passed character on the screen. 从 ASCII 码转化回字符。
:warning:: **SINGLE CHARACTER !!**
### · fgets ( ) and puts ( )
1. `fgets(s, n, stdin)` 从键盘读取内容，存入预先定义的字符数组 `s` 中。最多读取 `n - 1` 个字符，自动补上 `'\0'`，读到的换行符也会保留。
2. `puts(s)` 输出字符串，并自动换行。

```C
#include <stdio.h>

int main() {
    char str[10];
    fgets(str, sizeof(str), stdin);
    puts(str);
    return 0;
}
```
### · scanf ( ) and printf ( )
1. `printf` 比较简单
2. `scanf(占位符, 赋给变量的地址)`多个占位符之间必须**空格隔开**才会被认为是多个数据。
```C
int main(){
    int c;
    char str[100];
    scanf("%d %s", &c, str);
    printf("output, c = %d, str = \"%s\" \n",c, str);
    return 0;
}
```
## :sun_with_face: File I/O
**读取文件，导出文件，传输文件**
### 1. 文件格式:
1. `ASCII` files: `.txt`,`.csv` 只能储存字符串类型的数据
2. Binary files: `.bin` 可以储存任意类型的数据
### 2.对文件的基本操作：

#### · Open -- `fopen()`
`fopen("文件路径+文件名","mode")` **create a new file** or **open an existing file**, it initializes an object of type `FILE`,本质是个`pointer`
> modes: 决定文件的读写权限，以及文件不存在或已存在时如何处理。

| mode | 含义 | 文件不存在时 | 文件已存在时 |
| --- | --- | --- | --- |
| `"r"` | Read，只读 | 打开失败 | 从文件开头读取 |
| `"w"` | Write，只写 | 创建文件 | **清空原有内容**，从头写入 |
| `"a"` | Append，只追加写入 | 创建文件 | 保留原有内容，写入始终追加到末尾 |
| `"r+"` | 读 + 写 | 打开失败 | 保留原有内容，从文件开头开始 |
| `"w+"` | 读 + 写 | 创建文件 | **清空原有内容**，从文件开头开始 |
| `"a+"` | 读 + 追加写入 | 创建文件 | 保留原有内容，写入始终追加到末尾 |

- `+` 表示同时允许读和写，**不表示追加**；追加由 `a` 决定。
- 默认是 **text mode（文本模式）**；加上 `b` 表示 **binary mode（二进制模式）**，例如 `"rb"`、`"wb"`、`"ab"`、`"rb+"`。二进制模式避免文本模式可能进行的换行符等转换；文件扩展名不会自动决定打开模式。
- :warning: `"w"` 和 `"w+"` 在**成功打开时就会清空文件**，即使还没有写入内容。

#### · Close -- `fclose()`
```C
int flose(FILE *fp);
/* 1. 释放倒入文件所占用的内存
   2. 关闭文件，使得其他程序可以打开这个文件
   3. 刷新缓冲区，将数据真正写入文件
```

以 `"w"` 模式打开文件，写入一行文字，再关闭文件。

```C
#include <stdio.h>

int main() {
    FILE *fp = fopen("./test.txt", "w");
    if (fp == NULL) { // 打开失败时返回 NULL，不能继续使用 fp 读写
        perror("fopen");
        return 1;
    }

    fputs("Hello, file!\n", fp);
    fclose(fp); // 使用完毕后关闭文件
    return 0;
}
```
#### · Read and Write (ASCII file)
1. read and write a single character:
```C
fputc(int c, FILE* fp);// int c 指的是字符代表的ASCII码
char c = fgetc(FILE* fp);
```
2. read and write a group of chars
```C
char str[20];
fputs(char* str, FILE* fp);

fgets(char* str, int n, FILE *p); //但是只能读取n-1个字符的字符串。
```
3. read and write formatted text
`fprintf(FILE* fptr, char* format, 内部不一样的部分)`
`fscanf(FILE* fptr, char* format, 要存入的变量)`
```C
// fprintf
char format[]="My name is %s and I am %d years old.\n";
fprintf(fptr, format, "Jack", 11);
fprintf(fptr, format, "Alice", 21);

// fscanf
char data[300];
fscanf(fptr, "%s", data);
```
> 特别地，对于csv文件，可以使用逗号分隔数据形成表格。
4. Read and Write (Binary file)
二进制文件使用 `fwrite()` 写入、`fread()` 读取，直接保存数据在内存中的字节，不转换为文本。

```C
fwrite(数据地址, 每个元素的大小, 元素个数, 文件指针);
fread(存储地址, 每个元素的大小, 元素个数, 文件指针);
```

例如：将一个整数写入文件，再读取出来。

```C
int num = 123, result;

// 写入
FILE *fp = fopen("data.bin", "wb");
fwrite(&num, sizeof(num), 1, fp);
fclose(fp);

// 读取
fp = fopen("data.bin", "rb");
fread(&result, sizeof(result), 1, fp);
fclose(fp);
// 读取成功后，result 为 123
```

- `&num` / `&result`：变量的地址。
- `sizeof(num)`：一个整数占用的字节数；`1`：读写一个整数。
- 两个函数都返回**成功读写的元素个数**，这里应为 `1`。
- 二进制文件通常不能直接用文本编辑器阅读；不同系统的整数大小、字节顺序可能不同，因此这种写法适合同一环境下保存和读取数据。
