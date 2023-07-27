TARGET := sudoku
CC := gcc

SRCS_FOLDER := src
INCLUDE_FOLDER := include
PREREQUISITES_FOLDER := prerequisites
OBJS_FOLDER := objs
BIN_FOLDER := .

SDL_INCLUDE := -I./include

CFLAGS := -Wall -Wextra -flto -O3 -I$(INCLUDE_FOLDER) -I$(PREREQUISITES_FOLDER) -I$(SDL_INCLUDE) -MMD -mwindows
LDFLAGS := -L./lib/

SRCS_RAW := main.c	\
			graphics_init.c	\
			sudoku_init.c	\
			main_loop.c	\
			draw_grid.c	\
			backtrack.c	\
			find_empty_cell.c	\
			is_valid.c	\
			remove_numbers.c	\
			idiot_solver.c	\
			game_inputs.c	\

SRCS := $(addprefix $(SRCS_FOLDER)/, $(SRCS_RAW))
OBJS := $(SRCS:$(SRCS_FOLDER)/%.c=$(OBJS_FOLDER)/%.o)
DEPS := $(OBJS:.o=.d)
PREREQUISITES := $(wildcard $(PREREQUISITES_FOLDER)/*.c)

.PHONY: all clean re fclean test clear

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_FOLDER)/$@ $^ -lSDL2 -lSDL2_ttf

$(OBJS_FOLDER)/%.o: $(SRCS_FOLDER)/%.c | $(OBJS_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)

-include $(DEPS)

$(OBJS_FOLDER):
	mkdir -p $(OBJS_FOLDER)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(BIN_FOLDER)/$(TARGET)

re: fclean all

clear:
	clear

test: clear all
	$(BIN_FOLDER)/$(TARGET)