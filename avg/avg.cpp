#include<bits/stdc++.h>
using namespace std;

int main(int argc,char *argv[]){

    const double interval=atof(argv[1]);//データの記録間隔
    const double simu_time=atof(argv[2]);//シミュレーション時間
    const int iter=atoi(argv[3]);//シミュレーション回数
    const int num_data=simu_time/interval+1;//配列の要素数
    vector<double> t(num_data),S(num_data),I(num_data),R(num_data);

    //データファイルのデータを配列に格納
    for(int i=0;i<iter;i++){
        string filename="./data/output";
        filename+=to_string(i+1);
        filename+=".dat";
        ifstream fin(filename);
        if(!fin){  
            cout << "入力ファイルをオープンできません" << endl;
            return 1;
        }
        int num_s,num_i,num_r;
        int j=0;
        while(fin>>t[j]>>num_s>>num_i>>num_r){
            S[j]+=num_s;
            I[j]+=num_i;
            R[j]+=num_r;
            j++;
        }
    }

    //iterで割って平均を求める
    for(int i=0;i<num_data;i++){
        S[i]/=1.0*iter;
        I[i]/=1.0*iter;
        R[i]/=1.0*iter;
    }

    //平均データをファイルに出力
    ofstream fout("avg.dat",ios::out); 
    for(int i=0;i<num_data;i++){
        fout<<t[i]<<" "<<S[i]<<" "<<I[i]<<" "<<R[i]<<endl;
    }
}

