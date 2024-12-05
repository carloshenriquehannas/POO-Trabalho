TARGET = simulation

SRC_DIR = source
INC_DIR = header

CXX = g++
CXXFLAGS = -std=c++11 -I$(INC_DIR)

SOURCES = $(SRC_DIR)/cliente.cpp \
          $(SRC_DIR)/mesa.cpp \
          $(SRC_DIR)/reserva.cpp \
          $(SRC_DIR)/cardapio.cpp \
          $(SRC_DIR)/funcionario.cpp \
          $(SRC_DIR)/pedido.cpp \
          $(SRC_DIR)/pagamento.cpp \
          restaurant.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)