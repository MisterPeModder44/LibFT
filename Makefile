NAME := libft.a

SRC_PATH := srcs
OBJ_PATH := bin
INC_PATH := includes

SRCS =
OBJS =

MODULES =

include srcs/base/base.mk

LC = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_PATH)
RM = rm -f

NORM_LOG = norm.log
NORM_FILES =

VERBOSE = 1

all: $(NAME)

premsg:
ifneq ($(VERBOSE), 1)
	@printf "\n\033[90mCompiling \033[0m$(NAME)\033[90m: \033[0m"
endif

$(NAME): premsg $(OBJS)
ifeq ($(VERBOSE), 1)
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[32mdone!"
	@printf "\n\033[90mCompiling \033[0m$(NAME)\033[90m: \033[0m"
endif
	@$(LC) $(NAME) $(OBJS)
	@printf "\033[32mdone!\n"

$(OBJS): $(SRCS)
	@mkdir $(OBJ_PATH) $(addprefix $(OBJ_PATH)/, $(MODULES)) 2> /dev/null || true
ifeq ($(VERBOSE), 1)
	@tput dl; tput cub 100; printf "\033[90mCreating object files: \033[0m$(notdir $@)"
endif
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(NORM_LOG)
	@$(RM) $(OBJS)
	@rmdir $(addprefix $(OBJ_PATH)/, $(MODULES)) $(OBJ_PATH) 2> /dev/null || true
	@printf "\033[33mRemoved \033[93mobject files!\033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[33mRemoved \033[93m$(NAME) executable!\033[0m\n\n"

re: fclean all

norm:
	@printf "\033[90mChecking \033[0mThe Norm\033[90m...\033[0m\n"
	$(eval NORM_FILES = $(SRCS) $(shell find includes -type f -name "*.h"))
	@printf "Found \033[32m%s\033[0m files!\n" $(words $(NORM_FILES))
	@$(RM) $(NORM_LOG)
	@norminette $(NORM_FILES) >> $(NORM_LOG)
	@printf "Norm Errors: "
	@cat $(NORM_LOG) | grep Error | wc -l | bc
	@printf "See \033[4m$(NORM_LOG)\033[0m for details.\n"

TESTF = srcs/printf/printf.c

test:
	echo $(notdir $(patsubst %/,%,$(dir $(TESTF))))

.PHONY: all premsg clean fclean re norm
