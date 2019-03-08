#include <set>
#include <queue>
#include <tuple>
#include <array>
#include <vector>
#include <bitset>
#include <string>
#include <numeric>
#include <utility>
#include <fstream>
#include <iterator>
#include <iostream>
#include <functional>


constexpr auto N = 18, K = 3;
constexpr double ALPHA = 1.5;
const std::set<int> filter {0, 2, 9, 14, 17};


struct Method
{
    int score;
    std::vector<int> method;
};


int computeGradeByGroup(const std::bitset<N>&);
int computeScoreByGroup(const std::bitset<N>&); // for favorability


std::vector<std::pair<int, std::string>> rawInfo;
std::array<std::array<int, N>, N>        scores;
std::vector<std::bitset<N>>              posG;
std::vector<int>                         scoreG;
std::vector<std::vector<int>>            noInterference;


bool cmp(const Method&, const Method&);
std::priority_queue<Method, std::vector<Method>, decltype(cmp)*> Result(cmp);


void genRawInfoAndScores()
{
    // read prefers
    std::ifstream score_in("score.txt");

    for (int _i = 0, i = -1; _i < N + filter.size(); ++_i)
    {
        int score1, score2, score3; std::string No;
        score_in >> No >> score1 >> score2 >> score3;

        if (filter.count(_i)) continue; else ++i;

        rawInfo.emplace_back(std::make_pair(score1 + score2 + score3, No));

        std::ifstream fin("prefer_" + No + ".txt");
        for (int _j = 0, j = -1; _j < N + filter.size(); ++_j)
        {
            int score; std::string No;
            fin >> No >> score;

            if (filter.count(_j)) continue; else ++j;

            scores[i][j] = score;
        }
    }

    if (N != rawInfo.size())
    {
        std::cout << "The number of students entered should be " << N << " or edit N in code" << std::endl;
        exit(0);
    }
}


void computePosG()
{
    std::vector<int> grades;
    for (auto info : rawInfo) grades.push_back(info.first);

    float average = std::accumulate(grades.begin(), grades.end(), 0) / (float)N * K;

    auto legal = [=](const int &score) { return (average - ALPHA <= score) && (score <= average + ALPHA); };

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


int computeScore(const std::vector<int> &method)
{
    auto sum = 0;
    for (auto i: method) sum += scoreG[i];
    return sum;
}


int traverse(int m, int count, std::bitset<N> posCurrent, std::vector<int> method)
{
    if (posCurrent.all())
    {
        auto mtd = Method({ computeScore(method), method });
        Result.push(mtd);
        {
            std::cout << mtd.score << " ";
            for (auto i : mtd.method)
            {
                std::cout << computeGradeByGroup(posG[i]) << " ";
                for (int j = 0; j < N; ++j)
                {
                    if (posG[i][j])
                    {
                        std::cout << rawInfo[j].second << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
        return 0;
    }
    else if (count == 0) return 1;

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
    std::cout << "\n\n## RESULT ##" << std::endl;
    for (int _ = 0; _ < 10; ++_)
    {
        auto top = Result.top();
        Result.pop();
        std::cout << top.score << " ";
        for (auto i : top.method)
        {
            std::cout << computeGradeByGroup(posG[i]) << " ";
            for (int j = 0; j < N; ++j)
            {
                if (posG[i][j])
                {
                    std::cout << rawInfo[j].second << " ";
                }
            }
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
    return a.score < b.score;
}


int computeGradeByGroup(const std::bitset<N> &group)
{
    int res = 0, i = 0;
    for (; i < N; ++i) if (group[i]) res += rawInfo[i].first;
    return res;
}


int computeScoreByGroup(const std::bitset<N> &group)
{
    std::function<int(int, std::bitset<N>)> cntScore = [&](int i, std::bitset<N> pos)
    {
        auto j = i, res = 0;
        while (++j < N)
        {
            if (pos[j]) 
            {
                res += scores[i][j] + scores[j][i] + cntScore(j, pos);
                break;
            }
        }

        while (++j < N) if (pos[j]) res += scores[i][j] + scores[j][i];

        return res;
    };

    int res = 0, i = -1;
    while (++i < N) if (group[i]) break;

    return cntScore(i, group);
}
