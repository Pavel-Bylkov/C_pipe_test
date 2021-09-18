# C_pipe_test
Учебный проект на языке С - цель разобраться с использованием перенаправлений потоков ввода-вывода.

make - скомпилирует pipex

./pipex file1 cmd1 cmd2 file2
работает как
< file1 cmd1 | cmd2 > file2

make bonus - добавит дополнительные возможности

./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
работает как
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

Режим << and >> когда первый параметр "here_doc"
./pipex here_doc LIMITER cmd1 cmd2 file
работает как
cmd1 << LIMITER | cmd2 >> file