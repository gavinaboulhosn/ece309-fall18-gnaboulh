
# add files you create here
OBJ = example.o hw2.o hw3.o PList.o IntArray.o IntSetArray.o IntegerSetHT.o MaxHeap.o

all: libece309.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libece309.a $(OBJ)

libece309.a: $(OBJ)
	$(AR) -r $@ $(OBJ) 

%.o:%.cpp
	$(CXX) -c -o $@ -I . -I ../include $< -Wall -Werror -std=c++11
