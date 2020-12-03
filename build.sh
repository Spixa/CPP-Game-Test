#!/bin/bash
# i have no idea of bash 



# gets all .cpp and .h files n then like compiles them or sumn and doesn't give a crap about anything else 
echo "Building: "
tput setaf 01
echo {*.cpp,*.h}
g++ {*.cpp,*.h} -o Game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -Wall -Wextra   # i like warning catchers
tput setaf 0
echo "Operation done!"
