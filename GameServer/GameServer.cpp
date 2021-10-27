// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>

#include <thread>

void HelloThread()
{
    cout << "Hello Ah" << endl;
}
void HelloThread_2(int32 num)
{
    cout << num << endl;
}
int main()
{
    vector<std::thread> ThreadList;
    for (int i = 0; i < 12; i++)
    {
        ThreadList.push_back(std::thread(HelloThread_2, i));
    }
    for (int i = 0; i < 12; i++)
    {
        if (ThreadList[i].joinable())
            ThreadList[i].join();
    }
    /*

    std::thread t;

    auto id1 = t.get_id(); // 쓰레드가 할당되지 않았으므로 0 을 return

    t = std::thread(HelloThread);
    std::thread(HelloThread_2, 10);
    
    int32 count = t.hardware_concurrency();// CPU 코어 개수의 정보를 추출

    auto id = t.get_id();  // 쓰레드 ID 를 return
    //t.detach(); // std::thread 객체에서 실제 쓰레드를 분리 ( 리눅스의 Demon Process )

    if (t.joinable()) // thread 변수 t 에 실제 스레드가 할당되어 있는지를 Check 
        t.join();  // Main Thread 가 t Thread 가 끝날때까지 대기한다.
        */

    cout << "Hello main" << endl;

     
    
}

