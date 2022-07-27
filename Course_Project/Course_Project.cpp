#include "Course_Project.h"
#include "TaskExecution.h"

int main()
{
	using namespace KHAS;

	setlocale(LC_ALL, "Russian");

	TaskExecution task;
	task.view();
	return 0;
}
