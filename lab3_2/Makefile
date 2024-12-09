# Компилятор
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I/usr/include/UnitTest++  # Указание на путь для UnitTest++

# Исходные файлы
SRC = modPermutation.cpp main.cpp  # Исходные файлы
OBJ = $(SRC:.cpp=.o)

# Тесты
TEST_SRC = test_modPermutation.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Цель по умолчанию
all: modPermutation

# Компиляция основной программы
modPermutation: $(OBJ)
	$(CXX) $(CXXFLAGS) -o modPermutation $(OBJ)

# Компиляция тестов
test: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o test_modPermutation $(TEST_OBJ) modPermutation.o -lUnitTest++

# Правило для компиляции объектов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJ) $(TEST_OBJ) modPermutation test_modPermutation
