class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {}

    void add(int num) {
        arr.push_back(num);
    }

    int getProduct(int k) {
        if (k > arr.size())
            return 0;

        long long mul = 1;

        for (int i = arr.size() - 1; i >= (int)arr.size() - k; i--) {
            mul *= arr[i];
        }

        return (int)mul;
    }
};