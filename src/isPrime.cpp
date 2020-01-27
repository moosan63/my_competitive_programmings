
// memoには数え上げた素数を入れていく
bool is_prime(int n, map<int,int> &memo){
    if(memo[n] == 1){
        return false;
    }else if(memo[n] == 2){
        return true;
    }

    bool prime = true;
    double sqrt_n = sqrt(double(n));
    for(int i =2; i<=max(2,int(sqrt_n)); i++){
        if(memo[i]==2 && n%i==0){
            prime = false;
        }
    }
    if(prime){
        memo[n] = 2;
    }else{
        memo[n] = 1;
    }

    return prime;
}