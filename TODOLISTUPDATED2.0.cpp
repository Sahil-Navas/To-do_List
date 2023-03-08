#include <iostream>
#include <vector>

struct list 
{
    int priority;
    std::string task;
};    

void taskRemover(std::vector<list> &ls, int elementNo)
{
    for(int i = 0; i < ls.size(); i++)
    {
        if(ls[i].priority == elementNo)
        {
            ls.erase(ls.begin() + elementNo);
        }
    }
}


void taskAdder(std::vector<list> &ls, int priorityNo, std::string taskTodo)
{
    ls.push_back(list());
    printf("\nType in the priority of your task: ");
    std::cin >> priorityNo;
    printf("\nType in the task you need to do: ");
    std::cin.ignore(256,'\n');
    getline(std::cin, taskTodo);
    ls[ls.size() - 1].priority = priorityNo;
    ls[ls.size() - 1].task = taskTodo;
}


void listReader(int todoSize, std::vector<list> ls)
{
    for(int b = 0; b < todoSize; b++)
    {
        std::cout << "Task " << ls[b].priority << ": " << ls[b].task << std::endl;
    } 
}


int main()
{
    std::vector<list> ls;
    int todoSize, priorityNo, inputNo, elementNo; 
    std::string taskTodo;

    while(true)
    {
        printf("1) Add a task\n");
        printf("2) Read the list\n");
        printf("3) Remove a task\n");
        printf("4) Sort tasks alphabetically\n");
        printf("5) Reset/New list\n");
        printf("6) Exit program\n");
        scanf("%d", &inputNo);

        if(inputNo == 1)
        {
            taskAdder(ls, priorityNo, taskTodo);
            std::cout << ls[3].priority << " at " << ls[3].task << std::endl; 
        }else if (inputNo == 2)
        {
            listReader(todoSize, ls);

        }else if (inputNo == 3)
        {
            printf("Please type in the element number of the task to delete: \n");
            scanf("%d", &elementNo);
            taskRemover(ls, elementNo);
            listReader(todoSize, ls);
        }else if (inputNo == 4)
        {
            for(int i = 0; i < ls.size(); i++)
            {
                for(int j = i + 1; j < ls.size(); j++)
                {
                    if(ls[i].task > ls[j].task)
                    {
                        std::swap(ls[i].task, ls[j].task);
                        std::swap(ls[i].priority, ls[j].priority);
                    } 
                }
            }
        }else if (inputNo == 5)
        {
            ls.clear();
            std::cout << "Type the number of tasks: ";
            scanf("%d", &todoSize);

            for(int i = 0; i < todoSize; i++)
            {
                ls.push_back(list());
                printf("\nType in the priority of your task: ");
                std::cin >> priorityNo;
                printf("\nType in the task you need to do: ");
                std::cin.ignore(256,'\n');
                getline(std::cin, taskTodo);
                ls[i].priority = priorityNo;
                ls[i].task = taskTodo;
            }
        }else if (inputNo == 6)
        {
            break;
        }else 
        {
            printf("Please type in a value between 1 - 6\n");
        }
    }


 }
