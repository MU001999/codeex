#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <numeric>
#include <utility>
#include <iterator>
#include <iostream>
#include <functional>

#define N     24
#define K     3
#define ALPHA 5


struct Method
{
    int score;
    std::vector<int> method;
};


int computeGradeByGroup(const std::bitset<N>&);
int computeScoreByGroup(const std::bitset<N>&); // for favorability


bool cmp(const Method&, const Method&);
std::priority_queue<Method, std::vector<Method>, decltype(cmp)*> Result(cmp);

std::vector<std::pair<int, std::string>> rawInfo = {
    {64, "0"},
    {60, "1"},
    {41, "2"},
    {94, "3"},
    {33, "4"},
    {73, "5"},
    {11, "6"},
    {57, "7"},
    {15, "8"},
    {32, "9"},
    {3 , "10"},
    {68, "11"},
    {63, "12"},
    {23, "13"},
    {67, "14"},
    {30, "15"},
    {58, "16"},
    {4 , "17"},
    {77, "18"},
    {31, "19"},
    {92, "20"},
    {98, "21"},
    {28, "22"},
    {37, "23"}
};

std::vector<std::vector<int>> scores(N, std::vector<int>(N, 0));

std::vector<int> scoreG;

std::vector<std::bitset<N>> posG;

std::vector<std::vector<int>> noInterference;


