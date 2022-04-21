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
init_sc : 初期状態における対策グループに属する脆弱ホスト数
init_ic : 初期状態における対策グループに属する感染ホスト数
init_rc : 初期状態における対策グループに属する保護ホスト数
alpha : ホスト一台当たりのマルウェア感染率
deltas : ホスト一台当たりの脆弱性除去率
deltai : ホスト一台当たりのマルウェア除去率
eta : ホスト一台当たりの脆弱性発見率
tau : ホストが対策グループへの参加及び離脱を決定する頻度を表すパラメータ
deltaw : マルウェアの脅威の度合い
kappa : 温度係数
omega : 対策グループに参加するホストのコストを表す重み
gamma : ホストに対して対策グループへの参加を促すインセンティブを表す重み
 3000 10000 9998 1 0 1 0 0 10 1 1 10 1 1 0.1 2 1 20 0.1
#COMMENTOUT
t=3000
n=10000
k=20
p=0.1
init_s=9998
init_i=1
init_r=0
init_sc=1
init_ic=0
init_rc=0
eta=0.01
deltas=1.0
alpha=10
deltas=0.1
deltai=0.1
eta=10
tau=1
deltaw=0.1
kappa=0.1
omega=2
gamma=1
make
for ((i=0 ; i<100 ; i++))
do
rm -f output${i}.dat
done
for ((i=0 ; i<100 ; i++))
do
./main_app $t $n $k $p $eta $deltas $alpha $deltai >output${i}.dat
done
gnuplot -persist <<EOF
set logscale y
set yrange [0:10000]
set xrange [0:3000]
set xlabel "時刻t"
set ylabel "Ni(t)"
set nokey
plot for [i=0:99] 'output'.i.'.dat' using 1:2 with steps linecolor rgb "#000000"
EOF