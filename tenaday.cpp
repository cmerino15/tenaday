#include <iostream>
#include <fstream>

int MainMenu();
void Show();
void Add();
void Practice(int & choice);

int main()
{   
    int app_state = true;
    
    while(app_state){
       app_state = MainMenu();
    }

}

int MainMenu(){
  std::cout << "Ten-A-Day\n";
  std::cout << "-------------\n";
  std::cout << "1. Show Tasks\n";
  std::cout << "2. Add Tasks\n";
  // option to delete tasks from tasks.txt
  std::cout << "3. Exit\n\n";
  std::string dummy="";
  int choice = 0;
  std::cin >> choice;
  getline(std::cin, dummy);
  if(choice == 1){
     Show();
     return 1;
  }else if( choice == 2){
     Add();
     return 1;
  }
  else{
     std::cout << "\n.\n.\n.\nExiting\n";
     return 0;
  }
}

void Show(){
  bool cont = 1;
  int i = 0, choice=0;
  std::string t="", dummy="";
  std::ifstream fin;
  fin.open("tasks.txt");
  std::cout << "0. Exit\n";
  while(getline(fin, t)){
    i++;
    std::cout << i << ". " << t << "\n";
  }
  fin.close();
  std::cout << "Choose a task to set a timer for\n";
  std::cin >> choice;
  getline(std::cin, dummy);
  if( 0 <= choice <= i ){
    Practice(choice);
  }else{
    std::cout << "Error: not an option\n";
  }
}


void Add(){
  bool cont = 1;
  std::string t="", dummy="";
  std::ofstream fout;
  fout.open("tasks.txt", std::ios::app);
  while(cont == 1){
    std::cout << "Enter a task\n";
    getline(std::cin, t);
    fout << t << "\r\n";
    std::cout << "Continue? enter 1 for yes or 0 for no\n";
    std::cin >> cont;
    getline(std::cin, dummy);  // ignore trailing whitespace
  }
  fout.close();

}

void Practice(int & choice){
  // rewrite using vector so that I can easily display choices here
  std::cout << "Setting a 10 minute timer for " << choice << "\n";
  // set timer
  // wait 
  // ask user if task was completed
  // check off of task list (don't erase)

}