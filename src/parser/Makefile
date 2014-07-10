include ../../Makefile.inc

CPP_FILES = $(wildcard *.cpp)
OBJECTS = $(CPP_FILES:.cpp=.o)
INCLUDES = $(wildcard *.h)

.PHONY: all build-objects build-includes clean clean-parser

all: build-objects build-includes

build-objects: $(OBJECTS) | $(BUILD_DIR)/src/parser
	cp $(OBJECTS) $(BUILD_DIR)/src/parser

build-includes: $(INCLUDES) | $(BUILD_DIR)/src/parser
	cp $(INCLUDES) $(BUILD_DIR)/src/parser

$(OBJECTS): %.o: %.cpp
	$(CXX) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS) $(FLAGS) -c $< -o $@

$(BUILD_DIR)/src/parser:
	mkdir -p $(BUILD_DIR)/src/parser

clean:
	@echo "Clean objects in `pwd`"
	rm -rf *.o