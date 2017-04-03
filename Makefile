all: lru lfu second random

lru: lru.cpp deque.cpp 
	g++ -o lru lru.cpp deque.cpp 

lfu: lfu.cpp deque.cpp
	g++ -o lfu lfu.cpp deque.cpp

second: second.cpp
	g++ -o second second.cpp 

random: random.cpp
	g++ -o random random.cpp deque.cpp

clean: 
	rm -f *.o lru lfu random clock generate
