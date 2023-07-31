TARGET := sudoku
CC := gcc

SRCS_FOLDER := src
INCLUDE_FOLDER := include
PREREQUISITES_FOLDER := prerequisites
OBJS_FOLDER := objs
BIN_FOLDER := .

ifeq ($(OS),Windows_NT)
	RM := del /Q
	SDL_INCLUDE := -I./windows/include
	LDFLAGS := -L./windows/lib
	CFLAGS += -mwindows
else
	UNAME_S := $(shell uname -s)
	RM := rm -f
	ifeq ($(UNAME_S),Linux)
		SDL_INCLUDE := -I./linux/include
		LDFLAGS := -L./linux/lib
	endif
endif

CFLAGS += -Wall -Wextra -flto -O3 -I$(INCLUDE_FOLDER) -I$(PREREQUISITES_FOLDER) -I$(SDL_INCLUDE) -MMD

SRCS_RAW := main.c	\
			graphics_init.c	\
			sudoku_init.c	\
			main_loop.c	\
			draw_grid.c	\
			backtrack.c	\
			find_empty_cell.c	\
			is_valid.c	\
			remove_numbers.c	\
			game_inputs.c	\
			count_solver.c \
			fill_candidates.c \

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