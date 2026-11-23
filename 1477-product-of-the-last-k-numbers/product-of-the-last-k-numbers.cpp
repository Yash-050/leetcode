class ProductOfNumbers {
public:
    vector<int>arr;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }

    
    int getProduct(int k) {
        if(arr.size()<k||arr.empty())return 0;
        long long ans = 1;
       for(int i = arr.size()-1;i>=(int)arr.size()-k;i--){
        ans = 1LL*ans*arr[i];
       }    
       return (long long)ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */