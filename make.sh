#!/bin/bash

g++ main.cpp src/enemies.cpp src/helper.cpp src/turrets.cpp -std=c++20 -Wall -Weffc++ -Wextra -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -l sfml-graphics -l sfml-window -l sfml-system && ./main
# g++ test.cpp -std=c++20 -Wall -Weffc++ -Wextra -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -o main -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib/ -l sfml-graphics -l sfml-window -l sfml-system && ./main
# -Wsign-conversion