void genRawInfoAndScores()
{
    void checkN();

    // read file... 

    scores[0][0] = 2;
    scores[0][1] = 5;
    scores[0][2] = 3;
    scores[0][3] = 3;
    scores[0][4] = 2;
    scores[0][5] = 1;
    scores[0][6] = 1;
    scores[0][7] = 3;
    scores[0][8] = 3;
    scores[0][9] = 5;
    scores[0][10] = 2;
    scores[0][11] = 5;
    scores[0][12] = 5;
    scores[0][13] = 5;
    scores[0][14] = 1;
    scores[0][15] = 4;
    scores[0][16] = 5;
    scores[0][17] = 5;
    scores[0][18] = 1;
    scores[0][19] = 3;
    scores[0][20] = 2;
    scores[0][21] = 1;
    scores[0][22] = 2;
    scores[0][23] = 1;
    scores[1][0] = 1;
    scores[1][1] = 3;
    scores[1][2] = 1;
    scores[1][3] = 1;
    scores[1][4] = 4;
    scores[1][5] = 2;
    scores[1][6] = 4;
    scores[1][7] = 4;
    scores[1][8] = 1;
    scores[1][9] = 3;
    scores[1][10] = 5;
    scores[1][11] = 3;
    scores[1][12] = 2;
    scores[1][13] = 3;
    scores[1][14] = 3;
    scores[1][15] = 2;
    scores[1][16] = 4;
    scores[1][17] = 1;
    scores[1][18] = 5;
    scores[1][19] = 5;
    scores[1][20] = 1;
    scores[1][21] = 2;
    scores[1][22] = 1;
    scores[1][23] = 1;
    scores[2][0] = 3;
    scores[2][1] = 2;
    scores[2][2] = 3;
    scores[2][3] = 5;
    scores[2][4] = 1;
    scores[2][5] = 2;
    scores[2][6] = 1;
    scores[2][7] = 4;
    scores[2][8] = 5;
    scores[2][9] = 5;
    scores[2][10] = 5;
    scores[2][11] = 2;
    scores[2][12] = 2;
    scores[2][13] = 5;
    scores[2][14] = 4;
    scores[2][15] = 4;
    scores[2][16] = 3;
    scores[2][17] = 5;
    scores[2][18] = 5;
    scores[2][19] = 1;
    scores[2][20] = 4;
    scores[2][21] = 1;
    scores[2][22] = 3;
    scores[2][23] = 4;
    scores[3][0] = 2;
    scores[3][1] = 5;
    scores[3][2] = 4;
    scores[3][3] = 1;
    scores[3][4] = 1;
    scores[3][5] = 1;
    scores[3][6] = 2;
    scores[3][7] = 2;
    scores[3][8] = 2;
    scores[3][9] = 3;
    scores[3][10] = 4;
    scores[3][11] = 1;
    scores[3][12] = 2;
    scores[3][13] = 1;
    scores[3][14] = 1;
    scores[3][15] = 3;
    scores[3][16] = 1;
    scores[3][17] = 3;
    scores[3][18] = 4;
    scores[3][19] = 5;
    scores[3][20] = 2;
    scores[3][21] = 1;
    scores[3][22] = 1;
    scores[3][23] = 3;
    scores[4][0] = 2;
    scores[4][1] = 4;
    scores[4][2] = 5;
    scores[4][3] = 1;
    scores[4][4] = 5;
    scores[4][5] = 4;
    scores[4][6] = 5;
    scores[4][7] = 5;
    scores[4][8] = 3;
    scores[4][9] = 3;
    scores[4][10] = 3;
    scores[4][11] = 4;
    scores[4][12] = 4;
    scores[4][13] = 1;
    scores[4][14] = 1;
    scores[4][15] = 1;
    scores[4][16] = 4;
    scores[4][17] = 4;
    scores[4][18] = 4;
    scores[4][19] = 5;
    scores[4][20] = 3;
    scores[4][21] = 3;
    scores[4][22] = 4;
    scores[4][23] = 1;
    scores[5][0] = 5;
    scores[5][1] = 1;
    scores[5][2] = 3;
    scores[5][3] = 2;
    scores[5][4] = 1;
    scores[5][5] = 5;
    scores[5][6] = 3;
    scores[5][7] = 1;
    scores[5][8] = 2;
    scores[5][9] = 5;
    scores[5][10] = 3;
    scores[5][11] = 3;
    scores[5][12] = 2;
    scores[5][13] = 1;
    scores[5][14] = 4;
    scores[5][15] = 2;
    scores[5][16] = 5;
    scores[5][17] = 4;
    scores[5][18] = 1;
    scores[5][19] = 2;
    scores[5][20] = 2;
    scores[5][21] = 2;
    scores[5][22] = 1;
    scores[5][23] = 2;
    scores[6][0] = 5;
    scores[6][1] = 5;
    scores[6][2] = 3;
    scores[6][3] = 4;
    scores[6][4] = 2;
    scores[6][5] = 4;
    scores[6][6] = 2;
    scores[6][7] = 1;
    scores[6][8] = 1;
    scores[6][9] = 4;
    scores[6][10] = 3;
    scores[6][11] = 1;
    scores[6][12] = 3;
    scores[6][13] = 1;
    scores[6][14] = 4;
    scores[6][15] = 1;
    scores[6][16] = 5;
    scores[6][17] = 3;
    scores[6][18] = 4;
    scores[6][19] = 5;
    scores[6][20] = 2;
    scores[6][21] = 3;
    scores[6][22] = 3;
    scores[6][23] = 1;
    scores[7][0] = 4;
    scores[7][1] = 1;
    scores[7][2] = 4;
    scores[7][3] = 2;
    scores[7][4] = 2;
    scores[7][5] = 4;
    scores[7][6] = 4;
    scores[7][7] = 2;
    scores[7][8] = 1;
    scores[7][9] = 1;
    scores[7][10] = 1;
    scores[7][11] = 4;
    scores[7][12] = 4;
    scores[7][13] = 5;
    scores[7][14] = 2;
    scores[7][15] = 4;
    scores[7][16] = 3;
    scores[7][17] = 1;
    scores[7][18] = 5;
    scores[7][19] = 4;
    scores[7][20] = 2;
    scores[7][21] = 4;
    scores[7][22] = 5;
    scores[7][23] = 5;
    scores[8][0] = 3;
    scores[8][1] = 2;
    scores[8][2] = 4;
    scores[8][3] = 2;
    scores[8][4] = 2;
    scores[8][5] = 4;
    scores[8][6] = 4;
    scores[8][7] = 3;
    scores[8][8] = 1;
    scores[8][9] = 5;
    scores[8][10] = 4;
    scores[8][11] = 3;
    scores[8][12] = 4;
    scores[8][13] = 3;
    scores[8][14] = 5;
    scores[8][15] = 5;
    scores[8][16] = 5;
    scores[8][17] = 4;
    scores[8][18] = 1;
    scores[8][19] = 3;
    scores[8][20] = 2;
    scores[8][21] = 1;
    scores[8][22] = 4;
    scores[8][23] = 1;
    scores[9][0] = 1;
    scores[9][1] = 4;
    scores[9][2] = 4;
    scores[9][3] = 1;
    scores[9][4] = 4;
    scores[9][5] = 5;
    scores[9][6] = 4;
    scores[9][7] = 5;
    scores[9][8] = 5;
    scores[9][9] = 3;
    scores[9][10] = 3;
    scores[9][11] = 2;
    scores[9][12] = 5;
    scores[9][13] = 2;
    scores[9][14] = 1;
    scores[9][15] = 4;
    scores[9][16] = 2;
    scores[9][17] = 1;
    scores[9][18] = 5;
    scores[9][19] = 1;
    scores[9][20] = 2;
    scores[9][21] = 1;
    scores[9][22] = 1;
    scores[9][23] = 5;
    scores[10][0] = 3;
    scores[10][1] = 2;
    scores[10][2] = 4;
    scores[10][3] = 4;
    scores[10][4] = 5;
    scores[10][5] = 5;
    scores[10][6] = 1;
    scores[10][7] = 1;
    scores[10][8] = 4;
    scores[10][9] = 4;
    scores[10][10] = 2;
    scores[10][11] = 2;
    scores[10][12] = 5;
    scores[10][13] = 3;
    scores[10][14] = 5;
    scores[10][15] = 1;
    scores[10][16] = 4;
    scores[10][17] = 1;
    scores[10][18] = 3;
    scores[10][19] = 1;
    scores[10][20] = 1;
    scores[10][21] = 5;
    scores[10][22] = 4;
    scores[10][23] = 3;
    scores[11][0] = 2;
    scores[11][1] = 4;
    scores[11][2] = 4;
    scores[11][3] = 1;
    scores[11][4] = 2;
    scores[11][5] = 2;
    scores[11][6] = 2;
    scores[11][7] = 3;
    scores[11][8] = 3;
    scores[11][9] = 2;
    scores[11][10] = 3;
    scores[11][11] = 5;
    scores[11][12] = 2;
    scores[11][13] = 1;
    scores[11][14] = 2;
    scores[11][15] = 2;
    scores[11][16] = 3;
    scores[11][17] = 3;
    scores[11][18] = 3;
    scores[11][19] = 2;
    scores[11][20] = 5;
    scores[11][21] = 5;
    scores[11][22] = 3;
    scores[11][23] = 1;
    scores[12][0] = 2;
    scores[12][1] = 4;
    scores[12][2] = 1;
    scores[12][3] = 1;
    scores[12][4] = 3;
    scores[12][5] = 2;
    scores[12][6] = 2;
    scores[12][7] = 4;
    scores[12][8] = 3;
    scores[12][9] = 2;
    scores[12][10] = 5;
    scores[12][11] = 1;
    scores[12][12] = 2;
    scores[12][13] = 2;
    scores[12][14] = 2;
    scores[12][15] = 2;
    scores[12][16] = 4;
    scores[12][17] = 3;
    scores[12][18] = 3;
    scores[12][19] = 5;
    scores[12][20] = 5;
    scores[12][21] = 5;
    scores[12][22] = 1;
    scores[12][23] = 1;
    scores[13][0] = 4;
    scores[13][1] = 3;
    scores[13][2] = 3;
    scores[13][3] = 4;
    scores[13][4] = 1;
    scores[13][5] = 4;
    scores[13][6] = 4;
    scores[13][7] = 3;
    scores[13][8] = 2;
    scores[13][9] = 2;
    scores[13][10] = 3;
    scores[13][11] = 2;
    scores[13][12] = 4;
    scores[13][13] = 4;
    scores[13][14] = 4;
    scores[13][15] = 1;
    scores[13][16] = 4;
    scores[13][17] = 4;
    scores[13][18] = 2;
    scores[13][19] = 4;
    scores[13][20] = 5;
    scores[13][21] = 5;
    scores[13][22] = 2;
    scores[13][23] = 3;
    scores[14][0] = 2;
    scores[14][1] = 1;
    scores[14][2] = 1;
    scores[14][3] = 4;
    scores[14][4] = 5;
    scores[14][5] = 2;
    scores[14][6] = 4;
    scores[14][7] = 5;
    scores[14][8] = 1;
    scores[14][9] = 2;
    scores[14][10] = 3;
    scores[14][11] = 3;
    scores[14][12] = 4;
    scores[14][13] = 2;
    scores[14][14] = 5;
    scores[14][15] = 2;
    scores[14][16] = 3;
    scores[14][17] = 3;
    scores[14][18] = 3;
    scores[14][19] = 5;
    scores[14][20] = 5;
    scores[14][21] = 4;
    scores[14][22] = 4;
    scores[14][23] = 3;
    scores[15][0] = 1;
    scores[15][1] = 5;
    scores[15][2] = 5;
    scores[15][3] = 4;
    scores[15][4] = 2;
    scores[15][5] = 5;
    scores[15][6] = 2;
    scores[15][7] = 2;
    scores[15][8] = 1;
    scores[15][9] = 2;
    scores[15][10] = 1;
    scores[15][11] = 2;
    scores[15][12] = 2;
    scores[15][13] = 3;
    scores[15][14] = 1;
    scores[15][15] = 1;
    scores[15][16] = 3;
    scores[15][17] = 1;
    scores[15][18] = 3;
    scores[15][19] = 5;
    scores[15][20] = 3;
    scores[15][21] = 4;
    scores[15][22] = 3;
    scores[15][23] = 1;
    scores[16][0] = 3;
    scores[16][1] = 5;
    scores[16][2] = 3;
    scores[16][3] = 5;
    scores[16][4] = 1;
    scores[16][5] = 5;
    scores[16][6] = 1;
    scores[16][7] = 5;
    scores[16][8] = 4;
    scores[16][9] = 5;
    scores[16][10] = 5;
    scores[16][11] = 3;
    scores[16][12] = 4;
    scores[16][13] = 3;
    scores[16][14] = 4;
    scores[16][15] = 1;
    scores[16][16] = 4;
    scores[16][17] = 1;
    scores[16][18] = 1;
    scores[16][19] = 3;
    scores[16][20] = 5;
    scores[16][21] = 2;
    scores[16][22] = 1;
    scores[16][23] = 1;
    scores[17][0] = 3;
    scores[17][1] = 1;
    scores[17][2] = 2;
    scores[17][3] = 5;
    scores[17][4] = 4;
    scores[17][5] = 3;
    scores[17][6] = 2;
    scores[17][7] = 1;
    scores[17][8] = 1;
    scores[17][9] = 2;
    scores[17][10] = 3;
    scores[17][11] = 1;
    scores[17][12] = 1;
    scores[17][13] = 3;
    scores[17][14] = 2;
    scores[17][15] = 5;
    scores[17][16] = 3;
    scores[17][17] = 1;
    scores[17][18] = 1;
    scores[17][19] = 4;
    scores[17][20] = 2;
    scores[17][21] = 1;
    scores[17][22] = 3;
    scores[17][23] = 2;
    scores[18][0] = 5;
    scores[18][1] = 3;
    scores[18][2] = 1;
    scores[18][3] = 5;
    scores[18][4] = 2;
    scores[18][5] = 2;
    scores[18][6] = 1;
    scores[18][7] = 4;
    scores[18][8] = 2;
    scores[18][9] = 1;
    scores[18][10] = 2;
    scores[18][11] = 4;
    scores[18][12] = 3;
    scores[18][13] = 4;
    scores[18][14] = 3;
    scores[18][15] = 1;
    scores[18][16] = 4;
    scores[18][17] = 3;
    scores[18][18] = 1;
    scores[18][19] = 1;
    scores[18][20] = 4;
    scores[18][21] = 4;
    scores[18][22] = 1;
    scores[18][23] = 1;
    scores[19][0] = 1;
    scores[19][1] = 4;
    scores[19][2] = 5;
    scores[19][3] = 2;
    scores[19][4] = 4;
    scores[19][5] = 2;
    scores[19][6] = 2;
    scores[19][7] = 4;
    scores[19][8] = 1;
    scores[19][9] = 4;
    scores[19][10] = 5;
    scores[19][11] = 4;
    scores[19][12] = 5;
    scores[19][13] = 5;
    scores[19][14] = 2;
    scores[19][15] = 5;
    scores[19][16] = 5;
    scores[19][17] = 5;
    scores[19][18] = 4;
    scores[19][19] = 5;
    scores[19][20] = 5;
    scores[19][21] = 3;
    scores[19][22] = 2;
    scores[19][23] = 1;
    scores[20][0] = 4;
    scores[20][1] = 2;
    scores[20][2] = 3;
    scores[20][3] = 4;
    scores[20][4] = 1;
    scores[20][5] = 2;
    scores[20][6] = 3;
    scores[20][7] = 4;
    scores[20][8] = 5;
    scores[20][9] = 2;
    scores[20][10] = 5;
    scores[20][11] = 5;
    scores[20][12] = 1;
    scores[20][13] = 2;
    scores[20][14] = 4;
    scores[20][15] = 1;
    scores[20][16] = 2;
    scores[20][17] = 2;
    scores[20][18] = 2;
    scores[20][19] = 4;
    scores[20][20] = 5;
    scores[20][21] = 1;
    scores[20][22] = 1;
    scores[20][23] = 1;
    scores[21][0] = 5;
    scores[21][1] = 3;
    scores[21][2] = 4;
    scores[21][3] = 2;
    scores[21][4] = 3;
    scores[21][5] = 2;
    scores[21][6] = 1;
    scores[21][7] = 1;
    scores[21][8] = 4;
    scores[21][9] = 3;
    scores[21][10] = 3;
    scores[21][11] = 3;
    scores[21][12] = 3;
    scores[21][13] = 3;
    scores[21][14] = 4;
    scores[21][15] = 2;
    scores[21][16] = 2;
    scores[21][17] = 1;
    scores[21][18] = 3;
    scores[21][19] = 5;
    scores[21][20] = 2;
    scores[21][21] = 2;
    scores[21][22] = 2;
    scores[21][23] = 3;
    scores[22][0] = 3;
    scores[22][1] = 5;
    scores[22][2] = 5;
    scores[22][3] = 4;
    scores[22][4] = 4;
    scores[22][5] = 1;
    scores[22][6] = 3;
    scores[22][7] = 5;
    scores[22][8] = 1;
    scores[22][9] = 1;
    scores[22][10] = 2;
    scores[22][11] = 1;
    scores[22][12] = 3;
    scores[22][13] = 1;
    scores[22][14] = 5;
    scores[22][15] = 2;
    scores[22][16] = 1;
    scores[22][17] = 2;
    scores[22][18] = 2;
    scores[22][19] = 5;
    scores[22][20] = 1;
    scores[22][21] = 1;
    scores[22][22] = 1;
    scores[22][23] = 4;
    scores[23][0] = 1;
    scores[23][1] = 2;
    scores[23][2] = 5;
    scores[23][3] = 2;
    scores[23][4] = 5;
    scores[23][5] = 5;
    scores[23][6] = 4;
    scores[23][7] = 3;
    scores[23][8] = 5;
    scores[23][9] = 5;
    scores[23][10] = 2;
    scores[23][11] = 2;
    scores[23][12] = 3;
    scores[23][13] = 5;
    scores[23][14] = 3;
    scores[23][15] = 3;
    scores[23][16] = 2;
    scores[23][17] = 2;
    scores[23][18] = 3;
    scores[23][19] = 1;
    scores[23][20] = 5;
    scores[23][21] = 4;
    scores[23][22] = 4;
    scores[23][23] = 4;

    checkN();
}


