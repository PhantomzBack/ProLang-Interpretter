include_path:="C:\\Users\\yugra\\Documents\\CSE Related\\Projs\\ProLangInterpreter\\ProLang-Interpretter"
	
all: expression_evaluator.o variable.o string_manipulations.o interpretter.o
	gcc -o prolang-interpretter.exe interpretter.o expression_evaluator.o variable.o string_manipulations.o

expression_evaluator.o:
	gcc -Idir ${include_path} -c expression_evaluator.c -o expression_evaluator.o
	
variable.o:
	gcc -Idir ${include_path} -c variable.c -o variable.o
	
string_manipulations.o:
	gcc -Idir ${include_path} -c string_manipulations.c -o string_manipulations.o
	
interpretter.o:
	gcc -Idir ${include_path} -c interpretter.c -o interpretter.o


clean:
	-rm edit *.o
