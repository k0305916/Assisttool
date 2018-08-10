/*
在一棵长为n的树上，有很多小蛇在爬。
每次，小蛇若存在于距离地面x的位置，下一步则会爬到x+1的位置。
其中有k对关键点，形如ai,bi，表示一条小蛇若当时在ai，则下一步到达的点为bi。
总共有Q条小蛇，每条小蛇初始时在地面。
第i条小蛇初始时每天会行动si步，每次后退都会令小蛇更加渴望胜利，若当天该小蛇后退过，则接下来每天小蛇的速度将会乘以2，即每天行动当前步数*2步。若有2天后退过，则小蛇的速度将会是si*4，若有3天后退过，则小蛇的速度将会是si*8，依此类推。
求每条小蛇到达树顶时所花了多少天。

Input
第一行两个数n,k(1<=n<=10^9,1<=k<=200000)。
接下来k行，每行两个数ai,bi表示每一对关键点。(1<=ai,bi<=n)
接下来一行一个数Q，表示有Q条小蛇。(1<=Q<=200000)
接下来Q行，每行一个数si。(1<=si<=10^9)
保证小蛇可以到达树顶。
Output
Q行表示答案。
Input示例
7 3
1 3
4 2
2 5
2
1
2
Output示例
6
3
*/

#include <iostream>
#include <list>
#include <algorithm>
struct Key{
    int cur = 0;
    int next = 0;
};

class KeysOper
{
  public:
    void InportKeys(int cur,int next)
    {
        Key key;
        key.cur = cur;
        key.next = next;
        m_keys.push_back(key);
    }

    bool IsKey(int cur)
    {
        auto iter = std::find_if(m_keys.begin(),m_keys.end(),[&cur](Key key){
            if(key.cur == cur) return true;return false;
        });

        if(iter == m_keys.end())
            return false;
        return true;
    }

    int Next(int cur)
    {
        auto iter = std::find_if(m_keys.begin(),m_keys.end(),[&cur](Key key){
            if(key.cur == cur) return true;return false;
        });

        return iter->next;
    }

  private:
    std::list<Key> m_keys;
};

class Snake
{
  public:
    Snake(int speed,int end,int start=0):
        m_speed(speed),m_end(end)
    {
        
    }

    bool IsEnd(int& state,int& days)
    {
        if(state >= m_end)
            return true;

        days++;
        return false;
    }

    int GetSpeed(){return m_speed;}
  private:
    bool m_Isback;
    int m_cur;
    int m_speed;
    int m_end;
};

int main()
{
    int end,k;
    std::cin >> end >> k;
    KeysOper keysoper;
    while(k-->0)
    {
        int cur,next;
        std::cin >> cur >> next;
        keysoper.InportKeys(cur,next);
    }

    int q;
    std::cin >> q;
    std::list<Snake> Snakes;
    while(q-->0)
    {
        int speed;
        std::cin >> speed;
        Snake snake(speed,end);
        Snakes.push_back(snake);
    }

    for(auto snake : Snakes)
    {
        int days =0,state=0;
        while(snake.IsEnd(state,days) != true)
        {
            auto speed = snake.GetSpeed();
            while(speed-- > 0)
            {
                auto next = 0;
                if(keysoper.IsKey(state))
                {
                    next = keysoper.Next(state);
                }
                else
                {
                    next += state+1;
                }
                state = next;
            }
        }

        std::cout << days << std::endl;
    }

    std::cin >> end;
}