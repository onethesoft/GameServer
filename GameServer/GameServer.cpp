// GameServer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>

#include <thread>
#include <atomic>
#include <Mutex>

vector<int32> v;

// mutual Exclusive ( 상호배타적 )
mutex m;

// RAII (Resource Acquisition Is Initialization )
template<typename T>
class LockGuard
{
public:
    LockGuard(T& m)
    {
        _mutex = &m;
        _mutex->lock();
    }
    ~LockGuard()
    {
        _mutex->unlock();
    }
private:
    T* _mutex;
};


void Push()
{
    for (int32 i = 0; i < 10000; i++)
    {
        LockGuard<std::mutex> lockGuard(m);
        //std::lock_guard<std::mutex> lockGuard(m);
        //std::unique_lock<std::mutex> uniqueLock(m);
        //uniqueLock.lock();
        //m.lock();

        v.push_back(i); 
        
        if (i == 5000)
        {
            //m.unlock();
            break;
        }
        

        //m.unlock();
    }
}



int main()
{
    //v.reserve(20000);

    std::thread t1(Push);
    std::thread t2(Push);

    t1.join();
    t2.join();

    cout << v.size() << endl;
}

