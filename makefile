DEPS_LIB_DIR:=deps/libs
DEPS_INC_DIR:=deps/include
LIBS:=-lglad -lglfw3

BIN_DIR:=bin
ROOT_DIR:=DDE
SRCS:=$(shell find $(ROOT_DIR) -name "*.cpp")
OBJS:=$(patsubst $(ROOT_DIR)/%.cpp, $(BIN_DIR)/$(ROOT_DIR)/%.o, $(SRCS))

CC:=g++
EXECUTABLE:=$(BIN_DIR)/dom_drawing_engine

.PHONY all : $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE) : $(OBJS)
	$(CC) $< -o $(EXECUTABLE) -L$(DEPS_LIB_DIR) $(LIBS)

$(BIN_DIR)/%.o : %.cpp $(BIN_DIR)
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ -I$(DEPS_INC_DIR)

$(BIN_DIR) :
	mkdir $(BIN_DIR)

.PHONY clean :
	rm -r bin
