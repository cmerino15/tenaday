#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

int MainMenu();
void Show();
void Add();
void Practice(std::string &tsk);

int main()
{
  int app_state = true;

  while (app_state)
  {
    app_state = MainMenu();
  }
}

int MainMenu()
{
  std::cout << "Ten-A-Day\n";
  std::cout << "-------------\n";
  std::cout << "1. Show Tasks\n";
  std::cout << "2. Add Tasks\n";
  std::cout << "3. Exit\n\n";
  std::string dummy = "";
  int choice = 0;
  std::cin >> choice;
  getline(std::cin, dummy);
  if (choice == 1)
  {
    Show();
    return 1;
  }
  else if (choice == 2)
  {
    Add();
    return 1;
  }
  else
  {
    std::cout << "\n.\n.\n.\nExiting\n";
    return 0;
  }
}

void Show()
{
  bool cont = 1;
  int i = 0, choice = 0;
  std::vector<std::string> tasks;
  std::string t = "", dummy = "";
  std::ifstream fin;
  fin.open("tasks.txt");
  std::cout << "0. Exit\n";
  while (getline(fin, t))
  {
    i++;
    std::cout << i << ". " << t << "\n";
    tasks.push_back(t);
  }
  fin.close();
  std::cout << "Choose a task to set a timer for\n";
  std::cin >> choice;
  getline(std::cin, dummy);
  if (0 <= choice <= i)
  {
    Practice(tasks[choice - 1]);
  }
  else
  {
    std::cout << "Error: not an option\n";
  }
}

void Add()
{
  bool cont = 1;
  std::string t = "", dummy = "";
  std::ofstream fout;
  fout.open("tasks.txt", std::ios::app);
  while (cont == 1)
  {
    std::cout << "Enter a task\n";
    getline(std::cin, t);
    fout << t << "\r\n";
    std::cout << "Continue? enter 1 for yes or 0 for no\n";
    std::cin >> cont;
    getline(std::cin, dummy); // ignore trailing whitespace
  }
  fout.close();
}

void Practice(std::string &tsk)
{
  auto timer = std::chrono::minutes(8);
  auto countdown = std::chrono::minutes();

  std::cout << "Starting " << timer.count() + 2 << " minute timer for " << tsk << '\n';

  std::this_thread::sleep_for(timer);
  std::cout << "2 minutes remaining\n";
  std::this_thread::sleep_for(countdown);
  std::cout << "Timer finished\n";
}
