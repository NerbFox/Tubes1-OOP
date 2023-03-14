#  Compile main.cpp and all libraries
g++ ./main.cpp ./Ability/*.cpp ./Card/*.cpp ./Command/*.cpp ./ExceptionHandler/*.cpp ./Game/*.cpp ./Player/*.cpp ./Inventory/*.cpp
-o main

#  Run main.cpp and all libraries
./main