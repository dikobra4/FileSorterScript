# Объявление компилятора и флагов
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Имена целей и файлов
TARGET = sorter
SOURCES = main.cpp FileSorter.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Правило для создания объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки
clean:
	rm -f $(OBJECTS) $(TARGET)
