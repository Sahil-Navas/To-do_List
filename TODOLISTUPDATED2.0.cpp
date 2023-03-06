#include <iostream>
#include <vector>
struct list 
{
    int priority;
    std::string task;
};    

void taskAdder(int choco)
{
    choco += 1;
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
    int todoSize, priorityNo, inputNo; 
    std::string taskTodo;

    std::cout << "Type the number of tasks: ";
    scanf("%d", &todoSize);

    for(int j = 1; j <= todoSize; j++)
    {
        ls.push_back(list());
    }

    for(int i = 0; i < todoSize; i++)
    {
        std::cin >> priorityNo;
        std::cin.ignore(256,'\n');
        getline(std::cin, taskTodo);
        ls[i].priority = priorityNo;
        ls[i].task = taskTodo;
    }

    printf("1) Add a task\n");
    printf("2) Read the list\n");
    printf("3) Remove a task\n");
    printf("4) Sort tasks alphabetically\n");
    printf("5) Reset list\n");
    printf("6) Exit program\n");

    scanf("%d", &inputNo);

    switch(inputNo)
    {
        case 1:

            break;
        case 2:
            listReader(todoSize, ls);
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
        
    }

 }