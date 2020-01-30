#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o Simulator.o Population.o Inventory.o Agent.o SPtr.o Blockchain.o Serial.o
TARGET = blockchain
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp tools.hpp Simulator.hpp Population.hpp Agent.hpp Blockchain.hpp Block.hpp SPtr.hpp Serial.hpp
Simulator.o: Simulator.cpp Simulator.hpp Population.hpp Agent.hpp Blockchain.hpp Block.hpp SPtr.hpp Serial.hpp Inventory.hpp tools.hpp
Population.o: Population.cpp Population.hpp Agent.hpp tools.hpp Blockchain.hpp Block.hpp SPtr.hpp Serial.hpp
Inventory.o: Inventory.cpp Inventory.hpp Agent.hpp tools.hpp Blockchain.hpp Block.hpp SPtr.hpp Serial.hpp
Agent.o: Agent.cpp Agent.hpp tools.hpp Blockchain.hpp Block.hpp SPtr.hpp Serial.hpp
Blockchain.o: Blockchain.cpp Blockchain.hpp Block.hpp 
SPtr.o: SPtr.cpp SPtr.hpp Serial.hpp Block.hpp
Serial.o: Serial.cpp Serial.hpp
tools.o: tools.cpp tools.hpp
