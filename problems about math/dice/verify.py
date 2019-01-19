from random import randint, shuffle

def dice():
    return randint(1, 6)

def say_which(r, t):
    vals = [i for i in range(1, 7) if i != r and i != t]
    shuffle(vals)
    return vals[0]

def cal_once():
    real_result = dice()
    think_result = dice()
    which_not = say_which(real_result, think_result)
    return real_result, think_result, which_not

def keep():
    r, t, w = cal_once()
    return r == t

def change():
    r, t, w = cal_once()
    t = say_which(t, w)
    return r == t

def cal(times, way):
    right_times = 0
    for i in range(times):
        right_times += way()
    return right_times * 100.0 / times

if __name__ == "__main__":
    for i in range(10):
        print(cal(100000, keep), cal(100000, change))
