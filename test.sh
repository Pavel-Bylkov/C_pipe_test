#!/bin/bash

echo "*************** Make Pipex ****************"
make
echo ""
echo "*************** Test Pipex errors ****************"
rm -rf infile outfile_origin outfile
echo "***Test lost arguments***"
./pipex infile "ls -l" outfile
echo "***Test more arguments***"
./pipex infile "ls -l" "grep a1" "wc -l" outfile
echo "***Test infile not found***"
./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l > outfile_origin
echo "***Test infile out in arguments***"
./pipex "ls -l" "cat -e" "wc -l" outfile
echo "a1" > infile
echo "a2" >> infile
echo "a3" >> infile
echo "a4" >> infile
echo "***Test cmd1 not found***"
./pipex infile "ls55 -l" "wc -l" outfile
< infile ls55 -l | wc -l > outfile_origin
echo "***Test cmd2 not found***"
./pipex infile "ls -l" "wc55 -l" outfile
< infile ls -l | wc55 -l > outfile_origin
echo ""
echo "*************** Test Pipex works ****************"
echo ""
echo "< infile ls -l | wc -l > outfile_origin"
./pipex infile "ls -l" "wc -l" outfile
< infile ls -l | wc -l > outfile_origin
diff outfile outfile_origin
echo ""
echo "< infile grep a1 | wc -w > outfile_origin"
./pipex infile "grep a1" "wc -w" outfile
< infile grep a1 | wc -w > outfile_origin
diff outfile outfile_origin
echo ""
echo "< infile cat -e | grep a1 > outfile_origin"
./pipex infile "cat -e" "grep a1" outfile
< infile cat -e | grep a1 > outfile_origin
diff outfile outfile_origin

echo ""
echo "*************** Test Pipex leaks ****************"
echo ""
leaks --atExit -- ./pipex infile "cat -e" "grep a1" outfile