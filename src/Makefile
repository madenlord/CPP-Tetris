# Directories for .o, .dll, .exe, .hpp, .d and .cpp files.
OBJ_DIR  = ../obj
BIN_DIR  = ../bin
DEP_DIR  = $(OBJ_DIR)/deps
INC_DIR  = ../include
LIB_DIR  = ../libraries
SRC_DIR  = .

# Target program
TARGET   = $(BIN_DIR)/sfml-app

# All source, object and dependency files
SRCS     := $(wildcard *.cpp)
OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS	 := $(SRCS:%.cpp=$(DEP_DIR)/%.d)

# Libraries variables
SFML_DIR = $(LIB_DIR)/SFML-2.5.1
SFML_INC = $(SFML_DIR)/include
LIBS     = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Compilation flags and options
CFLAGS   = -Wall -I$(INC_DIR) -I$(SFML_INC)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
SFML_DIR = $(LIB_DIR)/SFML-2.5.1
LIBS     = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

$(TARGET) : $(OBJS)
	g++ $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d | $(DEP_DIR)
	g++ -c $(CFLAGS) $(DEPFLAGS) -o $@ -c $<

$(DEP_DIR) : ; @mkdir -p $@

$(DEPS) :

include $(wildcard $(DEPS))

.PHONY: clean
clean :
	@rm -f -r $(OBJ_DIR) $(TARGET)