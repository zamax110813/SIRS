.SUFFIXES:.cpp .o
-include objfiles
.cpp.o:
	g++ -c $< -o $@
-include headerdepend