#  Compile main.cpp and all libraries
g++ main.cpp ./Card/*.cpp ./Command/*.cpp ./ExceptionHandler/*.cpp ./Game/*.cpp ./Player/*.cpp ./Inventory/*.cpp ./Ability/*.cpp -o main && ./main