# Template C++ makefile
# 
# Daniel Andrus
# Version 1.0



SOURCE_FILES = main.cpp look_busy.cpp list_parser.cpp flat_list_parser.cpp list_randomizer.cpp

CPP_COMPILER = g++
CPP_LINKER = g++
CPP_COMPILE_FLAGS = -std=c++11
CPP_LINK_FLAGS = -std=c++11

# NOTICE build directory must be set in object targets

BUILD_DIR = build
SOURCE_DIR = src



# EDIT set custom program name

lookbusy: $(addprefix $(BUILD_DIR)/, $(SOURCE_FILES:.cpp=.o))
	$(CPP_LINKER) $(CPP_LINK_FLAGS) -o $@ $^
	



# EDIT custom build directory

build/%.o: $(addprefix $(SOURCE_DIR)/, %.cpp)
	@mkdir -p $(BUILD_DIR)
	$(CPP_COMPILER) $(CPP_COMPILE_FLAGS) -c -o $@ $<

clean:
	@rm -f $(addprefix $(BUILD_DIR)/, $(SOURCE_FILES:.cpp=.o)) lookbusy
