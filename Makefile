cc = g++

exe_file = run
$(exe_file): image-service.o prng-service.o user.o
	$(CC) image-service.o prng-service.o user.o -o $(exe_file)
image-service.o: image-service.cpp
	$(CC) -c image-service.cpp
prng-service.o: prng-service.cpp
	$(CC) -c prng-service.cpp
user.o: user.cpp
	$(CC) -c user.cpp

clean:
	rm -f *.out *.o $(exe_file)
