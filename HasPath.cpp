/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

#include <iostream>
#include <list>
#include <memory>
#include <string>
using namespace std;

char pmatrix[][4] = {{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
int g_stri = 0;
char *findstr = "bcced";
char *findstr1 = "abcb";
int rows = 3, cols = 4;

bool FindFirstChar(char *matrix, int row, int col, char c)
{
    if(matrix[row][col] == c)
        return true;
    return false;
}

bool FindSubstr(char *matrix, int rows, int cols, char *str, int lrow, int lcol)
{
    for (int i = 0; i < 4; i++)
    {
        auto row = lrow;
        auto col = lcol;
        switch(i)
        {
            case 0:
            {
                row = lrow-1;
                if(row < 0)
                    continue;
                if(matrix[row][col] != str[g_stri])
                    continue;
            }
            break;
            case 1:
            {
                col = lcol-1;
                if(row < 0)
                    continue;
                if(matrix[row][col] != str[g_stri])
                    continue;
            }
            break;
            case 2:
            {
                row = lrow+1;
                if(row < 0)
                    continue;
                if(matrix[row][col] != str[g_stri])
                    continue;
            }
            break;
            case 3:
            {
                col = lcol+1;
                if(row < 0)
                    continue;
                if(matrix[row][col] != str[g_stri])
                    continue;
            }                        
            break;
        }

        g_stri++;
        if(FindSubstr(matrix,rows,cols,&str[g_stri],row,col))
            return true;
        else
            g_stri--;
    }
    return false;
}

bool hasPath(char** matrix, int rows, int cols, char *str)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!FindFirstChar(matrix, i, j, findstr[g_stri]))
                continue;

            auto frow = i;
            auto fcol = j;
            g_stri++;

            if (FindSubstr(matrix, rows, cols, &findstr[g_stri], frow, fcol))
                return true;
            else
                g_stri--;
        }
    }

    return false;
}

#pragma region xxx
// shared_ptr<list<list<char>>> InitMatrix()
// {
//     cout << "Input M * N: ";
//     auto M =0;
//     auto N = 0;
//     cin >> M >> N;
//     shared_ptr<list<list<char>>> charlist(new list<list<char>>());
//     for(int i=0;i<M;i++)
//     {
//         list<char> tmp;
//         for(int j=0;j<N;j++)
//         {
//             cout << "Input Detail char:(MaxCount N):";
//             auto value = '0';
//             cin >> value;
//             tmp.push_back(value);
//         }
//         charlist->push_back(tmp);
//     }

//     return charlist;
// }

// bool FindSubString(shared_ptr<list<list<char>>> mylist,string substring)
// {
//     return false;
// }
#pragma endregion

int main()
{
    // auto myList = InitMatrix();
    // string findstr = "bcced";
    // auto resul = FindSubString(myList,findstr);

    auto result = hasPath(pmatrix, rows, cols, findstr);
    getchar();
    return 0;
}