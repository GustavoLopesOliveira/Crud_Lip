# Compilador
CXX = g++

# Diretórios
INCLUDE_DIR = include
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos
SOURCES = main.cpp cliente.cpp funcionario.cpp quarto.cpp estadia.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)
EXECUTABLE = programa.exe

# Flags de compilação
CXXFLAGS = -I$(INCLUDE_DIR) -std=c++11 -mconsole

# Regras
all: $(BIN_DIR)/$(EXECUTABLE)

$(BIN_DIR)/$(EXECUTABLE): $(OBJECTS)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(BIN_DIR)/$(EXECUTABLE)

$(OBJ_DIR)/%.o: %.cpp
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ_DIR)\*.o $(BIN_DIR)\$(EXECUTABLE)

run: $(BIN_DIR)/$(EXECUTABLE)
	$(BIN_DIR)/$(EXECUTABLE)

.PHONY: all clean run