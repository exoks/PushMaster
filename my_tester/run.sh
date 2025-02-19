#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                  𓐓  run.sh 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀  Student: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/19 15:42:39 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/19 20:50:51 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#!/bin/bash

#====<[ Variables: ]>===========================================================
gen_src="generator.c"
gen_exec="generator"

#====<[ Colors: ]>==============================================================
GREEN="\033[1;32m"
CYAN="\033[1;36m"
PINK="\033[0;38;5;199m"
RED="\033[1;31m"
RESET="\033[1;0m"

#====<[ Script: ]>==============================================================
if [ $# -le 0 ]
then
	echo "${CYAN}run.sh:${RESET} Invalid args${RED}: ./run.sh [MIN] [MAX] [SIZE]"
	exit 127
fi

if [ ! -f generator ]; then
  cc  generator.c -o generator;
  printf "${GREEN}[OK]${RESET}: ${PINK}Compiling${RESET} %-29s| ${gen_exec}\n" "${gen_src}";
else
	echo "${GREEN}[OK]: ${CYAN}${gen_exec} ✔️${RESET}"
fi

# if [! -f generator]
#
# generator $1 $2 $3 > file
#
# data=$(cat file)
#
# ./../push_swap $data
#
# echo -ne "\033[1;32m$data\033[1;0m\n"
#
# all=`./../push_swap $data`
# nbr=`echo "$all" | wc -l`
# ra=`echo "$all" | awk '/^ra$/' | wc -l`
# rb=`echo "$all" | awk '/^rb$/' | wc -l`
# rr=`echo "$all" | awk '/^rr$/' | wc -l`
# pb=`echo "$all" | awk '/^pb$/' | wc -l`
# pa=`echo "$all" | awk '/^pa$/' | wc -l`
# sb=`echo "$all" | awk '/^sb$/' | wc -l`
# rra=`echo "$all" | awk '/^rra$/' | wc -l`
# rrb=`echo "$all" | awk '/^rrb$/' | wc -l`
# rrr=`echo "$all" | awk '/^rrr$/' | wc -l`
#
# echo -ne "\n\033[1;36m=>\033[1;0m waiting "
# i=0
# while [ $i -lt 3 ]; do
# 	echo -n "."
# 	sleep 1
# 	i=$(($i + 1))
# done
# echo -ne "\n"
#
# if [ ${nbr} -gt 1500 ]
# then
# 	echo -ne "\n\033[1;31m[KO]\033[1;0m :====> \033[1;32m${nbr}\033[1;0m\n"
# 	echo -ne "It must be less than >>> 1500\n\n\033[1;31m>>>>>>>>>> FAILURE <<<<<<<<<<\033[1;0m\n\n"
# else
# 	echo -ne "\n\033[1;32m[OK]\033[1;0m :====> \033[1;31m${nbr}\n"
# 	echo -ne "\n\033[1;32m<<<<<<<<<<< SUCCESS >>>>>>>>>>\033[1;0m\n\n"
# fi
#
# rm file
# echo -ne "sb :=> $sb\nra :=> $ra\nrb :=> $rb\nrr :=> $rr\npa :=> $pa\npb :=> $pb\nrra :=> $rra\nrrb :=> $rrb\nrrr :=> $rrr\n"
# echo -ne "\033[1;32m   Made By Oussama Ezzaou :)   \033[1;0m\n"
