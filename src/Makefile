include ../Makefile.inc

CPP_FILES = $(wildcard *.cpp)
OBJECTS = $(CPP_FILES:.cpp=.o)
INCLUDES = $(wildcard *.h)

.PHONY: all build-objects build-parser clean clean-parser

all: build-parser build-objects build-includes

build-objects: $(OBJECTS) | $(BUILD_DIR)/src

build-includes: $(INCLUDES) | $(BUILD_DIR)/src

build-parser: $(BASE_DIR)/src/parser
	@cd ./parser; $(MAKE) $(MFLAGS)

$(OBJECTS): %.o: %.cpp
	$(CXX) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS) $(FLAGS) -c $< -o $@

$(BUILD_DIR)/src:
	@echo "Make build dir $(BUILD_DIR)/src"
	mkdir -p $(BUILD_DIR)/src

clean: clean-parser
	@echo "Clean objects in `pwd`"
	rm -rf *.o

clean-parser: $(BUILD_DIR)/src/parser
	@cd ./parser; $(MAKE) $(MFLAGS) clean