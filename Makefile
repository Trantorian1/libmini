# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 10:26:52 by marvin            #+#    #+#              #
#    Updated: 2023/11/24 11:50:04 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==================================[ COLOR ]================================= #

RESET      = \033[0m
BOLD       = \033[1m
DIM        = \033[2m
ITALIC     = \033[3m
UNDERLINE  = \033[4m
BLINK      = \033[5m
REVERSE    = \033[7m
HIDDEN     = \033[8m

BLACK      = \033[30m
RED        = \033[31m
GREEN      = \033[32m
YELLOW     = \033[33m
BLUE       = \033[34m
MAGENTA    = \033[35m
CYAN       = \033[36m
WHITE      = \033[37m

BLACK_BG   = \033[40m
RED_BG     = \033[41m
GREEN_BG   = \033[42m
YELLOW_BG  = \033[43m
BLUE_BG    = \033[44m
MAGENTA_BG = \033[45m
CYAN_BG    = \033[46m
WHITE_BG   = \033[47m

# ==================================[ SETUP ]================================= #

DIR_BUILD  = .
DIR_OBJS   = $(DIR_BUILD)/objs
DIR_DEPS   = $(DIR_BUILD)/deps
DIR_SRCS   = ./src
DIR_INCL   = ./include
DIR_BIN    = ./bin

FILES_SRCS = $(shell find . -wholename "$(DIR_SRCS)/*.cpp")
FILES_OBJS = $(patsubst $(DIR_SRCS)/%.cpp,$(DIR_OBJS)/%.o,$(FILES_SRCS))
FILES_DEPS = $(patsubst $(DIR_SRCS)/%.cpp,$(DIR_DEPS)/%.d,$(FILES_SRCS))

OPT        = 
DEBUG      =
LIBS       =

C_COMPILER = g++
I_FLAGS    = $(foreach dir,$(DIR_INCL),-I$(dir) )
SILENCED   = 
C_FLAGS    = -Wall -Wextra -Werror $(SILENCED) $(OPT) $(DEBUG) $(I_FLAGS)
C_DEPS     = -MM -MP $(I_FLAGS)

BIN        = phonebook

# =================================[ BINARY ]================================= #

all: $(BIN)

$(BIN): $(FILES_OBJS) $(FILES_DEPS)
# 	displays build command
	@printf "$(BOLD)$(BLUE)building $(WHITE)%-30s$(RESET) $(CYAN)$(C_COMPILER) \
             $(C_FLAGS) $(FILES_OBJS) -o $(BIN) $(LIBS)$(RESET)\n" "$@"
# 	builds binary
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) -o $(BIN) $(FILES_OBJS)

# =================================[ OBJECTS ]================================ #

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp
# 	displays build command
	@printf "$(GREEN)building $(WHITE)%-30s$(RESET) $(CYAN)$(C_COMPILER) \
             $(C_FLAGS)\n$(RESET)" "$(notdir $@)"
# 	builds object file
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) -c $< -o $@

# ==============================[ DEPENDENCIES ]============================== #

$(DIR_DEPS)/%.d: $(DIR_SRCS)/%.cpp
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(C_DEPS) -MT $(DIR_OBJS)/$*.o -MF $@ $<

# =================================[ CLEANUP ]================================ #

clean:
	@echo "$(RED)removing $(WHITE)*.o$(RESET)"
	@rm -f $(FILES_OBJS)
	@echo "$(RED)removing $(WHITE)*.d$(RESET)"
	@rm -f $(FILES_DEPS)



fclean: clean
	@echo "$(BOLD)$(RED)removing $(WHITE)$(BIN)$(RESET)"
	@rm -f $(BIN)



re: fclean
	@make -s all



debug:
	@echo $(FILES_SRCS)
	@echo $(FILES_OBJS)
	@echo $(FILES_DEPS)
	@echo $(C_FLAGS)



-include $(FILES_DEPS)



.PHONY: all submodules clean fclean re debug
