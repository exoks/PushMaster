#!/bin/bash

# Safegard if no posional variable are given
if [ $# -le 0 ]
then
	echo -ne "\033[1;31mpush_swap:\033[1;31m Invalid args\033[1;0m :==> [./run.sh] [MIN] [MAX] [SIZE]\n"
	exit 127
fi

if [ ! -f a.out ]
then
	gcc generator.c
fi

./a.out $1 $2 $3 > file

data=$(cat file)

./push_swap $data

echo -ne "\033[1;32m$data\033[1;0m\n"

nbr=`./push_swap $data | wc -l`

echo -ne "\n\033[1;36m=>\033[1;0m waiting "
i=0
while [ $i -lt 3 ]; do
	echo -n "."
	sleep 1
	i=$(($i + 1))
done
echo ""

if [ ${nbr} -gt 1500 ]
then
	echo -ne "\n\033[1;31m[KO]\033[1;0m :====> \033[1;32m${nbr}\033[1;0m\n"
	echo -ne "It must be less than >>> 1500\n\n\033[1;31m>>>>>>>>>> FAILURE <<<<<<<<<<\033[1;0m\n\n"
else
	echo -ne "\n\033[1;32m[OK]\033[1;0m :====> \033[1;31m${nbr}\n"
	echo -ne "\n\033[1;32m<<<<<<<<<<< SUCCESS >>>>>>>>>>\033[1;0m\n\n"
fi

 rm file

echo -ne "\033[1;32m   Made By Oussama Ezzaou :)   \033[1;0m\n"
