#pragma once

#include <cstdlib>
#include <cstdio>
#include <mutex>
#include <condition_variable>

class semaphore
{
	std::mutex m;
	std::condition_variable cv;
	int counter;

public:
	semaphore();
	~semaphore();

	void P();
	void V();
};