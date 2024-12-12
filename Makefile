# Compilador
CXX = g++

# Diretórios
INCLUDE_DIR = include
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos
SOURCES = main.cpp cliente.cpp funcionario.cpp quarto.cpp estadia.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = programa.exe

# Flags de compilação
CXXFLAGS = -I$(INCLUDE_DIR) -std=c++11

# Regras
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean