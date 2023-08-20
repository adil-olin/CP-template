#!/bin/bash
set -e
if [ "$#" -eq 0 ]
then
    echo "No arguments supplied"
    exit 1
fi
Cflag="g++ -std=c++17 -DOL_IN_ONE -Wall -Wextra -O2 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2"
code=$1

$Cflag $code -o code
$Cflag gen.cpp -o gen
$Cflag brute.cpp -o brute
# if there need to be check the solution where there may or may not be a solution or more than one solution
if [ "$#" -eq 2 ]
then
    $Cflag checker.cpp -o checker
fi

for((i=0;i<10;++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer

    if [ "$#" -eq 2 ]
    then
        ./checker < input_file > checker_log
    fi

    if [ "$#" -eq 1 ]
    then
        diff -Z myAnswer correctAnswer > /dev/null || break
    fi
    
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer