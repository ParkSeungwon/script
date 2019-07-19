all : 
	make -C gtk/
	make -C src/
	make -C obj/

PHONY : clean

clean :
	rm obj/*.?
	rm *.x

