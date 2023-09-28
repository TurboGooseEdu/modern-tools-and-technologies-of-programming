# Отчет по заданию
Используемая ОС: MacOS

## Выводы в консоль
```shell
➜  01.IO_Flush git:(main) ✗ ./a.out 0 0          
STDERRSTDOUT                                                                                                                                                           
➜  01.IO_Flush git:(main) ✗ ./a.out 1 0
STDOUTSTDERR                                                                                                                                                           
➜  01.IO_Flush git:(main) ✗ ./a.out 0 1
STDOUT
STDERR
➜  01.IO_Flush git:(main) ✗ ./a.out 1 1
STDOUT
STDERR
```

## Выводы в файл

Команды:

```shell
➜  01.IO_Flush git:(main) ✗ ./a.out 0 0 &> 00.txt
➜  01.IO_Flush git:(main) ✗ ./a.out 1 0 &> 10.txt
➜  01.IO_Flush git:(main) ✗ ./a.out 0 1 &> 01.txt
➜  01.IO_Flush git:(main) ✗ ./a.out 1 1 &> 11.txt
```

00.txt
```
STDERRSTDOUT
```

10.txt
```
STDOUTSTDERR
```

01.txt
```
STDERR
STDOUT

```

11.txt
```
STDOUT
STDERR

```
