TARGET := sudoku
CC := gcc

SRCS_FOLDER := src
INCLUDE_FOLDER := include
PREREQUISITES_FOLDER := prerequisites
OBJS_FOLDER := objs
BIN_FOLDER := .

SDL_INCLUDE := -IC:\msys64\mingw64\include

CFLAGS := -Wall -Wextra -flto -O3 -I$(INCLUDE_FOLDER) -I$(PREREQUISITES_FOLDER) -I$(SDL_INCLUDE) -MMD
LDFLAGS := -LC:\msys64\mingw64\lib -lSDL2 -lSDL2_ttf

SRCS_RAW := main.c

SRCS := $(addprefix $(SRCS_FOLDER)/, $(SRCS_RAW))
OBJS := $(SRCS:$(SRCS_FOLDER)/%.c=$(OBJS_FOLDER)/%.o)
DEPS := $(OBJS:.o=.d)
PREREQUISITES := $(wildcard $(PREREQUISITES_FOLDER)/*.c)

.PHONY: all clean re fclean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN_FOLDER)/$@ $^

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

test: all
	$(BIN_FOLDER)/$(TARGET)