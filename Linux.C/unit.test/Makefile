##### compiler macros
CXX		:= g++
CXX_FLAG	:= -Wall
CXX_DEBUG	:= -g
CXX_MACROS	:= -D _LOG_MACROS_
CXX_FLAG	:= $(CXX_FLAG) $(CXX_DEBUG) $(CXX_MACROS)

##### name macros
PROJECT		:= unit.test
test_file	:= xargparse
unit_test	:= test.$(test_file)

##### path macros
PATH_TO		:= .
LINK_PATH	:= ..

##### obj macros
obj_ALL		:= xargparse.o xlog.o

##### vpath macros
vpath %.h	$(LINK_PATH)/inc
vpath %.o	$(LINK_PATH)/obj
vpath %.cc	$(PATH_TO)

### active
all : $(unit_test)

$(unit_test) : $(unit_test).o $(obj_ALL)
	$(CXX) $(CXX_FLAG) -o $@ $^

%.o : %.cc
	$(CXX) $(CXX_FLAG) -c $< -o $@


.PHONY : all clean install print tar dist TAGS check test
clean :
	@-rm -rfv $(unit_test) *.o *.d *.i *.log
install :
print :
tar :
dist :
TAGS :
check :
	$(CXX) $(CXX_FLAG) -M $(unit_test).cc -o $(unit_test).d
	$(CXX) $(CXX_FLAG) -E $(unit_test).cc -o $(unit_test).i
test :
	./$(unit_test) --ip 192.168.0.233 --port 2333 --path ../TCP --fuck
