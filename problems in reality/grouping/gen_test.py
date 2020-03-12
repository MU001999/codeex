import os
from random import randint

fnames = ["赵", "钱", "孙", "李", "周", "吴", "郑", "王"]

snames = ["欣", "胡", "之", "美", "容", "轩", "钥", "博"]

def gen_name():
    sname = ""
    length = randint(1, 2)
    for i in range(length):
        sname += snames[randint(0, len(snames) - 1)]
    return fnames[randint(0, len(fnames) - 1)] + sname

if __name__ == "__main__":
    if not os.path.exists("./test"):
        os.rmdir("./test")
        os.mkdir("./test")
    with open("./test/score.txt", "w") as f:
        for i in range(1, 24):
            if i < 10: f.write(str(i) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + "\n")
            else: f.write(str(i) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + "\n")
    with open("./test/name.txt", "w") as f:
        for i in range(1, 24):
            if i < 10: f.write(str(i) + " " + gen_name() + "\n")
            else: f.write(str(i) + " " + gen_name() + "\n")
    for i in range(23):
        with open("./test/prefer_" + str(i + 1) + ".txt", "w") as f:
            for i in range(23):
                f.write(str(i + 1) + " " + str(randint(1, 5)) + "\n")
