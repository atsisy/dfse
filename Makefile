objs = ./obj/main.o ./obj/cmd_opt.o ./obj/diskio.o ./obj/disk_struct.o
obj-dir = ./obj
bin-dir = ./bin

.PHONY: all clean

CC = gcc -O2

all: $(objs)
	@mkdir -p $(bin-dir)
	@$(CC) $(objs) -o $(bin-dir)/dfse

$(obj-dir)/%.o: %.c
	@mkdir -p $(obj-dir)
	@$(CC) $*.c -c -o $(obj-dir)/$*.o
	@echo "CC" $*.o

clean:
	rm -rf obj
	rm -rf bin
