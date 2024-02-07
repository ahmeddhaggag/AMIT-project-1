project_name = main
cc = gcc

run: $(project_name).c sdb.c
	$(cc) $(project_name).c sdb.c -o sdb.exe
	./sdb.exe