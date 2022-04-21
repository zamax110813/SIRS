
gnuplot -persist <<EOF
set yrange [0:1000]
set xrange [0:100]
set xlabel "Time"
set ylabel "The Number of Hosts"
set nokey
plot "output1.dat" u 1:2 title "S(Susceptible)" w l lc 'blue',\
"output1.dat" u 1:3 title "I(Infected)" w l lc 'red',\
"output1.dat" u 1:4 title "R(Recovered)" w l lc 'green'
EOF