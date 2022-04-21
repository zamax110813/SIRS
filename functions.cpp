#include"functions.h"

using namespace std;

double functions::random_double(void){
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_real_distribution<double> doubleRand(0.0,1.0);
  return doubleRand(mt);
};

int functions::random_int(int n){
  std::random_device rnd;
  std::mt19937 mt(rnd());
  std::uniform_int_distribution<int> intRand(0,n-1);
  return intRand(mt);
};

int functions::choose(const vector<double>& vec){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  std::discrete_distribution<size_t> dist(vec.begin(),vec.end());
  return dist(engine);
};