
TARGET = main
SOURCES = main.cpp src/*.cpp #src/turrets.cpp src/enemies.cpp src/helper.cpp


LIBRARIES = -l sfml-graphics -l sfml-window -l sfml-system
INCLUDE_DIRECTORIES =

CXX = g++
CXXFLAGS = -Wall -Weffc++ -Wextra
CPPVERSION = -std=c++20

OBJECTS = $(SOURCES:.cpp=.o)

FIN_MAC = $(CXX) $(SOURCES) $(CXXFLAGS) $(CPPVERSION) -I/opt/homebrew/Cellar/sfml/2.5.1_2/include/ -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib/ $(LIBRARIES) -o $(TARGET)
FIN_UBUNTU = $(CXX) $(OBJECTS) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) $(LIBRARIES) -o $(TARGET)

UNAME_S := $(shell uname -s)
# $(info $(UNAME_S))
# $(info $(FIN_MAC))


ifeq ($(UNAME_S), Linux)
  FIN = $(FIN_UBUNTU)
else
  FIN = $(FIN_MAC)
endif


compile:
	$(FIN)


# $(OBJECTS): $(SOURCES)
# 	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRECTORIES) -c $(SOURCES)

clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./${TARGET}
	
pushalltogit:
	git add .
	git commit -m "auto commit"
	git push origin master
	
pullallfromgit:
	git pull origin master