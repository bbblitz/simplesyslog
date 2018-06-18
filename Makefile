CC?=g++

ifeq ($(OS),Windows_NT)
	static_ext=.lib
	dynamic_ext=.dll
else
	static_ext=.a
	dynamic_ext=.so
endif

libname=simplesyslog
static_lib_name=$(libname)$(static_ext)
dyanmic_lib_name=$(libname)$(dynamic_ext)

build_dir=build
bin_dir=bin
src_dir=src

static_file=$(bin_dir)/$(static_lib_name)
dynamic_file=$(bin_dir)/$(dynamic_lib_name)

objects=$(build_dir)/syslog.o

all: $(static_file)
	@echo Complete

clean:
	rm $(build_dir)/*
	rm $(bin_dir)/*

$(static_file): $(objects)
	ar rcs $@ $^

$(dynamic_file): $(objects)
	$(CC) $(CFLAGS) -shared -o $@ $^

$(build_dir)/syslog.o: $(src_dir)/syslog.c $(src_dir)/syslog.h
	$(CC) $(CFLAGS) -c -o $@ $(src_dir)/syslog.c

