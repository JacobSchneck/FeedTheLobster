# Jacob Schneck
# CS 120
# Module-2: Open Ended Project - Class Relationships

CPP := g++
CPPSTD := -std=c++17

tests:
	$(CPP) $(CPPSTD) Pet.cpp Lobster.cpp Stomache.cpp tests.cpp Family.cpp -o tests
	./tests
	rm tests

main:
	$(CPP) $(CPPSTD) Pet.cpp Lobster.cpp Stomache.cpp main.cpp Family.cpp -o main
	./main
	rm main