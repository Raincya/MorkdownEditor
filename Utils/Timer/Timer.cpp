//
// Created by Nanomoa on 23-12-11.
//

#include "Timer.h"


void Timer::onTimeout()
{
    if(task)
    {
        task();
    }
}

void Timer::start(int interval, std::function<void()> _task)
{
    timer->setInterval(interval);
    timer->start();
    this->task = std::move(_task);
}

void Timer::stop()
{
    timer->stop();
}