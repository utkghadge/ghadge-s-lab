#include <iostream>
#include <thread>
#include <vector>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<functional>
#include<future>

using namespace std;

int func(int a)
{
	//this_thread::sleep_for(chrono::seconds(2));
	cout << "this is the time taking function" << endl;
	return a * a;
}

class Threadpool {

private:
	int m_threads;
	vector<thread> threads;
	queue <function<void()>> tasks;
	mutex mtx;
	condition_variable cv;
	bool stop;

public:

	explicit Threadpool(int numThreads) : m_threads(numThreads), stop(false) {

		for (int i = 0; i < m_threads; i++)
		{
			threads.emplace_back([this] {
				function<void()> task;
				while (1) {
					unique_lock<mutex> lock(mtx);
					cv.wait(lock, [this] {
						return !tasks.empty() || stop;
						});

					if (stop) {
						return;
					}

					task = move(tasks.front());
					tasks.pop();
					cout << "size of queue :" << tasks.size() << endl;

					lock.unlock();
					task();

				}

				});
		}

	}

	~Threadpool()
	{
		unique_lock<mutex> lock(mtx);
		stop = true;
		lock.unlock();
		cv.notify_all();

		for (auto& th : threads) {
			th.join();
		}

	}

	template<class F,class... Args> //variadic templates
	auto ExecuteTask(F&& f,Args&&... args) -> future<decltype(f(args...))> {

		using return_type = decltype(f(args...));

		//auto task = make_shared<packaged_task<return_type()>>(bind(forward<F>(f), forward<Args>(args...));
		auto task = make_shared<packaged_task<return_type()>>(bind(forward<F>(f), forward<Args>(args)...));


		future<return_type> res = task->get_future();

		unique_lock<mutex> lock(mtx);

		tasks.emplace([task]() -> void {
			(*task)();
		});

		lock.unlock();
		cv.notify_one();

		return res;

	}

};

int main() {
	Threadpool pool(16);

	future<int> res = pool.ExecuteTask(func,2);
	cout << "result is : " << res.get() << endl; 

	while (true) {


		//ool.ExecuteTask(func);

		/*thread t1(func);
		t1.detach();*/

	}

	cout << "thread pool program started" << endl;

	return 0;
}