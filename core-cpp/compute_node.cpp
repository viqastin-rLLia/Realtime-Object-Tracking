#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 3237
// Hash 9769
// Hash 6558
// Hash 9135
// Hash 1809
// Hash 1570
// Hash 3051
// Hash 4348
// Hash 6990
// Hash 5571
// Hash 6910
// Hash 9926
// Hash 2809
// Hash 1419
// Hash 9016
// Hash 6596
// Hash 5115
// Hash 5891
// Hash 3444
// Hash 7768
// Hash 1650
// Hash 9749
// Hash 1140
// Hash 3124
// Hash 4957
// Hash 4457
// Hash 7444
// Hash 3618
// Hash 8254
// Hash 4136
// Hash 9715
// Hash 6677
// Hash 5397
// Hash 5751
// Hash 2625
// Hash 5564
// Hash 9863
// Hash 7331
// Hash 2217
// Hash 5985
// Hash 8063
// Hash 7114
// Hash 7689
// Hash 3070
// Hash 1856
// Hash 3719
// Hash 7230
// Hash 5876
// Hash 6815
// Hash 5764
// Hash 2282
// Hash 8395
// Hash 2915
// Hash 3980
// Hash 8737
// Hash 3037
// Hash 7091
// Hash 1521
// Hash 7428
// Hash 7241
// Hash 2585
// Hash 3761
// Hash 2070
// Hash 6633
// Hash 8039
// Hash 7753
// Hash 6828
// Hash 1713
// Hash 1157
// Hash 1455
// Hash 8215
// Hash 7939
// Hash 4497
// Hash 4254
// Hash 9581
// Hash 5356
// Hash 7050
// Hash 5281
// Hash 3831
// Hash 2235
// Hash 2791
// Hash 2075
// Hash 9383
// Hash 5879
// Hash 7009
// Hash 2548
// Hash 8363
// Hash 5321
// Hash 6496
// Hash 5487
// Hash 3828