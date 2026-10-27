bin/testListArray: testListArray.cpp ListArray.h List.h ListLinked.h NOde.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp testListLinked.cpp

clean:
	rm -r *.o *.gch *.pch bin
