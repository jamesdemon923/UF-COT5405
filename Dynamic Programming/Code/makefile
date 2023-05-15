CC = g++
CFLAGS = -Wall -std=c++11 

TASK1 = t1
TASK2 = t2
TASK3 = t3
TASK4 = t4
TASK5A = t5a
TASK5B = t5b
TASK6 = t6 
TASK7A = t7a 
TASK7B = t7b 

all: $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5A) $(TASK5B) $(TASK6) $(TASK7A) $(TASK7B)

$(TASK1): t1.o
	$(CC) $(CFLAGS) Task1.cpp -o $(TASK1)

t1.o: Task1.cpp
	$(CC) $(CFLAGS) -c Task1.cpp -o t1.o

$(TASK2): t2.o
	$(CC) $(CFLAGS) Task2.cpp -o $(TASK2)

t2.o: Task2.cpp
	$(CC) $(CFLAGS) -c Task2.cpp -o t2.o

$(TASK3): t3.o
	$(CC) $(CFLAGS) Task3.cpp -o $(TASK3)

t3.o:Task3.cpp
	$(CC) $(CFLAGS) -c Task3.cpp -o t3.o

$(TASK4): t4.o
	$(CC) $(CFLAGS) Task4.cpp -o $(TASK4)

t4.o: Task4.cpp
	$(CC) $(CFLAGS) -c Task4.cpp -o t4.o

$(TASK5A): t5a.o
	$(CC) $(CFLAGS) Task5A.cpp -o $(TASK5A)

t5a.o: Task5A.cpp
	$(CC) $(CFLAGS) -c Task5A.cpp -o t5a.o

$(TASK5B): t5b.o
	$(CC) $(CFLAGS) Task5B.cpp -o $(TASK5B)

t5b.o: Task5B.cpp
	$(CC) $(CFLAGS) -c Task5B.cpp -o t5B.o

$(TASK6): t6.o
	$(CC) $(CFLAGS) Task6.cpp -o $(TASK6)

t6.o: Task6.cpp
	$(CC) $(CFLAGS) -c Task6.cpp -o t6.o

$(TASK7A): t7a.o
	$(CC) $(CFLAGS) Task7A.cpp -o $(TASK7A)

t7a.o: Task7A.cpp
	$(CC) $(CFLAGS) -c Task7A.cpp -o t7a.o

$(TASK7B): t7b.o
	$(CC) $(CFLAGS) Task7B.cpp -o $(TASK7B)

t7b.o: Task7B.cpp
	$(CC) $(CFLAGS) -c Task7B.cpp -o t7B.o

clean:
	rm -f *.o $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5A) $(TASK5B) $(TASK6) $(TASK7A) $(TASK7B)

run1:
	./$(TASK1)

run2: 
	./$(TASK2)

run3: 
	./$(TASK3)

run4: 
	./$(TASK4)

run5A: 
	./$(TASK5A)

run5B: 
	./$(TASK5B)

run6: 
	./$(TASK6)

run7A: 
	./$(TASK7A)

run7B: 
	./$(TASK7B)
