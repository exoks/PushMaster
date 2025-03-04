# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 16:46:00 by oezzaou           #+#    #+#              #
#    Updated: 2025/02/23 15:20:15 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#====<[ Colors: ]>==============================================================
GREEN					= \033[1;32m
RED						= \033[1;31m
BLUE					= \033[34m
CYAN					= \033[1;36m
GRAY					= \033[0;90m
PURPLE				= \033[0;35m
YELLOW				= \033[0;93m
BLACK  				= \033[20m
MAGENTA 			= \033[35m
WHITE  				= \033[37m
PINK					= \033[0;38;5;199m
ORANGE 				= \033[38;5;214m
LIGHT_BLACK  	= \033[90m
LIGHT_RED    	= \033[91m
LIGHT_GREEN  	= \033[92m
LIGHT_YELLOW 	= \033[93m
LIGHT_BLUE   	= \033[94m
LIGHT_MAGENTA = \033[95m
LIGHT_CYAN   	= \033[96m
LIGHT_WHITE  	= \033[97m
LIGHT_BLUE		= \033[38;5;45m
RESET					= \033[1;0m

#====<[ CC compiler: ]>=========================================================
CC						:= cc
CFLAGS				:= -Wall -Wextra -Werror
RM						:= rm -rf

#===<[ Sources: ]>==============================================================
PROJECT				:= Push_swap
NAME					:= push_swap
LIBFT					:= libft
SRC_DIR				:= src
OBJ_DIR				:= obj
INCLUDE				:= -Iinclude -I$(LIBFT)/include
SRC						:= push_swap push_swap_parser push_swap_instructions\
								 push_swap_algorithm push_swap_utils
OBJ						:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))
SRC						:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))

CHECKER				:= checker
SRC_BNS				:= checker push_swap_process push_swap_instructions\
								 push_swap_utils
OBJ_BNS 			:= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_BNS)))
SRC_BNS				:= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_BNS)))

#====<[ Tester: ]>==============================================================
TESTER				:= ./oezzaou_tester
STACK_SIZE		:= 100

#====<[ Rules: ]>===============================================================
all: signature $(NAME)

$(NAME): $(LIBFT) | $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $| -L$(LIBFT) -lft -o $@
	@echo "${GREEN}[OK] ${CYAN}$@ ✔️${RESET}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .create_dir 
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-29s| $@\n" "$<"

$(LIBFT):
	@make -s -C $@ all

signature:
	@printf "${GRAY}%19s${RESET}\n" "𓆩♕𓆪"
	@printf "${GRAY}%s${RESET}\n"		"𓄂 oussama ezzaou𓆃  "

bonus: $(OBJ_DIR) $(CHECKER)

$(CHECKER): $(LIBFT) | $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(INCLUDE) $| -L$(LIBFT) -lft -o $@
	@echo "${GREEN}[OK] ${CYAN}$@ ✔️${RESET}"

$(OBJ_DIR): 
	@mkdir -p $@

clean:
	@make -C $(LIBFT) fclean
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-29s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	else\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-29s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(OBJ_DIR) ✖️";\
	fi
	
fclean: clean
	@if [ -f $(NAME) ]; then\
		${RM} $(NAME);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-29s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME) ✔️";\
	fi
	@if [ -f $(CHECKER) ]; then\
		${RM} $(CHECKER);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-29s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(CHECKER) ✔️";\
	fi

re : fclean all

#====<[ Rules for testing: ]>=====================
# visual:
# 	./push_swap_visualizer/build/bin/visualizer

# Run this rule with this command: make test STACK_SIZE=<INT_VALUE>
test: all 
	@cd oezzaou_tester && ./run.sh -999 999 $(STACK_SIZE) 

#=================================================

.create_dir: $(OBJ_DIR)

.PHONY: all clean fclean re bonus visual test sinature $(LIBFT)
#===============================================================================
