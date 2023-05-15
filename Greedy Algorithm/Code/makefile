CC = g++
CFLAGS = -Wall -std=c++11 

TASK1 = s1
TASK2 = s2
TASK3 = s3
TASK4 = s4
TASK5 = s5

all: $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5)

$(TASK1): s1.o
	$(CC) $(CFLAGS) s1.cpp -o $(TASK1)

s1.o: s1.cpp
	$(CC) $(CFLAGS) -c s1.cpp -o s1.o

$(TASK2): s2.o
	$(CC) $(CFLAGS) s2.cpp -o $(TASK2)

s2.o: s2.cpp
	$(CC) $(CFLAGS) -c s2.cpp -o s2.o

$(TASK3): s3.o
	$(CC) $(CFLAGS) s3.cpp -o $(TASK3)

s3.o: s3.cpp
	$(CC) $(CFLAGS) -c s3.cpp -o s3.o

$(TASK4): s4.o
	$(CC) $(CFLAGS) s4.cpp -o $(TASK4)

s4.o: s4.cpp
	$(CC) $(CFLAGS) -c s4.cpp -o s4.o

$(TASK5): s5.o
	$(CC) $(CFLAGS) s5.cpp -o $(TASK5)

s5.o: s5.cpp
	$(CC) $(CFLAGS) -c s5.cpp -o s5.o

clean:
	rm -f *.o $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5)

run1:
	./$(TASK1)

run2: 
	./$(TASK2)

run3: 
	./$(TASK3)

run4: 
	./$(TASK4)

run5: 
	./$(TASK5)
