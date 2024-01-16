NAME                    := libft.a
PROJECT	                := libft
CC                      := cc
CFLAGS                  := -Wall -Wextra -Werror

SRC_DIR                 := ./srcs/
OBJ_DIR                 := ./objs/
HEADER_DIR              := header

BITMASK_DIR             := bit_mask/
LINKED_LIST_DIR         := data_structure/linked_list/
QUEUE_DIR               := data_structure/queue/
DISPLAY_DIR             := display/
IMPLEMENTATION_DIR      := implementation/
GNL_DIR                 := $(IMPLEMENTATION_DIR)/get_next_line/
FT_PRINTF_DIR           := $(IMPLEMENTATION_DIR)/ft_printf/
IS_VERIFICATION_DIR     := is_verification/
MEMORY_DIR              := memory/
NUMERIC_DIR             := numeric/
STRING_DIR              := string/

# Colors for visual effects
BLACK                   := \033[0;30m
RED                     := \033[0;31m
GREEN                   := \033[0;32m
YELLOW                  := \033[0;33m
BLUE                    := \033[0;34m
PURPLE                  := \033[0;35m
CYAN                    := \033[0;36m
WHITE                   := \033[0;37m
DEF_COLOR               := \033[0;39m
LF                      := \e[1K\r

SRCS_BIT_MASK           :=  $(addprefix $(BITMASK_DIR), \
                            ft_is_bit_set_7.c \
                            ft_is_bit_set_8.c)

SRCS_LINKED_LIST        :=  $(addprefix $(LINKED_LIST_DIR), \
                            ft_lstadd_back.c \
                            ft_lstadd_front.c \
                            ft_lstclear.c \
                            ft_lstdelone.c \
                            ft_lstiter.c \
                            ft_lstlast.c \
                            ft_lstmap.c \
                            ft_lstnew.c \
                            ft_lstsize.c)

SRCS_QUEUE              :=  $(addprefix $(QUEUE_DIR), \
                            enqueue.c \
                            dequeue.c \
                            is_empty.c)

SRCS_DISPLAY            :=  $(addprefix $(DISPLAY_DIR), \
                            ft_putchar_fd.c \
                            ft_putendl_fd.c \
                            ft_putnbr_fd.c \
                            ft_putstr_fd.c \
						    ft_putstr.c)

SRCS_GNL                :=  $(addprefix $(GNL_DIR), \
                            get_next_line.c \
                            get_next_line_utils.c)

SRCS_FT_PRINTF          :=  $(addprefix $(FT_PRINTF_DIR), \
                            ft_printf.c \
                            ft_printf_hex.c \
                            ft_printf_utils.c \
                            ft_printf_utils2.c \
                            ft_printf_utils3.c)

SRCS_IS_VERIFICATION    :=  $(addprefix $(IS_VERIFICATION_DIR), \
                            ft_isalnum.c \
                            ft_isalpha.c \
                            ft_isascii.c \
                            ft_isdigit.c \
                            ft_isprint.c)

SRCS_MEMORY             :=  $(addprefix $(MEMORY_DIR), \
                            ft_calloc.c \
                            ft_calloc_exit.c \
                            ft_memchr.c \
                            ft_memcmp.c \
                            ft_memcpy.c \
                            ft_memmove.c \
                            ft_memset.c)

SRCS_NUMERIC            :=  $(addprefix $(NUMERIC_DIR), \
                            ft_atoi.c \
                            ft_atoi_original.c \
                            ft_itoa.c)

SRCS_STRING             :=  $(addprefix $(STRING_DIR), \
                            ft_bzero.c \
                            ft_split.c \
                            ft_split_quotation.c \
                            ft_split_quotation_utils.c \
                            ft_strchr.c \
                            ft_strcmp.c \
                            ft_strdup.c \
                            ft_striteri.c \
                            ft_strjoin_free.c \
                            ft_strjoin.c \
                            ft_strlcat.c \
                            ft_strlcpy.c \
                            ft_strlen_null.c \
                            ft_strlen.c \
                            ft_strmapi.c \
						    ft_strncmp.c \
                            ft_strnstr.c \
                            ft_strrchr.c \
                            ft_strtrim.c \
                            ft_substr.c \
                            ft_tolower.c \
                            ft_toupper.c)

SRCS                    :=  $(SRCS_BIT_MASK) \
                            $(SRCS_LINKED_LIST) \
                            $(SRCS_QUEUE) \
                            $(SRCS_DISPLAY) \
                            $(SRCS_GNL) \
                            $(SRCS_FT_PRINTF) \
                            $(SRCS_IS_VERIFICATION) \
                            $(SRCS_MEMORY) \
                            $(SRCS_NUMERIC) \
                            $(SRCS_STRING)

OBJS                    :=  $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

# Header file dependencies
HEADER_FILES            :=  $(HEADER_DIR)/libft.h \
                            $(HEADER_DIR)/get_next_line.h \
                            $(HEADER_DIR)/ft_printf.h \

TOTAL_FILES             :=  $(words $(SRCS))
CURRENT_FILE            :=  1

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
progress_bar           = 		printf "$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
          					    printf "$(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
   	        				    printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A\033[999C\e[?25l"; \

# # for eval
# progress_bar 					= 	printf "\033[2K$(LF)$(RED)[ ♔Compiling...♔ ]$(DEF_COLOR) $(CYAN)[$(CURRENT_FILE)/$(TOTAL_FILES)]$(DEF_COLOR) [$(Yellow)%0.1f%%$(DEF_COLOR)] $(DEF_COLOR)\b" $$(echo "scale=1; ($(CURRENT_FILE) * 100) / $(TOTAL_FILES)" | bc); \
# 		    						printf " $(YELLOW)[%-*s%s]$(DEF_COLOR)" 38 "$$(printf '%0.*s' $$(($$(($(CURRENT_FILE) * 38)) / $(TOTAL_FILES))) '=========================================================================')>" ""; \
#     								printf "\n\033[2K$(DEF_COLOR)  ✔︎ $(CYAN)Compiling... $< $(DEF_COLOR) \033[A";

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\n\n$(GREEN)Compilation complete.$(DEFAULT_COLOR) $(NAME) has been created.\e[?25h"
	@sleep 0.5

#ifdef BONUS
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#	@echo "$(GREEN)|    🎉  $(PROJECT) bonus compile success.  🎉  |$(DEFAULT_COLOR)"
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#else
#	@echo
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#	@echo "$(GREEN)|      🥳  $(PROJECT) compile success. 🥳          |$(DEFAULT_COLOR)"
#	@echo "$(GREEN)===============================================$(DEFAULT_COLOR)"
#endif

$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))
	@sleep 0.01

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep 0.5

fclean:
	@make clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"
	@sleep 1
	@clear

re:
	@sleep 0.5
	@clear
	@make fclean
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re
