#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                  𓐓  run.sh 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀  Student: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/19 15:42:39 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/20 10:50:59 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#!/bin/bash

#====<[ Variables: ]>===========================================================
gen_src="generator.c"
gen_exec="generator"
push_swap_path=../push_swap

#====<[ Colors: ]>==============================================================
GREEN="\033[1;32m"
CYAN="\033[1;36m"
PINK="\033[0;38;5;199m"
YELLOW="\033[0;93m"
RED="\033[1;31m"
GRAY="\033[0;90m"
RESET="\033[1;0m"

#====<[ Script: ]>==============================================================
if [ $# -le 0 ]
then
	echo "${CYAN}run.sh:${RESET} Invalid args${RED}: ./run.sh [MIN] [MAX] [SIZE]"
	exit 127
fi

if [ ! -f generator ]; then
  cc ${gen_src} -o ${gen_exec};
  if [ $? -ne 0 ]; then
    echo "${YELLOW}run.sh${RESET}: ${RED}compiling error${RESET} > ${gen_src}"
    exit 1;
  fi
  printf "${GREEN}[OK]${RESET}: ${PINK}Compiling${RESET} %-22s| ${gen_exec}\n"\
         "${gen_src}";
fi
echo "${GREEN}[OK]: ${CYAN}${gen_exec} ✔️${RESET}";

#===
rand_nbr=`./${gen_exec} $1 $2 $3`

echo "${GREEN}${rand_nbr}${RESET}"

cmds=`./${push_swap_path} ${rand_nbr}`
ra=`echo  "${cmds}" | awk '/^ra$/'  | wc -l`
rb=`echo  "${cmds}" | awk '/^rb$/'  | wc -l`
rr=`echo  "${cmds}" | awk '/^rr$/'  | wc -l`
pb=`echo  "${cmds}" | awk '/^pb$/'  | wc -l`
pa=`echo  "${cmds}" | awk '/^pa$/'  | wc -l`
sb=`echo  "${cmds}" | awk '/^sb$/'  | wc -l`
rra=`echo "${cmds}" | awk '/^rra$/' | wc -l`
rrb=`echo "${cmds}" | awk '/^rrb$/' | wc -l`
rrr=`echo "${cmds}" | awk '/^rrr$/' | wc -l`
ctr=`echo "${cmds}" | wc -l`

printf "${RED}root${RESET}@${GREEN}oezzaou${RESET}❯${GRAY} waiting ${RESET}"
for second in {1..3}; do 
  printf "."; sleep 1;
  if [ ${second} -eq 3 ]; then
    printf "\n";
  fi
done

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
