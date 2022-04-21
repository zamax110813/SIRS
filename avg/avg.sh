:<<'#COMMENTOUT'
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
interval : データ記録の時間間隔
#COMMENTOUT
t=10
n=1000
k=20
p=0.1
init_s=999
init_i=1
init_r=0
alpha=0.001
deltas=1
deltai=0.1
eta=0.05
interval=0.001
graph=0

cd ../
./make.sh
cd avg

./make.sh

for i in `seq 1 10`
do
    rm -f output$i.dat
done

for i in `seq 1 10`
do
    ../a.out $t $n $init_s $init_i $init_r $alpha $deltas $deltai $eta $k $p $graph $interval>>output.dat
    echo $i
done