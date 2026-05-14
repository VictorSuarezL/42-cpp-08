NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

main.o: main.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Span.o: Span.cpp Span.hpp
	$(CXX) $(CXXFLAGS) -c Span.cpp -o Span.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
