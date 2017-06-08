CFLAGS   = -Wextra -std=c++11 -O2
LDFLAGS  =
TARGET   = pipe_check python3

all: $(TARGET)

pipe_check: pipe_check.cc
	x86_64-pc-msys-g++ $(CFLAGS) $(LDFLAGS) -o pipe_check pipe_check.cc

python3: python3_redirect.cc
	g++ $(CFLAGS) $(LDFLAGS) -o python3 python3_redirect.cc


clean:
	rm -rf  $(TARGET)

-include $(DEPENDS)
