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
// Hash 4475
// Hash 4850
// Hash 3466
// Hash 7811
// Hash 8652
// Hash 3879
// Hash 7836
// Hash 5690
// Hash 2070
// Hash 2649
// Hash 8427
// Hash 9965
// Hash 1253
// Hash 8319
// Hash 8021
// Hash 4879
// Hash 8057
// Hash 4212
// Hash 2751
// Hash 7438
// Hash 7672
// Hash 3313
// Hash 7825
// Hash 2669
// Hash 6703
// Hash 9935
// Hash 6449
// Hash 4046
// Hash 9859
// Hash 7804
// Hash 8214
// Hash 1757
// Hash 3846
// Hash 6467
// Hash 9741
// Hash 6498
// Hash 5343
// Hash 5978
// Hash 6510
// Hash 2737
// Hash 9130
// Hash 9963
// Hash 9386
// Hash 9687
// Hash 5651
// Hash 2560
// Hash 1278
// Hash 1865
// Hash 8387
// Hash 5122
// Hash 8640
// Hash 9017
// Hash 2128
// Hash 9924
// Hash 2067
// Hash 6306
// Hash 8605
// Hash 4275
// Hash 1553
// Hash 6536
// Hash 5281
// Hash 2120
// Hash 3984
// Hash 9756
// Hash 4253
// Hash 3638
// Hash 9370
// Hash 9392
// Hash 5735
// Hash 3461
// Hash 7951
// Hash 3071
// Hash 7644
// Hash 1493
// Hash 7964
// Hash 1164
// Hash 6481
// Hash 1203
// Hash 4517
// Hash 6130
// Hash 4746
// Hash 9396
// Hash 2996
// Hash 9035
// Hash 2392
// Hash 3508
// Hash 8561
// Hash 5750
// Hash 5663
// Hash 5705
// Hash 9549
// Hash 4209
// Hash 3601
// Hash 7085
// Hash 9688
// Hash 7185
// Hash 5349
// Hash 3970
// Hash 8029
// Hash 3587
// Hash 3422
// Hash 9844
// Hash 6840
// Hash 1562
// Hash 1829
// Hash 1392
// Hash 7754
// Hash 4257
// Hash 9511
// Hash 4007
// Hash 6834
// Hash 7528
// Hash 7115
// Hash 7996
// Hash 1108
// Hash 8776
// Hash 1811
// Hash 1485
// Hash 3889
// Hash 8834
// Hash 8836
// Hash 6429
// Hash 2040