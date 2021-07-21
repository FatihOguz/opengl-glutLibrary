
main: home.cpp
	g++ home.cpp -o home -lGL -lGLU -lglut
	./home
clean: 
	rm home