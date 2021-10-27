// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>

#include <thread>
#include <atomic>

// atomic : All-Or_Nothing
atomic<int32> sum = 0;
//int32 sum = 0;


void Add()
{
    for (int32 i = 0; i < 100'0000; i++)
    {
        sum.fetch_add(1);
        //sum++;
    }
}
void Sub()
{
    for (int32 i = 0; i < 100'0000; i++)
    {
        sum.fetch_add(-1);
        //sum--;
    }
}

int main()
{
    Add();
    Sub();

    cout << sum << endl;

    std::thread t1(Add);
    std::thread t2(Sub);

    t1.join();
    t2.join();

    cout << sum << endl;
}

