//
// Created by Nanomoa on 23-12-11.
//

#ifndef MARKDOWNEDITOR_TIMER_H
#define MARKDOWNEDITOR_TIMER_H


#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject* parent = nullptr) : QObject(parent)
    {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Timer::onTimeout);
    }

    ~Timer() override
    {
        this->stop();
        free(timer);
    }

    void start(int interval, std::function<void()> _task);

    void stop();

public slots:
    void onTimeout();

private:
    QTimer *timer;
    std::function<void()> task;
};


#endif //MARKDOWNEDITOR_TIMER_H
