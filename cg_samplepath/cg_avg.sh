:<<'#COMMENTOUT'
複数回シミュレーションを行った場合の,時刻経過に対する各ホスト数の平均を求める
#COMMENTOUT

gnuplot -persist <<EOF
nearint(x)=(x - floor(x) <= 0.5 ? floor(x) : floor(x)+1) 
filter(x,y)=nearint(x/y)*y
set yrange [0:1000]
set xrange [0:10]
set xlabel "Time"
set ylabel "The Number of Hosts"
set nokey
plot "output.dat" u (filter(\$1,0.01)):2 smooth unique title "S(Susceptible)" w l lc 'blue',\
    "" u (filter(\$1,0.01)):3 smooth unique title "I(Infected)" w l lc 'red',\
    "" u (filter(\$1,0.01)):4 smooth unique title "R(Recovered)" w l lc 'green'
EOF