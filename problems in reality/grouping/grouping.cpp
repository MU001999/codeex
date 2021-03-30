#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <array>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <numeric>
#include <utility>
#include <fstream>
#include <iterator>
#include <iostream>
#include <functional>

inline void exit_with_msg(const std::string &msg)
{
    std::cout << msg << std::endl;
    exit(0);
}

constexpr auto N = 18, K = 3, ScoreN = 3;
constexpr double ALPHA = 1.5;
const std::set<int> filter {0, 2, 9, 14, 17};

struct Method
{
    int score;
    std::vector<int> method;
};

double computeGradeByGroup(const std::bitset<N>&, double res = 0);
int    computeScoreByGroup(const std::bitset<N>&); // for favorability

std::map<std::string, std::string>          names;
std::vector<std::pair<double, std::string>> rawInfo;
std::array<std::array<int, N>, N>           scores;
std::vector<std::bitset<N>>                 posG;
std::vector<int>                            scoreG;
std::vector<std::vector<int>>               noInterference;

bool cmp(const Method&, const Method&);
std::priority_queue<Method, std::vector<Method>, decltype(cmp)*> Result(cmp);

void genRawInfoAndScores()
{
    std::ifstream score_in("score.txt");
    if (!score_in)
    {
        exit_with_msg("no such file: score.txt");
    }

    std::ifstream name_in("name.txt");
    if (!name_in)
    {
        exit_with_msg("no such file: name.txt");
    }

    for (int _i = 0, i = -1, tmpscores[ScoreN]; _i < N + filter.size(); ++_i)
    {
        std::string No;
        score_in >> No;

        if (No != std::to_string(_i + 1))
        {
            exit_with_msg("err for the No " + std::to_string(_i + 1) + " in file score.txt");
        }

        for (auto &score : tmpscores)
        {
            score_in >> score;
        }

        std::string name;
        name_in >> name >> name;
        names[No] = name;

        if (filter.count(_i))
        {
            continue;
        }
        else
        {
            ++i;
        }

        rawInfo.emplace_back(std::make_pair(std::accumulate(std::begin(tmpscores), std::end(tmpscores), 0) / (double)ScoreN, No));

        std::ifstream fin("prefer_" + No + ".txt");
        if (!fin)
        {
            exit_with_msg("no such file: prefer_" + No + ".txt");
        }

        for (int _j = 0, j = -1, score; _j < N + filter.size(); ++_j)
        {
            fin >> No >> score;

            if (No != std::to_string(_j + 1))
            {
                exit_with_msg("err for the No " + std::to_string(_j + 1) + " in file prefer_" + std::to_string(_i + 1) + ".txt");
            }

            if (filter.count(_j))
            {
                continue;
            }
            else
            {
                ++j;
            }

            scores[i][j] = score;
        }
    }

    if (N != rawInfo.size())
    {
        exit_with_msg("The number of students entered should be " + std::to_string(N) + " or edit N in code");
    }
}

void computePosG()
{
    std::vector<int> grades;
    for (auto info : rawInfo)
    {
        grades.push_back(info.first);
    }

    float average = std::accumulate(grades.begin(), grades.end(), 0) / (float)N * K;

    auto legal = [=](const int &score)
    { 
        return (average - ALPHA <= score) && (score <= average + ALPHA); 
    };

    std::function<void(int, int, std::bitset<N>)> add2posG = [&](int i, int k, std::bitset<N> pos)
    {
        if (k == 0 && legal(computeGradeByGroup(pos)))
        {
            posG.push_back(pos);
            scoreG.push_back(computeScoreByGroup(pos));
        }
        else while (++i < N)
        {
            pos[i] = true;
            add2posG(i, k - 1, pos);
            pos[i] = false;
        }
    };

    add2posG(-1, K, 0);
}

void computeNoInterference()
{
    for (auto i = 0; i < (int)posG.size(); ++i)
    {
        noInterference.push_back({});
        for (auto j = i + 1; j < (int)posG.size(); ++j)
        {
            if ((posG[i] & posG[j]).none())
            {
                noInterference[i].push_back(j);
            }
        }
    }
}

int computeScore(const std::vector<int> &method, int sum = 0)
{
    for (auto i: method)
    {
        sum += scoreG[i];
    }
    return sum;
}

int traverse(int m, int count, std::bitset<N> posCurrent, std::vector<int> method)
{
    if (posCurrent.all())
    {
        Result.push({ computeScore(method), method });
        if (Result.size() > 10)
        {
            Result.pop();
        }
        return 0;
    }
    else if (count == 0)
    {
        return 1;
    }

    for (auto it = noInterference[m].begin(); it != noInterference[m].end(); ++it)
    {
        if ((posG[*it] & posCurrent).none() && (int)noInterference[*it].size() >= count - 1)
        {
            method[count - 1] = *it;
            traverse(*it, count - 1, posCurrent | posG[*it], method);
        }
    }

    return 1;
}

void print()
{
    std::cout << "## RESULT ##" << std::endl;

    std::vector<decltype(Result)::value_type> results;
    while (!Result.empty())
    {
        results.push_back(Result.top());
        Result.pop();
    }
    std::reverse(results.begin(), results.end());

    for (int ind = 0; ind < results.size(); ++ind)
    {
        auto &top = results[ind];
        printf("\n %c 总分组评分: %3d\n", 'A' + ind, top.score);
        for (auto i : top.method)
        {
            printf("  小组成绩得分: %6.2lf, 组员: ", computeGradeByGroup(posG[i]));
            for (int j = 0; j < N; ++j)
            {
                if (posG[i][j])
                {
                    printf("%s ", names[rawInfo[j].second].c_str());
                }
            }
            printf("\n");
        }
        std::cout << std::endl;
    }
}

int main()
{
    genRawInfoAndScores();

    computePosG();
    computeNoInterference();

    for (int m = 0; m < (int)posG.size(); ++m)
    {
        std::vector<int> method(N / K, 0);
        method[N / K - 1] = m;
        traverse(m, N / K - 1, posG[m], method);
    }

    print();

    return 0;
}

bool cmp(const Method &a, const Method &b)
{
    return a.score > b.score;
}

double computeGradeByGroup(const std::bitset<N> &group, double res)
{
    for (int i = 0; i < N; ++i)
    {
        if (group[i])
        {
            res += rawInfo[i].first;
        }
    }
    return res;
}

int computeScoreByGroup(const std::bitset<N> &group)
{
    std::function<int(int)> cntScore = [&](int i)
    {
        auto j = i, res = 0;
        while (++j < N && !group[j]);

        if (j < N)
        {
            res += scores[i][j] + scores[j][i] + cntScore(j);
        }

        while (++j < N)
        {
            if (group[j])
            {
                res += scores[i][j] + scores[j][i];
            }
        }

        return res;
    };

    int i = -1;
    while (++i < N && !group[i]);

    return cntScore(i);
}
