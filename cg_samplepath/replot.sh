
gnuplot -persist <<EOF
set logscale y
set yrange [1:1000]
set xrange [0:100]
set xlabel font "Arial,20"
set ylabel font "Arial,20"
set tics font "Arial,10"
set key font"Arial,10"
set xlabel "Time"
set ylabel "The Number of Hosts"
set nokey
plot for [i=1:100] 'output'.i.'.dat' using 1:3 with steps linecolor rgb "#000000"
EOF