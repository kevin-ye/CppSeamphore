#include "semaphore.hpp"

semaphore::semaphore()
: counter(0)
{}

semaphore::~semaphore()
{}

void semaphore::P()
{
	// wait for counter to be greater than 0
	std::unique_lock<std::mutex> holdlock(m);
	cv.wait(holdlock, [this](){return counter > 0;});

	// subtract by 1
	counter--;

	// release the lock to let other P() get in
	holdlock.unlock();
	// one at a time
	cv.notify_one();
}

void semaphore::V()
{
	// increment by 1
	{
		std::lock_guard<std::mutex> guard_lock(m);
		counter++;
	}

	// notify the change of counter to a P(), one at a time
	cv.notify_one();
}
