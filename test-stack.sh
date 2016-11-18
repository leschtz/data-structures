#! /bin/sh

if [ -f stack ]
  then
    rm stack
fi

if [ -f stack.c ]
  then
    gcc -Wall -o stack stack.c
  else
    echo "File 'stack.c' not found."
    exit -1
fi

./stack > stack.txt

PUSH=$(cat stack.txt | grep 'PUSH:' | sed 's/[^0-9]//g')
printf "%4d\n" ${PUSH} > PUSH
POP=$(tac stack.txt | grep 'POP:' | sed 's/[^0-9]//g')
printf "%4d\n" ${POP} > POP

DIFF=$(diff PUSH POP)
if [ "$DIFF" != "" ]
  then
    echo "The operations failed."
    exit -2
  else
    echo "The stack did work correctly."
    exit 0
fi
