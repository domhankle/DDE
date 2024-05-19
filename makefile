DEPS_LIB_DIR:=deps/libs
DEPS_INC_DIR:=deps/include
LIBS:=-lglad -lglfw3

BIN_DIR:=bin
SRC_DIR:=src
INC_DIR:=include
SRCS:=$(shell find $(SRC_DIR) -name "*.cpp")
OBJS:=$(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/$(SRC_DIR)/%.o, $(SRCS))

CC:=g++
EXECUTABLE:=$(BIN_DIR)/dom_drawing_engine

all : $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) $^ -o $(EXECUTABLE) -L$(DEPS_LIB_DIR) $(LIBS)

$(BIN_DIR)/%.o : %.cpp $(BIN_DIR)
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -I$(DEPS_INC_DIR) -I$(INC_DIR)

$(BIN_DIR) :
	mkdir $(BIN_DIR)

.PHONY clean :
	rm -r bin
