##### complier macros
CXX		:= g++
CXX_WARNING	:= -Wall
CXX_fPIC	:= -fPIC
CXX_DEBUG	:= -g
CXX_MACROS	:= -D _LOG_MACROS_
CXX_FLAG	:= $(CXX_WARNING) $(CXX_DEBUG) $(CXX_MACROS)

##### name macros
PROJECT		:= Linux.C

##### path macros
PATH_TO		:= .
LINK_PATH	:= ..
OBJ_PATH	:= $(PATH_TO)/obj

##### obj macros
obj_ALL		:= xlog.o xargparse.o xsock.o xnode.o

##### vpath macros
vpath %.h	$(PATH_TO)/inc
vpath %.cc	$(PATH_TO)/src

### active
all : $(obj_ALL)

%.o : %.cc
	$(CXX) $(CXX_FLAG) -c $< -o $@

.PHONY : all clean install print tar dist TAGS check test
clean:
	@echo clean...
	@-rm -rfv $(OBJ_PATH) $(obj_ALL)
	@echo done.

install:
	@echo install...
	@mkdir -p $(OBJ_PATH)
	@mv -v $(obj_ALL) $(OBJ_PATH)
	@echo done.

print :
	@echo $?

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
