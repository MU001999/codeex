### 1. 你所设计的符号表和内存的数据结构是怎样的？请说明各个字段的设置内容和设置缘由。

  ```cpp
  struct Value
  {
      int size;
      string val;
  };
  /*
  size ：表示数据的大小
  val  ：以字符串形式记录值
  */
  ```
  ```cpp
  struct SymbolTable
  {
      vector<string> names;
      vector<int>    addrs;
      vector<string> types;
      vector<int>    sizes;

      string get_value(string);
      void   put(string, string, int);
      void   put(string, string, Value);
      void   assign(string, string);

      string get_name(int);
      int    get_addr(string);
      string get_type(string);
      int    get_size(string);

      bool exist(string);

      void print();
  };
  /*
  names                  ：保存变量名
  addrs                  ：保存与变量名相绑定的首地址
  types                  ：保存与变量名相绑定的类型信息
  sizes                  ：保存变量类型的大小
  get_value(name)        ：传入变量名，返回值
  put(name, type, size)  ：定义（非初始化及赋值），传入（变量名，类型，大小），在符号表中插入变量并分配内存，无返回值
  put(name, type, value) ：定义及初始化，传入（变量名，类型，值（包含大小和具体值）），在符号表中新建条目，无返回值
  assign(name, value)    ：赋值，传入（变量名，具体值），在符号表中寻找该变量并在内存中写入值
  get_name(addr)         ：传入地址，返回变量名
  get_addr(name)         ：传入变量名，返回地址
  get_type(name)         ：传入变量名，返回类型
  get_size(name)         ：传入变量名，返回大小
  exist(name)            ：传入变量名，若符号表中存在该变量名返回true否则返回false
  print()                ：打印符号表
  */
  ```
  ```cpp
  struct Memory
  {
      int end;
      char mem[1000];

      int put(char*, int);
      char *read(int);
      void write(int, char *, int);

      void print();
  };
  /*
  end                      ：记录可用首地址
  mem[1000]                ：实际内存区域
  put(value, size)         ：传入（值，大小），返回分配内存后其首地址
  read(addr)               ：传入地址，返回值
  write(addr, value, size) ：传入（地址，值，大小），在相应地址写入数据，无返回值
  print()                  ：打印内存
  */
  ```

### 2. 数据变量定义在内存中的对齐原则是怎样的？你是如何实现变量内存地址分配算法的？
  如果变量大小为4的倍数，则直接写入值后返回首地址，否则在后边写入空白数据使其在内存中所占空间为4的倍数。

  先将对应大小的值写入内存，之后判断变量大小%4是否不为零，若不为零则继续填充(4 - size % 4)字节的无意义数据。

### 3. 基于C语言的变量声明，你如何设计实现识别变量类型的算法？这样设计是否完善？
  根据http://www.cs.man.ac.uk/~pjj/bnf/c_syntax.bnf 中描述C的BNF范式精简出满足本次实验的声明和简单赋值的BNF范式如下：
  ```
  ------------------------------------------------------------------------------
  stmt                : decl | unary_exp
                      ;
  ------------------------------------------------------------------------------
  decl                : type_spec init_declarator COMMA
                      ;
  ------------------------------------------------------------------------------
  type_spec           : TVOID | TCHAR | TSHORT | TINT | TLONG | TFLOAT | TDOUBLE
                      ;
  ------------------------------------------------------------------------------
  init_declarator     : declarator
                      | declarator EQ initializer
                      ;
  ------------------------------------------------------------------------------
  declarator          : pointer direct_declarator
                      | direct_declarator
                      ;
  ------------------------------------------------------------------------------
  pointer             : STAR pointer
                      ;
  ------------------------------------------------------------------------------
  direct_declarator   : id
                      | LPAREN declarator RPAREN
                      | direct_declarator LBRACKET RBRACKET
                      | direct_declarator LBRACKET INTEGER RBRACKET
                      | direct_declarator LBRACKET IDENTIFIER RBRACKET
                      | direct_declarator LPAREN RPAREN
                      | direct_declarator LPAREN param_list RPAREN
                      ;
  ------------------------------------------------------------------------------
  param_list          : param_decl
                      | param_decl COMMA param_list
                      ;
  ------------------------------------------------------------------------------
  param_decl          : type_sepc
                      ;
  ------------------------------------------------------------------------------
  initializer         : unary_exp
                      | LBRACE initializer_list RBRACE
                      ;
  ------------------------------------------------------------------------------
  initializer_list    : initializer COMMA initializer_list
                      | initializer
                      ;
  ------------------------------------------------------------------------------
  unary_exp           : primary_exp
                      : unary_operator unary_exp
                      ;
  ------------------------------------------------------------------------------
  unary_operator      : AND | STAR
                      ;
  ------------------------------------------------------------------------------
  primary_exp         : IDENTIFIER
                      | const
                      | STRING
                      ;
  ------------------------------------------------------------------------------
  const               : INTEGER
                      | FLOAT
                      | CHAR
                      ;
  ------------------------------------------------------------------------------
  ```
  首先实现Tokenizer得到输入语句的token流；
  之后实现Parser在根据得到的token流通过递归下降（包含回溯）分析法获得表达类型的字符串。

### 4. 对于支持下标的数组操作，你是（打算）如何实现的？

  首先获得变量名的地址，然后根据数组元素的大小与下标的值相乘之后与地址相加后得到对应下边的元素的地址后根据地址及其类型获取值。

### 5. C语言为什么要引入符号表？

  通过引入符号表，可以实现变量名与源程序中的一些语法符号的类型和特征等相关信息的绑定，可以提高编译系统的运行效率。
