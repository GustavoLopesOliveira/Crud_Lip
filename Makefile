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

# Criação do executável no diretório bin
$(BIN_DIR)/$(EXECUTABLE): $(OBJECTS)
    if not exist $(BIN_DIR) mkdir $(BIN_DIR)
    $(CXX) $(OBJECTS) -o $(BIN_DIR)/$(EXECUTABLE)

# Compilação de arquivos .cpp para .o
$(OBJ_DIR)/%.o: %.cpp
    if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza de arquivos objetos e executável
clean:
    -del /Q $(OBJ_DIR)\*.o $(BIN_DIR)\$(EXECUTABLE) 2>nul || true

# Execução do programa
run: $(BIN_DIR)/$(EXECUTABLE)
    $(BIN_DIR)\$(EXECUTABLE) || echo "Execution failed with error code $$?"

.PHONY: all clean run