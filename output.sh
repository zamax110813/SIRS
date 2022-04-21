gnuplot -persist <<EOF
set yrange [0:"$1"]
set xrange [0:"$2"]
set key right
set xlabel font "Arial,20"
set ylabel font "Arial,20"
set tics font "Arial,10"
set key font"Arial,10"
set xlabel "Time"
set ylabel "The Number of Hosts"
plot "$3" u 1:2 title "S(Susceptible)" w l  lc 'blue',\
"$3" u 1:3 title "I(Infected)" w l lc 'red',\
"$3" u 1:4 title "R(Recovered)" w l lc 'green'
EOF