void computePosG()
{
    std::vector<int> grades;
    for (auto info : rawInfo) grades.push_back(info.first);

    int average = std::accumulate(grades.begin(), grades.end(), 0) / N;
    /*
    int a = std::max_element(grades.begin(), grades.end()), b = std::min_element(grades.begin(), grades.end());
    auto alpha = min(b - average, average - a) / 2;
    auto l = average - alpha / 2, r = average + alpha / 2;
    */
    auto legal = [=](const int &score) { return ((average - ALPHA / 2) <= score / 3) && (score / 3 <= (average + ALPHA / 2)); };
    std::function<void(int, int, std::bitset<N>)> add2posG = [&](int i, int k, std::bitset<N> pos) 
    {
        if (k == 0)
        {
            if (legal(computeGradeByGroup(pos)))
            {
                posG.push_back(pos);
                scoreG.push_back(computeScoreByGroup(pos));
            }
            else return;
        }
        else
        {
            while (++i < N)
            {
                pos[i] = true;
                add2posG(i, k - 1, pos);
                pos[i] = false;
            }
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
    return std::accumulate(method.begin(), method.end(), 0, [&](const int &a, const int &b) { return scoreG[a] + scoreG[b]; });
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


void checkN()
{
    if (N != rawInfo.size())
    {
        std::cout << "The number of students entered should be " << N << " or edit N in code" << std::endl;
        exit(0);
    }
}