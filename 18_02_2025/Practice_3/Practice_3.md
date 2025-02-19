# Задача 3

## Символьная таблица для `main.o`
```
main.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 main.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  000000000000013c main
0000000000000000         *UND*  0000000000000000 printf
0000000000000000         *UND*  0000000000000000 __isoc99_scanf
0000000000000000         *UND*  0000000000000000 calculate_distance
0000000000000000         *UND*  0000000000000000 check_fuel
0000000000000000         *UND*  0000000000000000 __stack_chk_fail
```
У объектника функции `check_fuel`, `calculate_distance` и т. д. в символьной таблице имеют маркер `*UND*`. Скорее всего это сокращение от `UNDefined`, т.е. не определено. Это логично, так как в объектных файлах еще не совершена связка функций (их реализаций) из других файлов.

## Символьная таблица для `a.out`
```
SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000              abi-note.c
000000000000218c l     O .note.ABI-tag  0000000000000020              __abi_tag
0000000000000000 l    df *ABS*  0000000000000000              init.c
0000000000000000 l    df *ABS*  0000000000000000              crtstuff.c
00000000000010a0 l     F .text  0000000000000000              deregister_tm_clones
00000000000010d0 l     F .text  0000000000000000              register_tm_clones
0000000000001110 l     F .text  0000000000000000              __do_global_dtors_aux
0000000000004028 l     O .bss   0000000000000001              completed.0
0000000000003dc8 l     O .fini_array    0000000000000000              __do_global_dtors_aux_fini_array_entry
0000000000001150 l     F .text  0000000000000000              frame_dummy
0000000000003dc0 l     O .init_array    0000000000000000              __frame_dummy_init_array_entry
0000000000000000 l    df *ABS*  0000000000000000              main.c
0000000000000000 l    df *ABS*  0000000000000000              navigation.c
0000000000000000 l    df *ABS*  0000000000000000              fuel.c
0000000000000000 l    df *ABS*  0000000000000000              crtstuff.c
0000000000002188 l     O .eh_frame      0000000000000000              __FRAME_END__
0000000000000000 l    df *ABS*  0000000000000000              
0000000000003dd0 l     O .dynamic       0000000000000000              _DYNAMIC
000000000000207c l       .eh_frame_hdr  0000000000000000              __GNU_EH_FRAME_HDR
0000000000003fe8 l     O .got.plt       0000000000000000              _GLOBAL_OFFSET_TABLE_
0000000000000000       F *UND*  0000000000000000              __libc_start_main@GLIBC_2.34
0000000000000000  w      *UND*  0000000000000000              _ITM_deregisterTMCloneTable
0000000000004018  w      .data  0000000000000000              data_start
0000000000004028 g       .data  0000000000000000              _edata
00000000000012af g     F .text  0000000000000024              check_fuel
00000000000012d4 g     F .fini  0000000000000000              .hidden _fini
0000000000000000       F *UND*  0000000000000000              __stack_chk_fail@GLIBC_2.4
0000000000000000       F *UND*  0000000000000000              printf@GLIBC_2.2.5
0000000000004018 g       .data  0000000000000000              __data_start
0000000000000000  w      *UND*  0000000000000000              __gmon_start__
0000000000004020 g     O .data  0000000000000000              .hidden __dso_handle
0000000000002000 g     O .rodata        0000000000000004              _IO_stdin_used
0000000000001295 g     F .text  000000000000001a              calculate_distance
0000000000004030 g       .bss   0000000000000000              _end
0000000000001070 g     F .text  0000000000000026              _start
0000000000004028 g       .bss   0000000000000000              __bss_start
0000000000001159 g     F .text  000000000000013c              main
0000000000000000       F *UND*  0000000000000000              __isoc99_scanf@GLIBC_2.7
0000000000004028 g     O .data  0000000000000000              .hidden __TMC_END__
0000000000000000  w      *UND*  0000000000000000              _ITM_registerTMCloneTable
0000000000000000  w    F *UND*  0000000000000000              __cxa_finalize@GLIBC_2.2.5
0000000000001000 g     F .init  0000000000000000              .hidden _init
```

Как видно в символьной таблице `a.out` функции уже имеют маркер `.text`, что точно говорит о том, что они уже определены. У переменных же маркер `.data`.

# Задача 4

Глобальные переменные и функции есть в символьной таблице.

```c
#include <stdio.h>

int global_var = 10;  // Глобальная переменная, доступна из других файлов
static int static_var = 20;  // Видна только внутри file1.c

void print_from_file1() {
    printf("file1.c -> global_var = %d\n", global_var);
    printf("file1.c -> static_var = %d\n", static_var);
}
```

## Символьная таблица `file1.o`
```
SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     F .text  000000000000003f print_from_file1
0000000000000000         *UND*  0000000000000000 printf
```

В символьной таблице есть `global_var`, `static_var` с маркером `.data` - это переменные, `print_from_file1` - `.text`, так как это функция (код)

## Диззассемблирование файла `main.o`
```
Дизассемблирование раздела .text:

0000000000000000 <main>:
   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   8b 05 00 00 00 00       mov    0x0(%rip),%eax        # a <main+0xa>
   a:   89 c6                   mov    %eax,%esi
   c:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 13 <main+0x13>
  13:   48 89 c7                mov    %rax,%rdi
  16:   b8 00 00 00 00          mov    $0x0,%eax
  1b:   e8 00 00 00 00          call   20 <main+0x20>
  20:   b8 00 00 00 00          mov    $0x0,%eax
  25:   e8 00 00 00 00          call   2a <main+0x2a>
  2a:   b8 00 00 00 00          mov    $0x0,%eax
  2f:   e8 00 00 00 00          call   34 <main+0x34>
  34:   b8 00 00 00 00          mov    $0x0,%eax
  39:   5d                      pop    %rbp
  3a:   c3                      ret
```

Как видно из вывода команды, основная функция `main` имеет нулевой адрес.

## Диззассемблирование файла `a.out` (фрагмент)
```
0000000000401887 <main>:
  401887:	55                   	push   %rbp
  401888:	48 89 e5             	mov    %rsp,%rbp
  40188b:	8b 05 3f 38 0a 00    	mov    0xa383f(%rip),%eax        # 4a50d0 <global_var>
  401891:	89 c6                	mov    %eax,%esi
  401893:	48 8d 05 ca 87 07 00 	lea    0x787ca(%rip),%rax        # 47a064 <__rseq_flags+0x60>
  40189a:	48 89 c7             	mov    %rax,%rdi
  40189d:	b8 00 00 00 00       	mov    $0x0,%eax
  4018a2:	e8 29 31 00 00       	call   4049d0 <_IO_printf>
  4018a7:	b8 00 00 00 00       	mov    $0x0,%eax
  4018ac:	e8 74 ff ff ff       	call   401825 <print_from_file1>
  4018b1:	b8 00 00 00 00       	mov    $0x0,%eax
  4018b6:	e8 a9 ff ff ff       	call   401864 <print_from_file2>
  4018bb:	b8 00 00 00 00       	mov    $0x0,%eax
  4018c0:	5d                   	pop    %rbp
  4018c1:	c3                   	ret
  4018c2:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4018c9:	00 00 00 
  4018cc:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4018d3:	00 00 00 
  4018d6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
  4018dd:	00 00 00 

```

Функция `main` в уже полностью скомпилированном файле имеет другой адрес, так как помимо самой функции там уже проведена линковка и адресация не соответствует объектному файлу до этого.