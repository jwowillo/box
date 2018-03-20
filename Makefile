.PHONY: test

test:
	g++ -std=c++14 -isystem gtest/include -Igtest -pthread -c gtest/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	g++ -std=c++14 -isystem gtest/include -pthread test.cc libgtest.a -o test

clean:
	rm -f *.o
	rm -f *.a
	rm -f test
