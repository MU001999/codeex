/*
Q-URL: https://leetcode-cn.com/problems/rle-iterator
*/

class RLEIterator {
private:
    vector<int> &A_;
    int now_;
    int nowLeft_;

public:
    RLEIterator(vector<int>& A)
      : A_(A), now_(1), nowLeft_(A[0]) {
        // ...
    }

    int next(int n) {
        if (now_ == -1) {
            return -1;
        }
        while (n > 0) {
            if (n <= nowLeft_) {
                nowLeft_ -= n;
                break;
            } else {
                n -= nowLeft_;
                if (now_ + 2 > A_.size()) {
                    return now_ = -1;
                }
                nowLeft_ = A_[(now_ += 2) - 1];
            }
        }
        return A_[now_];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
