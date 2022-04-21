#! /bin/zsh

echo -n "OBJS = " > objfiles
ls *.cpp | tr '\n' ' ' | sed -e 's/cpp/o/g' >> objfiles
echo "\n\na.out : \$(OBJS)\n\tg++ \$(OBJS)\n" >> objfiles

g++ -MM *.cpp | sed -e 's/ .*.cpp//g' >> headerdepend

make