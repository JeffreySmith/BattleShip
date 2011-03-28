ALL:sprite timer button

cc=g++
name=main
dependencies= sprite.o timer.o button.o
config=`sdl-config --cflags --libs`
flags=-lSDL_image  -g 

button: button.cpp button.h
	${cc} ${config} ${flags} -c button.cpp
timer:timer.cpp timer.h
	${cc} ${config} ${flags} -c timer.cpp

sprite: sprite.cpp sprite.h
	${cc} ${config} ${flags} -c sprite.cpp


main: ${source}
	${cc} -o ${name} main.cpp ${dependencies} ${config} ${flags} 
clean:
	rm -rf *.o main \#* *\~