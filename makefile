compilesamet:./main.cpp
	g++ -c ./main.cpp
	g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system

pushall:
	git add .
	git commit -m "auto commit"
	git push origin master

pullallfromgit:
	git pull origin master