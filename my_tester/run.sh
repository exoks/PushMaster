#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                  𓐓  run.sh 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀  Student: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2025/02/19 15:42:39 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/02/20 12:24:11 by oezzaou
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

printf "${GREEN}❯${RESET} waiting "
for second in {1..3}; do 
  printf "."; sleep 1;
done
printf "\n\n";

#=== args <ctr: instruction counter | max: max instruction> 
print_results() {
  echo "${GREEN}❯${RESET} sb  | ${sb}"
  echo "${GREEN}❯${RESET} ra  | ${ra}"
  echo "${GREEN}❯${RESET} rb  | ${rb}"
  echo "${GREEN}❯${RESET} rr  | ${rr}"
  echo "${GREEN}❯${RESET} pa  | ${pa}"
  echo "${GREEN}❯${RESET} pb  | ${pb}"
  echo "${GREEN}❯${RESET} rra | ${rra}"
  echo "${GREEN}❯${RESET} rrb | ${rrb}"
  echo "${GREEN}❯${RESET} rrr | ${rrr}"

  if [ $1 -le $2 ]; then
    printf "\n❯ ${GREEN}[OK] ${YELLOW}%s${RESET}\n" "Inst: $1 <= Max_Inst: $2"
    printf "\n${GREEN}%40s${RESET}\n\n" "<<<<<<<<<<< SUCCESS >>>>>>>>>>";
  else
    printf "\n❯ ${RED}❯ [KO]: ${YELLOW} $1 > $2 ${RESET}\n";
    printf "\n${RED}%40s${RESET}\n\n"   ">>>>>>>>>>> FAILURE <<<<<<<<<<";
  fi 
}

if [ $3 -eq 3 ]; then
  print_results ${ctr} "100"
elif [ $3 -eq 5 ]; then
  print_results ${ctr} "100"
elif [ $3 -eq 100 ]; then
  print_results ${ctr} "700"
elif [ $3 -eq 500 ]; then
  print_results ${ctr} "5500"
else
  printf "❯ ${PURPLE}Instructions counter: ${RESET}${ctr}";
fi

#=== Programmer signature: oezzaou ===
printf "${GRAY}%19s${RESET}\n" "𓆩♕𓆪"
printf "${GRAY}%s${RESET}\n\n" "𓄂 oussama ezzaou𓆃  "
#===============================================================================
