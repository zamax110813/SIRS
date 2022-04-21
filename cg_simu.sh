:<<'#COMMENTOUT'
進化ゲーム理論を用いたマルウェア感染拡散対策モデルの確率論的シミュレータ(Watts-Strogatzモデル)
パラメータ
t : シミュレーション時間
n : 全ノード数
k : 接続する隣接ノード数
p : ノード再接続の確率
init_s : 初期状態における脆弱ホスト数
init_i : 初期状態における感染ホスト数
init_r : 初期状態における保護ホスト数
alpha : ホスト一台当たりのマルウェア感染率
deltas : ホスト一台当たりの脆弱性除去率
deltai : ホスト一台当たりのマルウェア除去率
eta : ホスト一台当たりの脆弱性発見率
graph : 0は完全グラフ,1はWSモデル,2はBAモデル
interval : 各ホスト数を記録する時間間隔
#COMMENTOUT
t=100
n=1000
k=20
p=0.1
init_s=999
init_i=1
init_r=0
eta=0.05
alpha=0.001
deltas=1
deltai=0.1
graph=0
interval=0.001
./make.sh

rm -f output.dat

./a.out $t $n $init_s $init_i $init_r $alpha $deltas $deltai $eta $k $p $graph $interval>output.dat

gnuplot -persist <<EOF
set yrange [0:1000]
set xrange [0:10]
set key right
set xlabel font "Arial,20"
set ylabel font "Arial,20"
set tics font "Arial,10"
set key font"Arial,10"
set xlabel "Time"
set ylabel "The Number of Hosts"
plot "output.dat" u 1:2 title "S(Susceptible)" w l  lc 'blue',\
"output.dat" u 1:3 title "I(Infected)" w l lc 'red',\
"output.dat" u 1:4 title "R(Recovered)" w l lc 'green'
EOF