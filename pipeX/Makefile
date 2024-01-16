# [TARGET]
NAME            :=  pipex

# [DEBUG OPTION]
DEBUG          		:=  -fsanitize=address -g3 # basic leak test
DEBUG2      		:=  -g #leaks -> export mallocstack=1 : locates the exact root of the memory leak

# [COMPILATION FLAGS]
CFLAGS  	      	:=  -Wall -Wextra -Werror 
# CFLAGS        		:=  -Wall -Wextra -Werror $(DEBUG)
# CFLAGS        		:=  -Wall -Wextra -Werror $(DEBUG2)
# CFLAGS        		:=  $(DEBUG)

CC					:=  cc

# [MAINSTREAM DIR]
SRC_DIR         :=  ./srcs/
OBJS_DIR        :=  ./objs/
HEADER_DIR      :=  header

# [HEADER DIR FOR ARCHIVE]
AR_HEADER_DIR   :=  srcs/ar/header/
AR_HEADER_FILES :=  $(AR_HEADER_DIR)/libft.h \
					$(AR_HEADER_DIR)/ft_printf.h \
					$(AR_HEADER_DIR)/get_next_line.h

# [COLOR SETTINGS]
BLACK           :=  \033[0;30m
RED             :=  \033[0;31m
GREEN           :=  \033[0;32m
YELLOW          :=  \033[0;33m
BLUE            :=  \033[0;34m
PURPLE          :=  \033[0;35m
CYAN            :=  \033[0;36m
WHITE           :=  \033[0;37m
DEF_COLOR       :=  \033[0;39m
LF              :=  \e[1K\r

# # =========================================================================================== #

# ifeq ($(filter $(MAKECMDGOALS), bonus), bonus)
# SRC_DIR		= src_bonus/
# SRCS        = $(addprefix $(SRC_DIR), $(SRC_BONUS))
# OBJ         = $(SRC_BONUS:.c=.o)
# OBJS        = $(addprefix $(OBJ_BONUS_DIR), $(OBJ))
# else
# SRC_DIR		= src/
# SRCS        = $(addprefix $(SRC_DIR), $(SRC))
# OBJ         = $(SRC:.c=.o)
# OBJS        = $(addprefix $(OBJ_DIR), $(OBJ))
# endif

# # =========================================================================================== #

# # ================================== MANDATORY PART ======================================= #

###############################################################################################
############################### [MANDATORY directory] #########################################
###############################################################################################

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #
# [HEADER FILES]
HEADER_MANDATORY_DIR			:=  $(HEADER_DIR)/mandatory/
HEADER_FILES_MANDATORY			:=  $(HEADER_MANDATORY_DIR)pipex.h

# [MANDATORY DEFAULT DIRECTORIES]
MANDATORY						:= $(SRC_DIR)mandatory/

# [MANDATORY DIRECTORIES]

#[MANDATORY SRCS FILE CLASS]
SRCS_MAIN						:=	$(addprefix $(MANDATORY), \
									data_manipulation.c \
									error_mng.c \
									main.c \
									process.c)

# [AGGREGATION OF ALL MANDATORY CLASSES]
SRCS							:=	$(SRCS_MAIN)
						
# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [MANDATORY OBJS DIRECTORY]
OBJS 				    		:= $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

##############################################################################################
##############################################################################################
##############################################################################################

# [LIBFT ARCHIVE DIRECTORY]
LIB_DIR 			   			:= ./srcs/ar/
LIB 				   			:= $(LIB_DIR)libft.a

# [PROGRESS BAR SETTING]
# [FILE DATA]
TOTAL_FILES 	        		:= $(words $(SRCS))
CURRENT_FILE 		    		:= 1

# [BAR DATA]

# past
# progress_bar            =   printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) \
# 			                $(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" \
# 			                "$(CURRENT_FILE)/$(TOTAL_FILES)" \
# 			                "$(shell seq -s '>' \
# 			                $$(echo "$(CURRENT_FILE) / $(TOTAL_FILES) * 50" | bc -l) \
# 			                | sed 's/[0-9]//g')"; \
# 			                printf "\033[s\n\033[K$(WHITE)   \
# 			                ✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# for dev
progress_bar 					= 	printf "\033[2K$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
		    						printf " $(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
   								printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A";

# # for eval
# progress_bar           = 		printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
# 								printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
# 								printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A\033[999C\e[?25l"; \

# [MAKE ALL : MANDATORY RULE]
all: $(OBJS_DIR) $(NAME)

# [CREATING TARGET FILE + LIBFT ARCHIVE(libft.a)]
$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|     🥳  [$(NAME)] compile success. 🥳         |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

# [CREATING OBJECT FILES]
$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY) $(AR_HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_MANDATORY_DIR) -I$(AR_HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep 0.1
	
# [CREATING OBJECT DIRECTORY]
$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# =========================================================================================== #

# ===================================== BONUS PART ========================================== #
###############################################################################################
################################# [BONUS directory] ###########################################
###############################################################################################

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [TARGET]
BONUS_NAME 					:=  pipex_bonus
# [HEADER FILES]
HEADER_BONUS_DIR			:=	$(HEADER_DIR)/bonus/
HEADER_FILES_BONUS			:=	$(HEADER_BONUS_DIR)pipex_bonus.h

# [BONUS DEFAULT DIRECTORIES]
BONUS_DIR					:=	$(SRC_DIR)bonus/

# [BONUS DIRECTORIES]
BONUS_MAIN					:=	$(BONUS_DIR)

#[BONUS SRCS FILE CLASS]
SRCS_BONUS_MAIN				:=	$(addprefix $(BONUS_MAIN), \
								data_manipulation_bonus.c \
								error_mng_bonus.c \
								main_bonus.c \
								process_bonus.c)

#[AGGREGATION OF ALL BONUS CLASSES]
SRCS_BONUS				:=	$(SRCS_BONUS_MAIN)

# [BONUS OBJS DIRECTORY]
OBJ_DIR_BONUS		  	:=	$(OBJS_DIR)bonus/

# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ #

# [BONUS OBJS DIRECTORY]
OBJS_BONUS				:=	$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))

#################################################################################
#################################################################################
#################################################################################

# [MAKE BONUS : BONUS RULE]
bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)

# [PROGRESS BAR SETTING]
# [FILE DATA]
TOTAL_FILES_BONUS			:=	$(words $(SRCS_BONUS))
CURRENT_FILE_BONUS			:=	1

# [BAR DATA]
# PAST
# progress_bar2		=	printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) \
# 						$(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s] \
# 						$(DEF_COLOR)" "$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)" \
# 						"$(shell seq -s '>' \
# 						$$(echo "$(CURRENT_FILE_BONUS) / $(TOTAL_FILES_BONUS) * 50" | bc -l) \
# 						| sed 's/[0-9]//g')"; \
# 						printf "\033[s\n\033[K$(WHITE)   \
# 						✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

# FOR DEV
progress_bar2 					= 	printf "\033[2K$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE_BONUS) * 100) / $(TOTAL_FILES_BONUS)" | bc); \
		    						printf " $(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE_BONUS) * 38)) / $(TOTAL_FILES_BONUS))) '=========================================================================')>" ""; \
   								printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A";

# # FOR EVAL
# progress_bar2			= 		printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE_BONUS) * 100) / $(TOTAL_FILES_BONUS)" | bc); \
# 								printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE_BONUS) * 38)) / $(TOTAL_FILES_BONUS))) '=========================================================================')>" ""; \
# 								printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A\033[999C\e[?25l"; \

# [CREATING BONUS OBJECT FILES]
$(OBJS_BONUS): objs/%.o: srcs/%.c $(HEADER_FILES_BONUS)
	@mkdir -p $(@D)
	@$(call progress_bar2)
	@$(CC) $(CFLAGS) -I$(HEADER_BONUS_DIR) -I$(AR_HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE_BONUS := $(shell expr $(CURRENT_FILE_BONUS) + 1))
	@sleep 0.1

# [CREATING BONUS TARGET FILE + LIBFT ARCHIVE(libft.a) -> if necessary]
$(BONUS_NAME): $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|  🎉  [$(BONUS_NAME)] compile success.  🎉     |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

# [CREATING BONUS OBJECT DIRECTORY]
$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJS_DIR)
	@mkdir $(OBJ_DIR_BONUS)

# =========================================================================================== #


# ============================================================================================= #
# [LIBFT ARCHIVE FILE]

$(LIB): $(AR_HEADER_FILES)	
	@sleep 0.5
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep 0.5
# ============================================================================================= #

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"	
	@sleep 1
	@clear

re: fclean
	@sleep 0.7
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
