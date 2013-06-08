test_leveldb:test_leveldb.cpp
	g++ -g -static $^ -o $@ -I../include -L../ -lleveldb -lpthread

.PHONE:clean
clean:
	rm test_leveldb
