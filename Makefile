CXX := g++
SRCDIR := source
BUILDDIR := build
TARGET := bin/hiillos

CXX_SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)
CXX_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(CXX_SOURCES:.cpp=.o))
CXX_FLAGS := -ggdb -std=c++11

LIB := SDL2 SDL2_image SDL2_ttf SDL2_mixer
LINKER_FLAGS := $(foreach library,$(LIB),-l$(library))

# TODO: Include all header files (find from subfolders)
INC := -I include

$(TARGET): $(CXX_OBJECTS)
	@echo " Linking..."
	$(CXX) $^ -o $(TARGET) $(LINKER_FLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXX_FLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	$(RM) -r $(BUILDDIR) $(TARGET)

distclean: clean

.PHONY: clean
