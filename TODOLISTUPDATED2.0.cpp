#include <iostream>
#include <vector>
#include <fstream>

struct list 
{
    int priority;
    std::string task;
};    

// Sort the list numerically by priority
void sortAlgoNumba(std::vector<list> &ls)
{
    for(int i = 0; i < ls.size(); i++)
    {
        for(int j = i + 1; j < ls.size(); j++)
        {
            if(ls[i].priority > ls[j].priority)
            {
                std::swap(ls[i].task, ls[j].task);
                std::swap(ls[i].priority, ls[j].priority);
            } 
        }
    }
}
// Sorts the list alphabetically A-Z
void sortAlgoAlpha(std::vector<list> &ls)
{
    for(int i = 0; i < ls.size(); i++)
    {
        for(int j = i + 1; j < ls.size(); j++)
        {
            if(ls[i].task > ls[j].task)
            {
                std::swap(ls[i].task, ls[j].task);
            } 
        }
    }
}
// Sorts the list alphabetically Z-A  
void sortAlgoReverseAlpha(std::vector<list> &ls)
{
    for(int i = 0; i < ls.size(); i++)
    {
        for(int j = i + 1; j < ls.size(); j++)
        {
            if(ls[i].task < ls[j].task)
            {
                std::swap(ls[i].task, ls[j].task);
            } 
        }
    }
}

// Removes task with element number
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

// adds tasks to the to do list
void taskAdder(std::vector<list> &ls, int priorityNo, std::string taskTodo)
{
    ls.push_back(list());
    printf("\nType in the priority of your task: ");
    std::cin >> priorityNo;
    // Just to make sure there is no doubles of priority
    for(int i = 0; i < ls.size(); i++)
    {
        if(priorityNo == ls[i].priority)
        {
            priorityNo = ls[i].priority + 1;
        }
    }
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
// While loop here to keep things going even after completing
    while(true)
    {
        // All the options as displayed here
        printf("1) Add a task\n");
        printf("2) Read the list\n");
        printf("3) Remove a task\n");
        printf("4) Sort tasks alphabetically A-Z\n");
        printf("5) Reset/New list\n");
        printf("6) Write list to a text file\n");
        printf("7) Sort tasks alphabetically Z-A\n");
        printf("8) Exit program\n");

        scanf("%d", &inputNo);
        // This was originally a switch case but because of the loop changed it to if elses
        if(inputNo == 1)
        {
            taskAdder(ls, priorityNo, taskTodo);
            std::cout << ls[3].priority << " at " << ls[3].task << std::endl; 
        }else if (inputNo == 2)
        {
            sortAlgoNumba(ls);
            listReader(todoSize, ls);

        }else if (inputNo == 3)
        {
            printf("Please type in the element number of the task to delete: \n");
            scanf("%d", &elementNo);
            taskRemover(ls, elementNo);
            listReader(todoSize, ls);
        }else if (inputNo == 4)
        {
            sortAlgoAlpha(ls);

        }else if (inputNo == 5)
        {
            ls.clear();
            std::cout << "Type the number of tasks: ";
            scanf("%d", &todoSize);

            for(int i = 0; i < todoSize; i++)
            {
                taskAdder(ls, priorityNo, taskTodo);
            }

            sortAlgoNumba(ls);
        }else if (inputNo == 6)
        {
            // Opens to a file named todoList.txt and writes the list towards it
            std::ofstream listFile;
            listFile.open("todoList.txt");
            for(int m = 0; m < ls.size(); m++)
            {
                listFile << ls[m].priority << ") " << ls[m].task << std::endl;
            }
        } else if (inputNo == 7)
        {
            sortAlgoReverseAlpha(ls);
        } else if (inputNo == 8)
        {
            break;
        }
        else 
        {
            printf("Please type in a value between 1 - 6\n");
        }
    }


 }
