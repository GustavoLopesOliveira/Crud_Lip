# Compilador
CXX = g++

# Arquivos
SOURCES = main.cpp cliente.cpp funcionario.cpp quarto.cpp estadia.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
EXECUTABLE = programa.exe
BIN_EXECUTABLE = programa.bin

# Flags de compilação
CXXFLAGS = -std=c++11 -mconsole

# Regras
all: $(EXECUTABLE) $(BIN_EXECUTABLE)

# Criação do executável .exe
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Criação do executável .bin
$(BIN_EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(BIN_EXECUTABLE)

# Compilação de arquivos .cpp para .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza de arquivos objetos e executáveis
clean:
	if exist *.o del /Q *.o
	if exist $(EXECUTABLE) del /Q $(EXECUTABLE)
	if exist $(BIN_EXECUTABLE) del /Q $(BIN_EXECUTABLE)
	if exist clientes.bin del /Q clientes.bin

# Execução do programa
run: $(EXECUTABLE) clientes.bin
	@echo "Running $(EXECUTABLE)..."
	cmd /c $(EXECUTABLE) || echo "Execution failed with error code $$?"

clientes.bin:
	echo "" > clientes.bin

.PHONY: all clean run
