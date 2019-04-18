import os
from random import randint


if __name__ == "__main__":
    if not os.path.exists("./test"):
        os.rmdir("./test")
        os.mkdir("./test")
    with open("./test/score.txt", "w") as f:
        for i in range(1, 24):
            if i < 10: f.write(str(i) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + "\n")
            else: f.write(str(i) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + " " + str(randint(60, 99)) + "\n")
    for i in range(23):
        with open("./test/prefer_" + str(i + 1) + ".txt", "w") as f:
            for i in range(23):
                f.write(str(i + 1) + " " + str(randint(1, 5)) + "\n")