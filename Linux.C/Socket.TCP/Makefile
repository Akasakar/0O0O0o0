##### compiler macros
CXX		:= g++
CXX_WARNING	:= -Wall
CXX_DEBUG	:= -g
CXX_MACROS	:= -D _LOG_MACROS_
CXX_FLAG	:= $(CXX_WARNING) $(CXX_DEBUG) $(CXX_MACROS)

##### name macros
PROJECT		:= Socket.TCP
HEAD_FILEs	:= head_files.d
target_ALL	:= xclient xserver
obj_ALL		:= xnode.o xsock.o xargparse.o xlog.o

##### path macros
PATH_TO		:= .
LINK_PATH	:= ..

##### vpath macros
vpath %.h	$(LINK_PATH)/inc
vpath %.cc	$(LINK_PATH)/src
vpath %.o	$(LINK_PATH)/obj

### active
all : $(target_ALL)

xclient : xclient.o $(obj_ALL)
	$(CXX) $(CXX_FLAG) -o $@ $^

xserver : xserver.o $(obj_ALL)
	$(CXX) $(CXX_FLAG) -o $@ $^

%.o : %.cc
	$(CXX) $(CXX_FLAG) -c $< -o $@

### depend
dependency : $(HEAD_FILEs)
$(HEAD_FILEs) : $(addsuffix .cc, $(target_ALL))
	@echo include update...
	$(CXX) -M $^ -o $@
include $(HEAD_FILEs)


.PHONY : all clean install print tar dist TAGS check test
clean :
	@echo removing ...
	@-rm -rfv $(target_ALL) $(HEAD_FILEs) *.o
	@echo done.
install :
	@echo installing...
print :
	@echo print...
tar :
	@echo tar...
	@tar -cvf $(PROJECT).tar ../$(PROJECT)
	@echo done.
dist :
	@echo dist...
	@tar -czvf $(PROJECT).tar.gz ../$(PROJECT)
	@echo done.
TAGS :
	@echo TAGS...
check :
	@echo check...
test :
	@echo test...
